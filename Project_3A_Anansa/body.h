#ifndef BODY_H
#define BODY_H
#include <cmath>

class Body
{
private:
    double mass;
    double velocity[];
    double r;
public:
    Body(double m, double radii);
    double getMass();
    double getRadii();
    void calculateVelocity(double r, double mass1, double mass2);
};

#endif // BODY_H
