#include "odesolver.h"
#include <cmath>
#include "system.h"

ODESolver::ODESolver(System system) {
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
