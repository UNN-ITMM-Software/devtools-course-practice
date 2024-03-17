// Copyright 2017 Korniakov Kirill

#include "include/complex_number.h"

#include <stdbool.h>
#include <string>
#include <limits>

const double eps = std::numeric_limits<double>::epsilon();

ComplexNumber::ComplexNumber() : real_(0), imaginary_(0) {}

ComplexNumber::ComplexNumber(const double real,
                             const double imaginary)
                             : real_(real), imaginary_(imaginary) {}

ComplexNumber::ComplexNumber(const ComplexNumber& z)
                             : real_(z.getRe()), imaginary_(z.getIm()) {}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z) {
    real_ = z.getRe();
    imaginary_ = z.getIm();

    return *this;
}

double ComplexNumber::getRe() const {
    return real_;
}

double ComplexNumber::getIm() const {
    return imaginary_;
}

void ComplexNumber::setRe(const double real) {
    real_ = real;
}

void ComplexNumber::setIm(const double imaginary) {
    imaginary_ = imaginary;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const {
    ComplexNumber sum;

    sum.setRe(this->getRe() + z.getRe());
    sum.setIm(this->getIm() + z.getIm());

    return sum;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const {
    ComplexNumber difference;

    difference.setRe(this->getRe() - z.getRe());
    difference.setIm(this->getIm() - z.getIm());

    return difference;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const {
    ComplexNumber multiplication;

    multiplication.setRe(this->getRe() * z.getRe() -
                         this->getIm() * z.getIm());
    multiplication.setIm(this->getRe() * z.getIm() +
                         this->getIm() * z.getRe());

    return multiplication;
}

bool ComplexNumber::equalsZero(const ComplexNumber& z) const {
    return z.getRe() < eps && z.getRe() > -eps &&
           z.getIm() < eps && z.getIm() > -eps;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& z) const {
    ComplexNumber division;

    if (equalsZero(z)) {
        throw std::string("Can't divide by zero");
    } else {
        double denominator = 1.0 / (z.getRe() * z.getRe() +
                                    z.getIm() * z.getIm());

        division.setRe(denominator * this->getRe() * z.getRe() +
                       denominator * this->getIm() * z.getIm());
        division.setIm(denominator * this->getIm() * z.getRe() -
                       denominator * this->getRe() * z.getIm());
    }

    return division;
}

bool ComplexNumber::operator == (const ComplexNumber& z) const {
    return equalsZero(*this - z);
}

bool ComplexNumber::operator != (const ComplexNumber& z) const {
    return !(*this == z);
}
