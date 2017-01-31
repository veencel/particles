#include "GParticleSet.h"
#include "GParticle.h"

int main(int argc, char* argv[]) {

    GParticleSet p;
    for (double i = 1; i < 3 ; ++i) {
        p.add(new GParticle{50,{i*100.0,200.0} });
    }
    for (double i = 1; i < 3 ; ++i) {
        p.add(new GParticle{50, {i*100.0,400.0} });
    }
    p.start(0.05);


    return 0;

}