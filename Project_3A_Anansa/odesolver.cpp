#include "odesolver.h"
#include <cmath>
#include "system.h"

ODESolver::ODESolver(System system) {
    n = Body::getNumber();
    h = Body::getStep();
    a = system.calculateAcceleration();
    x = new double[n];
    y = new double[n];
    VelocityVerlet();
    Euler();
}

void ODESolver::VelocityVerlet(double a) {
    x += h*vx + ((h*h)/2.) * a;
    y += h*vy + ((h*h)/2.) * a;
    vx += h*a;
    vy += h*a;
    return;
}

void ODESolver::Euler() {
    x += vx*h;
    y += vy*h;
    vx -= a*x;
    vy -= a*y;
    return;
}
