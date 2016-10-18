#ifndef BODY_H
#define BODY_H
#include <cmath>

class Body
{
private:
    double mass;
    double r0[3];
    double v0[3];
    double v[][];
    double r[][];
public:
    Body(double m, double radii[3], double v0[3]);
    double getMass();
    double getRadii();
    void calculateVelocityVerlet(double mass2);
    void calculateVelocityEuler(double mass2);
};

#endif // BODY_H
