// Copyright 2024 Smirnova Darya

#include "include/fraction_calculator.h"

#include <math.h>
#include <stdexcept>
#include <string>
#include <sstream>

FractionCalculator::FractionCalculator() : num(0), den(1) {}

FractionCalculator::FractionCalculator(const int numerator,
    const int denominator)
    : num(numerator) {
    if (denominator == 0)
        throw std::invalid_argument("Denominator cannot be a zero");
    else
        den = denominator;
}

int FractionCalculator::GetNum() const {
    return num;
}

void FractionCalculator::SetNum(const int numerator) {
    num = numerator;
}

int FractionCalculator::GetDen() const {
    return den;
}

void FractionCalculator::SetDen(const int denominator) {
    if (denominator == 0)
        throw std::invalid_argument("Denominator cannot be zero");
    den = denominator;
}

int FractionCalculator::NOD(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

FractionCalculator FractionCalculator::operator+(
    const FractionCalculator& obj) const {

    int numerator = this->GetNum() * obj.GetDen()
        + obj.GetNum() * this->GetDen();
    int denominator = this->GetDen() * obj.GetDen();
    int nod = NOD(numerator, denominator);

    numerator /= nod;
    denominator /= nod;

    FractionCalculator sum(numerator, denominator);

    return sum;
}

FractionCalculator FractionCalculator::operator-(
    const FractionCalculator& obj) const {
    int numerator = this->GetNum() * obj.GetDen()
        - obj.GetNum() * this->GetDen();
    int denominator = this->GetDen() * obj.GetDen();
    int nod = NOD(numerator, denominator);

    numerator /= nod;
    denominator /= nod;

    FractionCalculator diff(numerator, denominator);

    return diff;
}

FractionCalculator FractionCalculator::operator*(
    const FractionCalculator& obj) const {
    int numerator = this->GetNum() * obj.GetNum();
    int denominator = this->GetDen() * obj.GetDen();
    int nod = NOD(numerator, denominator);

    numerator /= nod;
    denominator /= nod;

    FractionCalculator product(numerator, denominator);

    return product;
}

FractionCalculator FractionCalculator::operator/(
    const FractionCalculator& obj) const {
    int numerator = this->GetNum() * obj.GetDen();
    int denominator = this->GetDen() * obj.GetNum();

    if (denominator == 0)
        throw std::invalid_argument("Division by zero");

    int nod = NOD(numerator, denominator);

    numerator /= nod;
    denominator /= nod;

    FractionCalculator quotient(numerator, denominator);

    return quotient;
}

FractionCalculator& FractionCalculator::operator=
(const FractionCalculator& obj) {
    if (this != &obj) {
        num = obj.num;
        den = obj.den;
    }
    return *this;
}

std::string FractionCalculator::ToString() const {
    std::stringstream ss;
    ss << num << "/" << den;
    return ss.str();
}
