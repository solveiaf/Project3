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


