#include "odesolver.h"
#include <cmath>

ODESolver::ODESolver(double n, double h, double a) {
    x = new double[n];
    y = new double[n];
    n = n;
    h = h;
    a = a;
    VelocityVerlet();
    Euler();
}

void ODESolver::VelocityVerlet() {
    //Algortihm for calculating velocity verlet
    for (int i = 0; i<n; i++) {
        x[i+1] = x[i] + h*vx + ((h*h)/2.) * a*x[i];
        y[i+1] = y[i] + h*vy + ((h*h)/2.) * a*y[i];
        vx += h*a;
        vy += h*a;

    }
    return;
}

void ODESolver::Euler() {
    for (int i=0; i<n; i++) {
        x[i+1] = x[i] + vx*h;
        y[i+1] = y[i] + vy*h;
        vx -= a*x[i];
        vy -= a*y[i];
    }
    return;

}
