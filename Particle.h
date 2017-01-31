/**
 * @file particle.h
 * @brief A Particle osztály deklarációja.
 *
 * Ez a fájl tartalmazza a Particle osztály deklarációját.
 *
 * @author Kátai Vencel
 */

#ifndef CHARGED_PARTICLES_PARTICLE_H
#define CHARGED_PARTICLES_PARTICLE_H

#include <iostream>

#include "Vector.h"

/**
 * @class Particle
 * @defgroup particle Particle
 *
 * @brief Egy részecskét ábrázoló osztály.
 *
 * Ez az osztály egy részecskét ábrázol, amit a töltésével, pozíciójával
 * és sebességével jellemez.
 *
 * @see particle.cpp
 */
class Particle {
protected:

    static Vector defPos; /**< Alapértelmezett pozíció */
    static double defCharge; /**< Alapértelmezett töltés */
    static Vector defV; /**< Alapértelmezett sebesség */

public:

    /**
     * @brief A Particle osztály konstruktora
     * @param Charge   A részecske kívánt töltése
     * @param Position A részecske kívánt helyzete
     * @param V        A részecske kívánt sebessége
     *
     * Ez a függvény a Particle osztály konstruktora.
     * Inicializálja a részecske töltését, pozícióját és
     * sebességét, a nem megadott paraméterek helyett az
     * alapértelmezett értékekkel.
     */
    Particle(double Charge=defCharge, Vector Position=defPos, Vector V=defV) : charge(Charge), position(Position), v(V){}


    /**
     * @brief Frissíti a sebességvektort
     * @param dv A sebességvektor változása
     *
     * Ez a függvény hozzáadja a paraméterként kapott
     * vektort a részecske sebességvektorához.
     */
    void refreshV(Vector dv){ v+= dv; }


    /**
     * @brief Lekérdezõ függvény a töltéshez
     * @return A részecske töltése
     * Ezzel a függvénnyel kérdezhetõ le a részecske töltése.
     */
    double getCharge(){ return charge; }


    /**
     * @brief Lekérdezõ függvény a helyzethez
     * @return A részecske helyzete.
     * Ezzel a függvénnyel kérdezhetõ le a részecske helyzete.
     */
    Vector getPosition(){ return position; }


    /**
     * @brief Lekérdezõ függvény a sebességhez
     * @return A részecske sebessége
     * Ezzel a függvénnyel kérdezhetõ le a részecske sebessége.
     */
    Vector getV() { return v; }

    double distanceFromParticle(const Particle&);

    double forceBetweenParticle(const Particle&);

    void move(double dt);
};

#endif //CHARGED_PARTICLES_PARTICLE_H