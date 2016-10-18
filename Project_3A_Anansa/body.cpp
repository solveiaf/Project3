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
