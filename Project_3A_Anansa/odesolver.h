#ifndef ODESOLVER_H
#define ODESOLVER_H


class ODESolver
{
private:
    double n, h, a;
    double * x;
    double * y;
public:
    ODESolver(double n, double h, double a);
    void VelocityVerlet();
    void Euler();

};

#endif // ODESOLVER_H
