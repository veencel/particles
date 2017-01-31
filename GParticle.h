//
// Created by Vencel on 2016. 05. 01..
//

#ifndef CHARGED_PARTICLES_GPARTICLE_H
#define CHARGED_PARTICLES_GPARTICLE_H

#include <SFML/Graphics.hpp>

#include "Vector.h"
#include "Constans.h"

class GParticle {
    double charge; /**< A részecske töltése Coulomb-ban */
    Vector position; /**< A részecske pozícióvektora */
    Vector v; /**< A részecske sebességvektora */
    sf::CircleShape shape;
 public:
    GParticle( double charge = 0, Vector Position = {0, 0}, Vector V = {0, 0} ) : charge{charge}, position{Position} , v{V}, shape{P_RADIUS} {

        shape.setPosition(position.toVector2f());

        if(charge < 0)
            shape.setFillColor(sf::Color::Blue);
        else if(charge == 0)
            shape.setFillColor(sf::Color::White);
        else
            shape.setFillColor(sf::Color::Red);
    }

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

    double distanceFromParticle(const GParticle&);

    double forceBetweenParticle(const GParticle&);

    void move(double dt);
    void draw(sf::RenderWindow& window);
    void bounceFromWall(){ if( (position.x <= 0) || (position.x >= W_WIDTH-P_RADIUS)) v.x*=-1;
                           if((position.y <= 0) || (position.y >= W_HEIGHT-P_RADIUS)) v.y*=-1; }
};


#endif //CHARGED_PARTICLES_GPARTICLE_H
