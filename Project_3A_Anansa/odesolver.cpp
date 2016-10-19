#include "odesolver.h"
#include <cmath>

ODESolver::ODESolver(double n, double h, double a) {
    n = n;
    h = h;
    a = a;
    VelocityVerlet(n,h,a);
    Euler(n,h,a);
}

void ODESolver:VelocityVerlet(double n, double h, double a) {
    //Algortihm for calculating velocity verlet
    for (int i = 0; i<n; i++) {
        x[i+1] = x[i] + h*vx + ((h*h)/2.) * a*x[i];
        y[i+1] = y[i] + h*vy + ((h*h)/2.) * a*y[i];
        vx += h*a;
        vy += h*a;

    }
    return;
}

void ODESolver:Euler(double n, double h, double a) {
    for (int i=0; i<n; i++) {
        x[i+1] = x[i] + vx*h;
        y[i+1] = y[i] + vy*h;
        vx -= a*x[i];
        vy -= a*y[i];
    }
    return;

}
