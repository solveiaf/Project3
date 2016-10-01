#pragma once

class vec3 {
private:
    double m_vector[3];

public:
    vec3();
    vec3(double x, double y, double z);
    double length();
    void print();
    double& operator[](int i)   { return m_vector[i]; }
    vec3& operator+=(vec3 v);
    vec3& operator-=(vec3 v);
    vec3& operator/=(double a);
    vec3 operator-(vec3 v);
    vec3 operator*(double a);
    vec3 operator/(double a);
    void setVector(double x, double y, double z);
    double* getVector() { return m_vector; }
};
