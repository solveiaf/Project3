#pragma once
#include <vector>
#include <particle.h>
#include <string>

class InitialCondition {
protected:
    std::vector<Particle*> m_particles;

public:
    InitialCondition();
    virtual void setupParticles() = 0;
    virtual std::string getName();
    std::vector<Particle*> getParticles() { return m_particles; }
};

