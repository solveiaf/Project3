#include <InitialConditions/threebody.h>
#include <vec3.h>
#include <cmath>

ThreeBody::ThreeBody() {

}

void ThreeBody::setupParticles() {
    Particle* largeBody  = new Particle(vec3(0,0,0), vec3(0,0,0), 1.0);
    Particle* smallBody1 = new Particle(vec3(1,0,0), vec3(0,2*M_PI,0), 1e-3);
    Particle* smallBody2 = new Particle(vec3(0,2,0), vec3(-1.5*M_PI,0,0), 1e-2);

    m_particles.push_back(largeBody);
    m_particles.push_back(smallBody1);
    m_particles.push_back(smallBody2);
}

std::string ThreeBody::getName() {
    return "Three-body";
}
