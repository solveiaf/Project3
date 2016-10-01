#pragma once
#include <particle.h>
#include <string>
#include <Potentials/potential.h>

class NewtonianGravity : public Potential {
private:
    double m_G = 0;

public:
    NewtonianGravity(double G);
    void computeForces(Particle* a, Particle* b);
    std::string getName();
};
