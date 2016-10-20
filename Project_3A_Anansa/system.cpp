#include "system.h"
#include <fstream>
#include "body.h"
#include <string>
using namespace std;
#include "odesolver.h"

System::System(int n) {

}

void System::addBody(Body body) {
    bodies.push_back(body);
    n_bodies++;
}

void System::calculatePotentialTwoB(double x, doube y){
    double temp_r, temp, Fx, Fy;
    double* F = new double [2];
    double m = bodies[0].getMass();
    temp_r = getRadii(x,y);
    temp = -(4*pi*pi*m)/pow(temp_r,3);
    Fx = temp*x;
    Fy = temp*y;
    } 
    F = [Fx,Fy];
}

void System::calculateAcceleration(double *F, m) {
    double a = new double[1];
    for (int i=0; i<=1; i++){
        a[i] = F[i]/m;
    }
}

double System::getRadii(double x, double y){
    return sqrt(pow(x,2) + pow(y,2));
}

double System::integrateOneStep(){
    calculateForce(x,y,number_particle,m1,m2,);
    calculateAcceleration(*F,m);
    ODESolver(n, timestep, *a);

}

