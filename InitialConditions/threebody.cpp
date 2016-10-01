#include <InitialConditions/threebody.h>
#include <vec3.h>
#include <system.h>
#include <cmath>


void ThreeBody::setupParticles(System* system) {
    Particle* largeBody  = new Particle(vec3(0,0,0), vec3(0,0,0), 1.0);
    Particle* smallBody1 = new Particle(vec3(1,0,0), vec3(0,2*M_PI,0), 1e-3);
    Particle* smallBody2 = new Particle(vec3(0,2,0), vec3(-1.5*M_PI,0,0), 1e-2);
    system->addParticle(largeBody);
    system->addParticle(smallBody1);
    system->addParticle(smallBody2);
}

std::string ThreeBody::getName() {
    return "Three-body";
}
