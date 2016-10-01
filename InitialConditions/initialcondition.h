#pragma once
#include <vector>
#include <particle.h>
#include <string>

class InitialCondition {
public:
    InitialCondition() {}
    virtual void setupParticles(class System* system) = 0;
    virtual std::string getName();
};

