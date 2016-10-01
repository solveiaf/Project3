#include <examples.h>
#include <iostream>
#include <cmath>
#include <system.h>
#include <particle.h>
#include <Integrators/eulercromer.h>
#include <Integrators/velocityverlet.h>
#include <Potentials/newtoniangravity.h>
#include <Potentials/nopotential.h>
#include <InitialConditions/twobody.h>
#include <InitialConditions/threebody.h>

using std::cout;
using std::endl;


void Examples::twoBodyProblem() {
    System* twoBodySystem = new System();
    twoBodySystem->setIntegrator(new VelocityVerlet(twoBodySystem));
    twoBodySystem->setPotential(new NewtonianGravity(4*M_PI*M_PI));
    twoBodySystem->setInitialCondition(new TwoBody());
    twoBodySystem->setFileWriting(true);
    twoBodySystem->removeLinearMomentum();
    twoBodySystem->integrate(50000);
}

void Examples::threeBodyProblem() {
    System* threeBodySystem = new System();
    threeBodySystem->setIntegrator(new EulerCromer(threeBodySystem));
    threeBodySystem->setPotential(new NewtonianGravity(4*M_PI*M_PI));
    threeBodySystem->setInitialCondition(new ThreeBody());
    threeBodySystem->setFileWriting(true);
    threeBodySystem->setDt(1e-5);
    threeBodySystem->removeLinearMomentum();
    threeBodySystem->integrate(5000000);
}
