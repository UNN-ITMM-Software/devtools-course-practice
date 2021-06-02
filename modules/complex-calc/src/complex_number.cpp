// Copyright 2021 Kolesin Andrey

#include "include/complex_number.h"

#include <math.h>

#include <limits>
#include <sstream>

double eps = std::numeric_limits<double>::epsilon();

Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}
double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }
bool Complex::operator==(const Complex& comp) const {
    return fabs(comp.real - real) <= eps && fabs(comp.imag - imag) <= eps;
}
bool Complex::operator!=(const Complex& comp) const {
    return !((*this) == comp);
}
const Complex Complex::operator+(const Complex& comp) {
    double re = comp.real + real;
    double im = comp.imag + imag;
    return Complex(re, im);
}
const Complex Complex::operator-(const Complex& comp) {
    double re = real - comp.real;
    double im = imag - comp.imag;
    return Complex(re, im);
}
const Complex Complex::operator*(const Complex& comp) {
    double re = real * comp.real - imag * comp.imag;
    double im = real * comp.imag + imag * comp.real;
    return Complex(re, im);
}
const Complex Complex::operator/(const Complex& comp) {
    double d = comp.real * comp.real + comp.imag * comp.imag;
    if (fabs(d) < eps) {
        throw -1;
    }
    double re = (real * comp.real + imag * comp.imag) / d;
    double im = (-real * comp.imag + imag * comp.real) / d;
    return Complex(re, im);
}
