#include <InitialConditions/twobody.h>
#include <vec3.h>
#include <system.h>
#include <cmath>


void TwoBody::setupParticles(System* system) {
    Particle* largeBody = new Particle(vec3(0,0,0), vec3(0,0,0),      1.0);
    Particle* smallBody = new Particle(vec3(1,0,0), vec3(0,2*M_PI,0), 1e-3);
    system->addParticle(largeBody);
    system->addParticle(smallBody);
}

std::string TwoBody::getName() {
    return "Two-body";
}
