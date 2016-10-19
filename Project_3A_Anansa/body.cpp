#include "body.h"
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

Body::Body(double m, double x, double y, double vx, double vy, double AU)
{
    radii = AU;
    mass = m;
    vx = vx;
    vy = vy;
    x[0] = x;
    y[0] = y;
}

double Body::getMass() {
    return mass;
}

double Body::getRadii(double x, double y) {
    return sqrt(pow(x,2) + pow(y,2));
}

void Body::calculateVelocityVerlet(double n, double year) {
    double h = year/n;
        //Algortihm for calculating velocity verlet
    for (int i = 0; i<n; i++) {
        r = Body::getRadii(x[i],y[i]);
        x[i+1] = x[i] + h*vx + ((h*h)/2.) * (h*4*pi*pi*pow(AU,3))/(pow(r,3)*year)*x[i];
        y[i+1] = y[i] + h*vy + ((h*h)/2.) * (h*4*pi*pi*pow(AU,3))/(pow(r,3)*year)*y[i];
        vx += h*a;
        vy += h*a;

    }
    return;
}

void Body::calculateVelocityEuler(double n, double year) {
    double h = year/n;
    for (int i=0; i<n; i++) {
        r = Body::getRadii(x[i],y[i]);
        x[i+1] = x[i] + vx*h;
        y[i+1] = y[i] + vy*h;
        vx -= (h*4*pi*pi*pow(AU,3))/(pow(r,3)*year)*x[i];
        vy -= (h*4*pi*pi*pow(AU,3))/(pow(r,3)*year)*y[i];
    }
    return;
}

void Body::input() {
    ifstream ifile;
}

void Body::output(double x, double y, h, n)  {
    ofstream ofile;
    string outfilename;

    cout << "Please enter the outputfilename: ";
    cin >> outfilename;

    ofile.open(outfilename);
    ofile << "x  " << "y " << "t  " << "timestep=" << h << "n= " << n << endl;
    double t;
    for (int i; i <=n; i++){
        t = h*i;
        ofile << x[i] <<"   " << y[i] << "   " << t << endl;
    }
}


