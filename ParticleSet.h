/**
 * @file particleset.h
 * @brief A ParticleSet osztály deklarációja.
 *
 * Ez a fájl tartalmazza a ParticleSet osztály deklarációját.
 *
 * @author Kátai Vencel
 */

#ifndef PARTICLESET_H
#define PARTICLESET_H

#include <stdexcept>

#include "Particle.h"
#include "Ring.h"

/**
 * @class ParticleSet
 * @defgroup particleset ParticleSet
 *
 * @brief A részecskéket tartalmazó és azok kölcsönhatását modellezõ osztály
 *
 * Ez az osztály tárolja a részecskéket, és megvalósítja
 * az azok közötti kölcsönhatások modellezéséhez szükséges mûveleteket.
 *
 * @see particleset.cpp
 * @see particle.h
 */
class ParticleSet {
    Ring<Particle> particles; /**< A részecskék tárolója */
public:
    /**
     * @brief Részecske hozzáadására való függvény.
     * @param p A hozzáadandó részecskére mutató pointer
     * Ezzel a függvénnyel egy új részecskét lehet a tárolóba rakni.
     * A részecskét a használónak kell dinamikusan lefoglalnia.
     */
    void add(Particle* p){ particles.add(p); }

    /**
     * @brief Megadja, hogy van e részecske a tárolóban.
     * @return true: üres, false: nem üres
     * Ezzel a függvénnyel meg lehet kérdezni, hogy van e részecske eltárolva.
     */
    bool empty(){ return particles.empty(); }

    /**
     * @brief Iterátort ad az elsõ részecskére.
     * @return Az elsõ részecskére mutató iterátor.
     * Ez a függvény egy iterátort ad az elsõ részecskére.
     */
    Ring<Particle>::iterator begin(){ return particles.begin(); }

    /**
     * @brief Iterátort ad a tároló végére
     * @return A tároló végére mutató iterátor
     * Ez a függvény egy iterátort ad a tároló végére.
     */
    Ring<Particle>::iterator end(){ return particles.end(); }

    void refreshParticles(double dt);

    void simulate(double s,double refreshRate = 0.1);

    void move(double dt);

    void start();
};

#endif //CHARGED_PARTICLES_PARTICLESET_H
