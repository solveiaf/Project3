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
    Body(double x, double y, double vx, double vy, double mass, int n);
    double getXPosition(int index);
    double getYPosition(int index);
    double getXVelocity(int index);
    double getYVelocity(int index);
    void input();
    void output(double x, double y);
};

#endif // BODY_H
