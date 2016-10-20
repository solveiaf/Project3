#ifndef BODY_H
#define BODY_H
#include <cmath>
#include "body.h"
#include <fstream>
#include <string>
using namespace std;

class Body
{
private:
    double r;
    double vx;
    double vy;
    double n;
    double h;
    double x;
    double y;
public:
    Body(double x, double y, double vx, double vy, double AU, double year, double n);
    double getStep();
    double getNumber();
    double getRadii(double x, double y);
    void input();
    void output(double x, double y);
};

#endif // BODY_H
