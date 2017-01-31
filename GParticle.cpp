//
// Created by Vencel on 2016. 05. 01..
//

#include "GParticle.h"


void GParticle::draw(sf::RenderWindow & window){

    window.draw(shape);
}

double GParticle::distanceFromParticle(const GParticle &p) {
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
double GParticle::forceBetweenParticle(const GParticle &p){
    return (charge*p.charge)/std::pow(distanceFromParticle(p),2);
}


/**
 * @brief Módosítja a részecske helyzetét
 * @param dt Az etelt idõ
 *
 * Ez a függvény módosítja a részecske helyzetét,
 * a paraméterként megadott idõ alatt megtett úttal.
 */
void GParticle::move(double dt) {
    position+=(v*dt);

   if(position.x <= 0 )
        position.x = 0;

    if( position.x >= W_WIDTH)
        position.x = W_WIDTH;

    if(position.y <= 0)
        position.y = 0;

    if (position.y >= W_HEIGHT )
        position.y = W_HEIGHT;

    shape.setPosition(position.toVector2f());
}