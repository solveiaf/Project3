#pragma once
#include <vector>

class vec3 {
private:
    double m_vector[3];

public:
    vec3();
    vec3(double x, double y, double z);
    double length();
    void print();

    // Operators.
    double& operator[](int i)   { return m_vector[i]; }
    vec3& operator+=(vec3 v);
    vec3& operator-=(vec3 v);
    vec3 operator-(vec3 v);
    vec3 operator*(double a);
    vec3 operator/(double a);

    // Setters.
    void setVector(double x, double y, double z);
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    // Getters.
    double* getVector() { return m_vector; }
};
