#include <particle.h>
#include <vec3.h>

Particle::Particle()
        : Particle(vec3(), vec3(), 0) {
}

Particle::Particle(vec3 position, vec3 velocity, double mass) {
    m_position  = position;
    m_velocity  = velocity;
    m_mass      = mass;
}

void Particle::resetForces() {
    m_forces[0] = 0;
    m_forces[1] = 0;
    m_forces[2] = 0;
}

void Particle::addForce(double dFx, double dFy, double dFz) {
    m_forces[0] += dFx;
    m_forces[1] += dFy;
    m_forces[2] += dFz;
}

void Particle::addPosition(double dx, double dy, double dz) {
    m_position[0] += dx;
    m_position[1] += dy;
    m_position[2] += dz;
}

void Particle::addVelocity(double dVx, double dVy, double dVz) {
    m_velocity[0] += dVx;
    m_velocity[1] += dVy;
    m_velocity[2] += dVz;
}

double Particle::velocitySquared() {
    return m_velocity[0]*m_velocity[0] +
           m_velocity[1]*m_velocity[1] +
           m_velocity[2]*m_velocity[2];
}

