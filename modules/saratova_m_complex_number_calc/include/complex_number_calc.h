// Copyright 2024 Saratova Marina

#ifndef MODULES_SARATOVA_M_COMPLEX_NUMBER_CALC_INCLUDE_COMPLEX_NUMBER_CALC_H_
#define MODULES_SARATOVA_M_COMPLEX_NUMBER_CALC_INCLUDE_COMPLEX_NUMBER_CALC_H_

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class ComplexCalculator {
 private:
  double real;
  double imaginary;

 public:
  ComplexCalculator() : real(0), imaginary(0) {}
  ComplexCalculator(double real, double imaginary);
  double getReal() const;
  double getImaginary() const;

  ComplexCalculator operator+(const ComplexCalculator& other) const;
  ComplexCalculator operator-(const ComplexCalculator& other) const;
  ComplexCalculator operator*(const ComplexCalculator& other) const;
  ComplexCalculator operator/(const ComplexCalculator& other) const;
  std::string toString() const;
};

#endif  // MODULES_SARATOVA_M_COMPLEX_NUMBER_CALC_INCLUDE_COMPLEX_NUMBER_CALC_H_
