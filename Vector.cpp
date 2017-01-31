/**
 * @file vector.cpp
 * @ingroup vector
 * @brief A Vector osztály tagfüggvényeinek definíciói.
 *
 * Ez a fájl tartalmazza a Vector osztály tagfüggvényeinek a definícióit.
 *
 * @author Kátai Vencel
 * @see vector.h
 */
#include <cmath>

#include "Vector.h"


/**
 * @brief Vektorok közötti összeadás mûvelet
 * @param rhs A hozzáadandó vektor
 * @return Az összegzett vektor
 *
 * Megvalósítja a vektorok közötti összeadás mûveletet.
 */
Vector Vector::operator+(const Vector &rhs) const {

    return Vector{x+rhs.x, y+rhs.y};
}


/**
 * @brief Vektorok közötti kivonás mûvelet
 * @param rhs A kivonandó vektor
 * @return A különbség vektor
 *
 * Megvalósítja a vektorok közötti kivonás mûveletet.
 */
Vector Vector::operator-(const Vector &rhs) const {
    return Vector{x-rhs.x, y-rhs.y};
}


/**
 * @brief Vektor és skalár közötti szorzás mûvelet
 * @param rhs Egy valós szám amivel szorzódik a vektor
 * @return A létrejövõ szorzat vektor
 *
 * Megvalósítja a vektor skalárral való szorzás mûveletet.
 */
Vector Vector::operator*(const double &rhs) const {
    return Vector{x*rhs, y*rhs};
}


/**
 * @brief Vektor és skalár közötti osztás mûvelet
 * @param rhs Egy valós szám amivel osztódik a vektor
 * @return A létrejövõ hányados vektor
 *
 * Megvalósítja a vektor skalárral való osztás mûveletet.
 */
Vector Vector::operator/(const double & rhs) const {
    return Vector{x/rhs, y/rhs};
}


/**
 * @brief Hozzáad egy másik vektort
 * @param rhs A hozzáadandó vektor
 * @return Az objektum referenciája
 *
 * Hozzáadja a paraméterként kapott vektort.
 * A láncolhatóság miatt a visszatérési értéke
 * az objektum.
 */
Vector &Vector::operator+=(const Vector &rhs) {
    return *this=(*this+rhs);
}


/**
 * @brief Kivon egy másik vektort
 * @param rhs A kivonandó vektor
 * @return Az objektum referenciája
 *
 * Kivonja a paraméterként kapott vektort.
 * A láncolhatóság miatt a visszatérési értéke
 * az objektum.
 */
Vector &Vector::operator-=(const Vector &rhs) {
    return *this=(*this-rhs);
}


/**
 * @brief Megszorozza a vektort egy skalárral
 * @param rhs A szorzó
 * @return Az objektum referenciája
 *
 * Megszorozza a vektor komponenseit a paraméterként kapott skalárral.
 * A láncolhatóság miatt a visszatérési értéke
 * az objektum.
 */
Vector &Vector::operator*=(const double &rhs) {
    return *this=(*this*rhs);
}


/**
 * @brief Leosztja a vektort egy skalárral
 * @param rhs Az osztó
 * @return Az objektum referenciája
 *
 * Leosztja a vektor komponenseit a paraméterként kapott skalárral.
 * A láncolhatóság miatt a visszatérési értéke
 * az objektum.
 */
Vector &Vector::operator/=(const double &rhs) {
    return *this=(*this/rhs);
}


/**
 * @brief Megadja a vektor hosszát
 * @return A vektor hossza
 *
 * Kiszámolja a vektor hosszát.
 */
double Vector::length() const {
    return std::sqrt((x*x)+(y*y));
}


/**
 * @brief Normalizálja a vektort
 * @return A normalizált vektor
 *
 * Leosztja a vektor komponenseit a hosszával.
 */
Vector Vector::normalize() {
    double len = length();
    x/=len;
    y/=len;
    return *this;
}

/**
 * @brief << operátor a Vektorok kiírásához ostream típusú objektumra
 * @param os Az objektum amire kiírja a vektort
 * @param v A kiírandó vektor
 * @return A megadott ostream objektum a láncolhatóság miatt
 *
 * Kiíró operátor ami kiírja ostream típusú obktumra a vektor
 * adattagjait (x:y) formátumban.
 */
std::ostream& operator<<(std::ostream& os,const Vector& v){
    std::cout<<"("<<v.x<<":"<<v.y<<")";
    return os;
}
