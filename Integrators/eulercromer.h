#pragma once
#include <Integrators/integrator.h>
#include <vector>
#include <particle.h>

class EulerCromer : public Integrator {
public:
    EulerCromer(class System* system);
    void integrateOneStep(std::vector<Particle*> particles);
    std::string getName();
};
