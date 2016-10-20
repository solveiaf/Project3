#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
#include <vector>
using namespace std;


class System
{
private:
    int n_bodies;
    vector<Body*> bodies;
public:
    System(string filename);
    void readFile();
    //Two body problem
    void calculateForce(double x, double y, int number_particle, double m1, double m2);
    double getRadii(double x, double y);
    void calculateAcceleration(double* F, double m);
    double integrateOneStep();
};

#endif // SYSTEM_H
