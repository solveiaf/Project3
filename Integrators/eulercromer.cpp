#include <Integrators/eulercromer.h>
#include <Integrators/integrator.h>
#include <system.h>

EulerCromer::EulerCromer(System* system)
    : Integrator(system) {
}

void EulerCromer::integrateOneStep(std::vector<Particle*> particles) {
    int n = particles.size();
    m_system->computeForces();
    for (int i=0; i<n; i++) {
        Particle *p = particles.at(i);
        p->getVelocity() += p->getForce()    * m_dt / p->getMass();
        p->getPosition() += p->getVelocity() * m_dt;
    }
}

std::string EulerCromer::getName() {
    return "Euler-Cromer";
}
