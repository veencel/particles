/**
 * @file particleset.cpp
 * @ingroup particleset
 * @brief A ParticleSet osztály tagfüggvényeinek definíciói.
 *
 * Ez a fájl tartalmazza a ParticleSet osztály tagfüggvényeinek a definícióit.
 *
 * @author Kátai Vencel
 * @see particleset.h
 */

//#define DEBUG

#include "ParticleSet.h"


/**
 * @brief Frissíti a tárolóban lévõ részecskék sebességét
 * @param dt Az idõ, ami alatt fellépõ erõket számoljuk.
 *
 * Ez a függvény a tárolóban lévõ összes részecske sebességét frissíti az egymásra ható erõk alapján.
 * Részecskénként összegzi a többi részecske és közte ható erõvektorokat, majd hozzáadja a sebességéhez.
 * Üres tároló esetén kivételt dob.
 */
void ParticleSet::refreshParticles(double dt){
    if(empty())
        throw std::underflow_error("ParticleSet: Empty! Nothing to refresh!");

    for(Ring<Particle>::iterator it = particles.begin() ; it != particles.end(); ++it) {
        Vector sum_dv;

        #ifdef DEBUG
        std::cout<<"Particle "<<it->getCharge()<< "V=" << it->getV().x <<","<<it->getV().y<<" with:"<<std::endl;
        #endif

        Ring<Particle>::iterator it2;
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


/**
 * @brief Szimulálja a tárolóban lévõ részecskék mozgását a megadott idõ alatt, megadott idõléptékkel.
 * @param s Az idõ ameddig a szimuláció tart.
 * @param refreshRate Az iteráció lépésköze.
 *
 * Ez a függvény szimulálja a részecskék mozgását.
 * Az elsõ paraméterben megadott ideig, a második paraméterben
 * megadott idõnként lépve újraszámolja az összes részecskének a sebességét
 * az egymásra ható erõk alapján, majd mindet elmozdítja a sebességének eltelt idõ-szeresével.
 * Kiírja a standard outputra a részecskék állapotát minden másodpercben.
 */
void ParticleSet::simulate(double s, double refreshRate){
    int cnt = 1;
    for(double i = 0; i < s ; i+=refreshRate){
        refreshParticles(refreshRate);
        move(refreshRate);
        if((int)i == cnt){
            std::cout<<" Simulation :  "<< cnt++<<"s"<<std::endl;
            int cntparticle=1;
            for(Ring<Particle>::iterator it = particles.begin() ; it != particles.end() ; ++it)
                std::cout<<"Particle "<<cntparticle++<<" Charge="<< it->getCharge() <<" Position:"<< it->getPosition() <<" Velocity="<<it->getV()<<std::endl;
        }
    }
}

/**
 * @brief A tárolóban lévõ részecskéket arrébbmozdítja
 * @param dt Az idõ ami alatti elmozdulást vesszük
 *
 * Ez a függvény a tárolóban lévõ összes részecskének a pozícióját frissíti
 * a megadott idõ alatt megtett úttal.
 * Ha a tároló üres kivételt dob.
 */
void ParticleSet::move(double dt){
    if(empty())
        throw std::underflow_error("ParticleSet: Empty! Nothing to move!");

    for(Ring<Particle>::iterator it = particles.begin() ; it != particles.end() ; ++it) {
        it->move(dt);
    }
}


