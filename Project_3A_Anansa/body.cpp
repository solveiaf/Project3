#include "body.h"
#include <cmath>

Body::Body(double m, double x, double y, double vx, double vy, double AU)
{
    radii = AU;
    mass = m;
    vx = vx;
    vy = vy;
    x[0] = x;
    y[0] = y;
}

double Body::getMass() {
    return mass;
}

double Body::getRadii(double x, double y) {
    return sqrt(pow(x,2) + pow(y,2));
}

void Body::calculateVelocityVerlet(double mass2) {
        //Algortihm for calculating velocity verlet
    for (int i = 0; i<n; i++) {
        x[i+1] = x[i] + h*vx[i] + ((h*h)/2.) *a;
        y[i+1] = y[i] + h*vy[i] + ((h*h)/2.) *a;
        vx[i+1] = vx[i] + h*a;
        vy[i+1] = vy[i] + h*a;

    }
}

void Body::calculateVelocityEuler(double n, double time) {
    double dt = time/n;
    for (int i=0; i<n; i++) {
        r = Body::getRadii(x[i],y[i]);
        x[i+1] = x[i] + vx*dt;
        y[i+1] = y[i] + vy*dt;
        vx -= (dt*4*pi*pi*pow(AU,3))/(pow(r,3)*time)*x[i];
        vy -= (dt*4*pi*pi*pow(AU,3))/(pow(r,3)*time)*y[i];
    }
    return;
}


