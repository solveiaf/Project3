#include "body.h"
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

Body::Body(double x, double y, double vx, double vy, double AU, double year, double n)
{
    h = year/n;
    r = AU;
    vx = vx;
    vy = vy;
    x = x;
    y = y;
    y = year;
    n = n;
}

double Body::getStep() {
    return h;
}

double Body::getNumber() {
    return n;
}

double Body::getRadii(double x, double y) {
    return sqrt(pow(x,2) + pow(y,2));
}

double Body::calculateAcceleration(double x, double y) {
    double h = year/n;
    double radii = getRadii(x,y);
    double a = (h*pi*pi*pow(AU,3))/(pow(radii,3)*year);
    return a;
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


