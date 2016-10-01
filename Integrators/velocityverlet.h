#pragma once
#include <Integrators/integrator.h>
#include <string>
#include <particle.h>

class VelocityVerlet : public Integrator {
private:
    bool m_firstStep = true;

public:
    VelocityVerlet(class System* system);
    std::string getName();
    void integrateOneStep(std::vector<Particle*> particles);
};
