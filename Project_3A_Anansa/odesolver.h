#ifndef ODESOLVER_H
#define ODESOLVER_H


class ODESolver
{
private:
    double n, h, a;
public:
    ODESolver();
    void VelocityVerlet(double n, double h, double a);
    void Euler(double n, double h, double a);
};

#endif // ODESOLVER_H
