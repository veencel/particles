//
// Created by Vencel on 2016. 05. 01..
//

#ifndef CHARGED_PARTICLES_GPARTICLESET_H
#define CHARGED_PARTICLES_GPARTICLESET_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "GParticle.h"
#include "Ring.h"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class GParticleSet {
    Ring<GParticle> particles;
    sf::RenderWindow window;
 public:

    GParticleSet() : particles{}, window{sf::VideoMode{W_WIDTH, W_HEIGHT},"Particles"} {
    }

    void add(GParticle* p){ particles.add(p); }

    bool empty(){ return particles.empty(); }

    Ring<GParticle>::iterator begin(){ return particles.begin(); }

    Ring<GParticle>::iterator end(){ return particles.end(); }

    void refreshParticles(double dt){
        if(empty())
            throw std::underflow_error("ParticleSet: Empty! Nothing to refresh!");

        for(auto it = particles.begin() ; it != particles.end(); ++it) {
            Vector sum_dv;

#ifdef DEBUG
            std::cout<<"Particle "<<it->getCharge()<< "V=" << it->getV().x <<","<<it->getV().y<<" with:"<<std::endl;
#endif

            Ring<GParticle>::iterator it2;
            for( ++(it2=it) ; it2 != it ; ++it2){

#ifdef DEBUG
                std::cout<<"Particle "<< it2->getCharge()<<" ";
#endif

                Vector direction = (it->getPosition() - it2->getPosition()).normalize();


                double force = it->forceBetweenParticle( *it2 );

#ifdef DEBUG
                std::cout<<"F = "<<force<<" ";
#endif

                sum_dv += direction * force * dt;

#ifdef DEBUG
                std::cout<<"Dv = "<<sum_dv.x <<" "<<sum_dv.y<<std::endl;
#endif
            }
            it->refreshV(sum_dv);

#ifdef DEBUG
            std::cout<<"Particle "<< it->getCharge()<< " new v=("<< it->getV().x<<" , "<<it->getV().y <<") "<<std::endl;
#endif
        }
    }

    void move(double dt){
        if(empty())
            throw std::underflow_error("ParticleSet: Empty! Nothing to move!");

        for(auto & particle : particles) {
            particle.move(dt);
        }
    }

    void drawParticles() {
        if (!empty()) {
            for(auto & particle : particles) {
                particle.draw(window);
            }
        }
    }

    void checkCollisionWithWall() {
        if (!empty()) {
            for(auto & particle : particles) {
                particle.bounceFromWall();
            }
         }
    }

    void start(double step = 0.1) {
        int fps = 0;
        sf::Time time = sf::seconds(1);
        sf::Clock clock;
        drawParticles();
        window.display();
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here...
            // window.draw(...);
            checkCollisionWithWall();
            refreshParticles(step);
            move(step);
            drawParticles();
            // end the current frame
            window.display();
            ++fps;
            if(clock.getElapsedTime() >= time){
                std::cout<<"FPS: "<<fps<<std::endl;
                time += sf::seconds(1);
                fps = 0;
            }
        }

    }
};



#endif //CHARGED_PARTICLES_GPARTICLESET_H
