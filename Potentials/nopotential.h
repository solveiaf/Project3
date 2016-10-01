#pragma once
#include <Potentials/potential.h>
#include <string>

class NoPotential : public Potential {
public:
    NoPotential() {}
    std::string getName();
    void computeForces(Particle*, Particle*);
};
