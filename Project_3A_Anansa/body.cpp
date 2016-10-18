#include "body.h"
#include <cmath>

Body::Body(double m, double radii)
{
    mass = m;
    r = radii;
}

double Body::getMass() {
    return mass;
}

double Body::getRadii() {
    return r;
}

void Body::calculateVelocity(double r, double mass1, double mass2) {

}

void calculateVelocityVerlet(double mass2)  {
    //Algortihm for calculating velocity verlet
    for (int i = 0; i<n; i++) {
        x[i+1] = x[i] + h*vx[i] + ((h*h)/2.) *a;
        y[i+1] = y[i] + h*vy[i] + ((h*h)/2.) *a;
        vx[i+1] = vx[i] + h*a;
        vy[i+1] = vy[i] + h*a

}
}
