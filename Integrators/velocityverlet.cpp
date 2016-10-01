#include <Integrators/velocityverlet.h>
#include <Integrators/integrator.h>
#include <system.h>

VelocityVerlet::VelocityVerlet(System* system)
        : Integrator(system) {
}

std::string VelocityVerlet::getName() {
    return "Velocity verlet";
}

void VelocityVerlet::integrateOneStep(std::vector<Particle*> particles) {
    int n = particles.size();
    const double dtHalf = 0.5*m_dt;

    if (m_firstStep == true) {
        m_firstStep = false;
        m_system->computeForces();
    }
    for (int i=0; i<n; i++) {
        Particle* p = particles.at(i);
        p->getVelocity() += p->getForce()    * dtHalf / p->getMass();
        p->getPosition() += p->getVelocity() * m_dt;
    }
    m_system->computeForces();
    for (int i=0; i<n; i++) {
        Particle* p = particles.at(i);
        p->getVelocity() += p->getForce()    * dtHalf / p->getMass();
    }
}
