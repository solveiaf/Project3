#include <QCoreApplication>
#include "body.h"
#include "odesolver.h"
#include "system.h"

Body::Body(double x, double y, double vx, double vy, double m, double n) {
    x = new double[n];
    y = new double[n];
    x[0] = x;
    y[0] = y;
    vx = vx;
    vy = vy;
    mass = m;
}

double Body::getXPosition(int index) {
    return x[index];
}

double Body::getYPosition(int index) {
    return y[index];
}

double Body::getYVelocity() {
    return vy;
}

double Body::getXVelocity() {
    return vx;
}

double Body::getMass() {
    return mass;
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


