/**
 * @file particle.cpp
 * @ingroup particle
 * @brief A Particle osztály tagfüggvényeinek definíciói.
 *
 * Ez a fájl tartalmazza a Particle osztály tagfüggvényeinek
 * a definícióit.
 *
 * @author Kátai Vencel
 * @see particle.h
 */

#include <cstdlib>
#include <cmath>

#include "Particle.h"
#include "Constans.h"



/**
 * @brief Kiszámolja a távolságot egy másik részecskétõl
 * @param p Annak a részecskének a referenciája amitõl számoljuk a távolságot
 * @return A 2 részecske között lévõ távolság
 *
 * Ez a függvény kiszámolja a paraméterben megadott részecske és
 * az objektum által jellemzett részecske között lévõ távolságot,
 * ami a pozícióvektoruk különbségének a hossza.
 */
double Particle::distanceFromParticle(const Particle &p) {
    return (position-p.position).length();
}


/**
 * @brief Kiszámolja egy másik részecske által hatott erõt
 * @param p A másik részecske referenciája
 * @return Az erõ
 *
 * Ez a függvény kiszámolja, hogy mekkora erõvel hat a paraméterben
 * megadott részecske az objektum által jellemzett részecskére.
 */
double Particle::forceBetweenParticle(const Particle &p){
    return (charge*p.charge)/std::pow(distanceFromParticle(p),2);
}


/**
 * @brief Módosítja a részecske helyzetét
 * @param dt Az etelt idõ
 *
 * Ez a függvény módosítja a részecske helyzetét,
 * a paraméterként megadott idõ alatt megtett úttal.
 */
void Particle::move(double dt) {
    position+=(v*dt);
    if(position.x < P_RADIUS ) {
        position.x = P_RADIUS;
    }
    else {
        if(position.x > W_WIDTH-P_RADIUS)
            position.x = W_WIDTH - P_RADIUS;
    }
    if(position.y < P_RADIUS)
        position.y = P_RADIUS;
    else {
        if (position.y > W_HEIGHT - P_RADIUS)
            position.y = W_HEIGHT-P_RADIUS;
    }
}
