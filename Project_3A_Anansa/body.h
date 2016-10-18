#ifndef BODY_H
#define BODY_H
#include <cmath>

class Body
{
private:
    double mass;
    double radii;
    double vx;
    double vy;
    double x[];
    double y[];
public:
    Body(double m, double x, double y, double vx, double vy);
    double getMass();
    double getRadii(double x, double y);
    void calculateVelocityVerlet(double mass2);
    void calculateVelocityEuler(double mass2);
};

#endif // BODY_H
