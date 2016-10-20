#include "system.h"
#include <fstream>
#include "body.h"
#include <string>
using namespace std;

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


double System::calculateForce(double x, double y,int number_particle,double m1, double m2){
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
    return * F;


}


double System::getRadii(double x, double y){
    return sqrt(pow(x,2) + pow(y,2));
}

