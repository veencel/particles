/**
 * @file ring.h
 * @brief A Ring osztály deklarációja.
 *
 * Ez a fájl tartalmazza a Ring osztály deklarációját
 * és tagfüggvényeinek definícióit.
 *
 * @author Kátai Vencel
 */
#ifndef CHARGED_PARTICLES_RING_H
#define CHARGED_PARTICLES_RING_H

#include <iterator>


/**
 * @class Ring
 * @defgroup ring Ring
 *
 * @brief Egy sablon sorozattároló osztály
 * @param T Adattípus
 * Ez az osztály egy sablon sorozattároló osztály,
 * ami láncolt listát épít a benne elhelyezett elemekbõl,
 * annyi különbséggel, hogy az utolsó elem az elsõre mutat,
 * így körbejárható a tároló iterátorával.
 *
 */
template<typename T>
class Ring {

    /**< A láncolt lista elemei */
    struct element{
        T* data; /**< Az eltárolt adatra mutató pointer */
        element* next; /**< A következõ elemre mutató pointer */
        element(): data{nullptr}, next{nullptr}{}
    };

    element* first; /**< Az elsõ elemre mutató pointer */
    element* last; /**< Az utolsó elemre mutató pointer, az egyszerûbb beszúráshoz */

public:

    class iterator; /**< A Ring osztály iterátorának elõdeklarációja. */


    /**
     * @brief A Ring osztály paraméter nélküli konstruktora
     *
     * Paraméter nélküli konstruktor a Ring osztályhoz, 0-val inicializálja az adattagokat,
     * ez jelzi, hogy a tároló üres.
     */
    Ring() : first{nullptr}, last{nullptr} {}


    /**
     * @brief A Ring osztály másoló konstruktora
     * @param r Egy másik példány az objektumból.
     * Másoló konstruktor a Ring osztályhoz.
     */
    Ring(const Ring<T> & r) : Ring{} {
        element* iter = r.first;
        if(iter != nullptr){
            do{
                T* cdata = new T;
                *cdata = *(iter->data);
                add(cdata);
                iter = iter->next;
            }while(iter != r.first);
        }
    }


    /**
     * @brief A Ring osztály destruktora
     *
     * Destruktor a Ring osztályhoz,
     * felszabadítja a tárolt elemeket.
     */
    ~Ring(){
        if(!empty()) {
            element* removable = first;
            element* next;
            do{
                delete removable->data;
                next = removable->next;
                delete removable;
                removable = next;

            }while(removable != first );
        }
    }

    /**
     * @brief Hozzáad egy elemet a tárolóhoz
     * @param p A tárolandó elemre mutató pointer
     *
     * A lista végére fûz egy új elemet.
     */
    void add(T* p){
        if( first == nullptr ) {
            first = new element{};
            first->data = p;
            first->next = first;
            last = first;
        }
        else{
            element* new_element = new element{};
            new_element->data=p;
            new_element->next=first;
            last->next=new_element;
            last = new_element;
        }
    }


    /**
     * @brief Megadja, hogy van e elem a tárolóban
     * @return true: üres, false : nem üres
     *
     * Ez a függvény megadja, hogy van-e elem a tárolóban.
     */
    bool empty(){ return first == nullptr && last == nullptr; }


    /**
     * @brief Iterátort ad a lista elejére
     * @return Iterátor ami a lista elejére mutat
     *
     * Ez a függvény egy iterátort ad a lista elejére.
     */
    iterator begin() { return iterator{first,true}; }

    /**
     * @brief Iterátort ad a lista végére.
     * @return Iterátor ami a lista végére mutat
     *
     * Ez a függvény egy iterátort ad a lista végére.
     * Mivel a lista körbejárható, nincs vége,
     * ezért ez is az elsõ elemre mutat.
     */
    iterator end() { return iterator{first}; }


    /**
     * @class Ring::iterator
     * @ingroup ring
     *
     * @brief A Ring osztály iterátora
     *
     * Ez az osztály a Ring osztály iterátorát valósítja meg.
     * Használatától függõen a lista körbejárható vele.
     *
     */
    class iterator : public std::iterator<std::forward_iterator_tag,element*>{
        element* pointer; /**< A mutatott elem pointere */
        bool begin; /**< Ez a változó jelzi, ha az iterátor a lista elejére mutat */
    public:
        iterator() : pointer{nullptr} {}

        iterator(element* p, bool begin = false) : pointer{p}, begin{begin} { }


        /**
         * @brief iterator Preinkremens operátora
         * @return Az iterátor a léptetés után
         *
         * Lépteti az iterátort a következõ elemre
         */
        iterator operator++(){
            if(pointer != nullptr)
                pointer = pointer->next;
            if(begin)
                begin = false;
            return *this;
        }

        /**
         * @brief iterator Postinkremens operátora
         * @return Az iterátor a léptetés elõtt
         *
         * Lépteti az iterátort a következõ elemre
         */
        iterator operator++(int){
            iterator ret= *this;
            ++(*this);
            if(begin)
                begin = false;
            return ret;
        }

        /**
         * @brief iterator dereferáló operátora
         * @return Az iterátor által mutatott adat referenciája
         *
         * Dereferálja az iterátort, ezáltal elérhetõ az általa mutatott adat.
         */
        T& operator*(){
            return *(pointer->data);
        }


        /**
         * @brief iterator tagkiválasztó operátora
         * @return Az iterátor által mutatott adat pointere
         *
         * Ez a tagkiválasztó operátor túltöltése az iterátor
         * által mutatott adat tagjainak eléréséhez.
         */
        T* operator->(){
            return pointer->data;
        }


        /**
         * @brief iteratorok közti logikai egyenlõséget vizsgáló operátor
         * @param rhs A hasonlítandó iterator
         * @return true : ha a 2 iterátor ugyanarra mutat, false : ha nem
         *
         * Összehasonlítja, hogy a 2 iterator ugyan arra az elemre mutat-e.
         */
        bool operator==(const iterator & rhs){ return pointer == rhs.pointer; }

        /**
         * @brief iteratorok közti logikai egyenlõtlenséget vizsgáló operátor
         * @param rhs A hasonlítandó iterator
         * @return true : ha a 2 iterátor nem ugyanarra mutat, false : ha ugyan arra mutatnak
         *
         * Összehasonlítja, hogy a 2 iterator ugyan arra az elemre mutat-e.
         */
        bool operator!=(const iterator & rhs){ return begin ? true : !(*this == rhs); }

    };

};

#endif //CHARGED_PARTICLES_RING_H
