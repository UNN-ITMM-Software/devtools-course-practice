// Copyright 2021 Kolesin Andrey

#include "include/complex_number.h"

#include <limits>

Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}
double Complex::getReal() { return real; }
double Complex::getImag() { return imag; }
