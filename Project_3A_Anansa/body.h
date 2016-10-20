#ifndef BODY_H
#define BODY_H

class Body
{
private:
    double * x;
    double * y;
    double vx;
    double vy;
    double mass;

public:
    Body(double x, double y, double vx, double vy, double mass);
    double getStep();
    double getNumber();
    void setVelocity();
    double getRadii(double x, double y);
    void input();
    void output(double x, double y);
};

#endif // BODY_H
