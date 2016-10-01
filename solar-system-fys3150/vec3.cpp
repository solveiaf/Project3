#include <vec3.h>
#include <cmath>
#include <iostream>

vec3::vec3()
        : vec3(0, 0, 0) {
}

vec3::vec3(double x, double y, double z) {
    setVector(x, y, z);
}

double vec3::length() {
    return std::sqrt(m_vector[0]*m_vector[0] +
                     m_vector[1]*m_vector[1] +
                     m_vector[2]*m_vector[2]);
}

void vec3::print() {
    std::cout << "(" << m_vector[0] << ", "
                     << m_vector[1] << ", "
                     << m_vector[2] << ")";
}

vec3& vec3::operator+=(vec3 v) {
    m_vector[0] += v[0];
    m_vector[1] += v[1];
    m_vector[2] += v[2];
    return *this;
}

vec3& vec3::operator-=(vec3 v) {
    m_vector[0] -= v[0];
    m_vector[1] -= v[1];
    m_vector[2] -= v[2];
    return *this;
}

vec3 vec3::operator-(vec3 v) {
    return vec3(m_vector[0]-v[0], m_vector[1]-v[1], m_vector[2]-v[2]);
}

vec3 vec3::operator*(double a) {
    return vec3(m_vector[0]*a, m_vector[1]*a, m_vector[2]*a);
}

vec3 vec3::operator/(double a) {
    return vec3(m_vector[0]/a, m_vector[1]/a, m_vector[2]/a);
}

vec3& vec3::operator/=(double a) {
    m_vector[0] /= a;
    m_vector[1] /= a;
    m_vector[2] /= a;
    return *this;
}

void vec3::setVector(double x, double y, double z) {
    m_vector[0] = x;
    m_vector[1] = y;
    m_vector[2] = z;
}

void vec3::setX(double x) {
    m_vector[0] = x;
}

void vec3::setY(double y) {
    m_vector[1] = y;
}

void vec3::setZ(double z) {
    m_vector[2] = z;
}


