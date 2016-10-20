#ifndef SYSTEM_H
#define SYSTEM_H


class System
{
private:
    int n_particles;
public:
    System();
    void readFile();
    //Two body problem
    double calculateForce(double x, double y, int number_particle, double m1, double m2);
    double getRadii(double x, double y);
};

#endif // SYSTEM_H
