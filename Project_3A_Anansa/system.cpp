#include "system.h"
#include <fstream>
#include "body.h"
<<<<<<< HEAD
#include <string>
using namespace std;
=======
#include "odesolver.h"
>>>>>>> 9175fae37ada45083c58cb573715038fe5b55000

System::System(string filename)
{
    readFile();
}

void System::readFile() {
    ifile = ifstream;
    double line = 0.0;
    double row = 0.0;
    ifstream.open(filename);
    while(!infile.eof) {
        while(!getline(filename, line, '/n')) {


        }

        n_particles++;
    }
}


void System::calculateForce(double x, double y,int number_particle,double m1, double m2){
    double temp_r, temp, Fx, Fy;
    double F = new double [1];
    temp_r = getRadii(x,y);
    if (number_particle == 2) {
        temp = -(4*pi*pi*m1)/pow(temp_r,3);
        Fx = temp*x;
        Fy = temp*y;
    }
    else if (number_particle>2) {
        temp = - (G*m1*m2)/pow(temp_r,3);
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

