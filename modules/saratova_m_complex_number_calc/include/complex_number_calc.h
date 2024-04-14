// Copyright 2024 Saratova Marina

#ifndef MODULES_SARATOVA_M_COMPLEX_NUMBER_CALC_INCLUDE_COMPLEX_NUMBER_CALC_H_
#define MODULES_SARATOVA_M_COMPLEX_NUMBER_CALC_INCLUDE_COMPLEX_NUMBER_CALC_H_

#include <vector>
#include <stdexcept>

class ComplexCalculator {
 private:
    double real;
    double imaginary;

 public:
    ComplexCalculator(double real, double imaginary);

    double getReal() const;
    double getImaginary() const;

    ComplexCalculator operator+(const ComplexCalculator& other) const;
    ComplexCalculator operator-(const ComplexCalculator& other) const;
    ComplexCalculator operator*(const ComplexCalculator& other) const;
    ComplexCalculator operator/(const ComplexCalculator& other) const;
};

#endif  // MODULES_SARATOVA_M_COMPLEX_NUMBER_CALC_INCLUDE_COMPLEX_NUMBER_CALC_H_
