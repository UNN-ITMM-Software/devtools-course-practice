// Copyright 2021 Yurin Stanislav

#include "include/fraction.h"

#include <math.h>

Fraction::Fraction(int n, int d) {
    if (d == 0) {
        throw "Can't have zero denominator";
    }

    if (d < 0) {
        n *= -1;
        d *= -1;
    }

    int gcd_n_and_d = gcd(abs(n), abs(d));

    numerator = n / gcd_n_and_d;
    denominator = d / gcd_n_and_d;
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

int Fraction::gcd(int a, int b) {
    if (a < 0 || b < 0) {
        throw "Can't find gcd if one of numbers is negative";
    }

    while (a && b) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }

    return a + b;
}

int Fraction::lcm(int a, int b) {
    if (a < 0 || b < 0) {
        throw "Can't find gcd if one of numbers is negative";
    }

    return a / gcd(a, b) * b;
}

Fraction &Fraction::operator=(const Fraction &right) {
    if (this == &right) {
        return *this;
    }

    numerator = right.getNumerator();
    denominator = right.getDenominator();

    return *this;
}

Fraction Fraction::operator+(Fraction f) {
    int lcm_ = lcm(this->getDenominator(), f.getDenominator());

    int res_numerator = this->getNumerator() *
                        (lcm_ / this->getDenominator()) +
                        f.getNumerator() *
                        (lcm_ / f.getDenominator());

    return Fraction(res_numerator, lcm_);
}

Fraction Fraction::operator-(Fraction f) {
    int lcm_ = lcm(this->getDenominator(), f.getDenominator());

    int res_numerator = this->getNumerator() *
                        (lcm_ / this->getDenominator()) -
                        f.getNumerator() *
                        (lcm_ / f.getDenominator());

    return Fraction(res_numerator, lcm_);
}

Fraction Fraction::operator*(Fraction f) {
    return Fraction(this->getNumerator() * f.getNumerator(),
                    this->getDenominator() * f.getDenominator());
}

Fraction Fraction::operator/(Fraction f) {
    return Fraction(this->getNumerator() * f.getDenominator(),
                    this->getDenominator() * f.getNumerator());
}
