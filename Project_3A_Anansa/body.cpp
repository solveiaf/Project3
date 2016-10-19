#include "body.h"
#include <cmath>

Body::Body(double m, double x, double y, double vx, double vy, double AU, double year, double n)
{
    h = year/n;
    r = AU;
    mass = m;
    vx = vx;
    vy = vy;
    x[0] = x;
    y[0] = y;
    y = year;
    n = n;
}

double Body::getStep() {
    return h;
}

double Body::getRadii(double x, double y) {
    return sqrt(pow(x,2) + pow(y,2));
}

double Body::calculateAcceleration(double x, double y) {
    double h = year/n;
    double radii = getRadii(x,y);
    double a = (h*pi*pi*pow(AU,3))/(pow(radii,3)*year);
    return a;
}


