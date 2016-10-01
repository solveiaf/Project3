#include <InitialConditions/twobody.h>
#include <vec3.h>
#include <cmath>

TwoBody::TwoBody() {

}

void TwoBody::setupParticles() {
    Particle* largeBody = new Particle(vec3(0,0,0), vec3(0,0,0),      1.0);
    Particle* smallBody = new Particle(vec3(1,0,0), vec3(0,2*M_PI,0), 1e-3);

    m_particles.push_back(largeBody);
    m_particles.push_back(smallBody);
}

std::string TwoBody::getName() {
    return "Two-body";
}
