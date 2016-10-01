#include <examples.h>
#include <iostream>
#include <cmath>
#include <system.h>
#include <particle.h>
#include <Integrators/eulercromer.h>
#include <Potentials/newtoniangravity.h>

using std::cout;
using std::endl;

void Examples::twoBodyProblem() {
    System* twoBodySystem = new System();
    twoBodySystem->setIntegrator(new EulerCromer(twoBodySystem));
    twoBodySystem->setPotential(new NewtonianGravity(4*M_PI*M_PI));
    twoBodySystem->setFileWriting(true);

    Particle* largeBody = new Particle(vec3(0,0,0), vec3(0,0,0), 1.0);
    Particle* smallBody = new Particle(vec3(1,0,0), vec3(0,2*M_PI,0), 1e-3);

    twoBodySystem->addParticle(largeBody);
    twoBodySystem->addParticle(smallBody);

    twoBodySystem->removeLinearMomentum();
    twoBodySystem->integrate(5000);
}
