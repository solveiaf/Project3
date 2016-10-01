#include <Potentials/newtoniangravity.h>
#include <iostream>

NewtonianGravity::NewtonianGravity(double G) {
    m_G = G;
}

void NewtonianGravity::computeForces(Particle* a, Particle* b) {
    double aMass = a->getMass();
    double bMass = b->getMass();
    vec3 distance = a->getPosition() - b->getPosition();
    double r = distance.length();
    double V = m_G * aMass * bMass / r;
    m_potentialEnergy += V;
    double F = -V / (r*r);

    double dFx = distance[0] * F;
    double dFy = distance[1] * F;
    double dFz = distance[2] * F;

    a->addForce(dFx, dFy, dFz);
    b->addForce(-dFx, -dFy, -dFz);
}

std::string NewtonianGravity::getName() {
    return "Newtonian gravity";
}
