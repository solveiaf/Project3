#include <Potentials/nopotential.h>

NoPotential::NoPotential() {

}

std::string NoPotential::getName() {
    return "No potential";
}


void NoPotential::computeForces(Particle*, Particle*) {

}
