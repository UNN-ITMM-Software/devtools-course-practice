// Copyright 2024 Saratova Marina

#include "include/complex_number_calc.h"

ComplexCalculator::ComplexCalculator(double real, double imaginary)
    : real(real), imaginary(imaginary) {}

double ComplexCalculator::getReal() const {
    return real;
}

double ComplexCalculator::getImaginary() const {
    return imaginary;
}

ComplexCalculator ComplexCalculator::operator+
                                (const ComplexCalculator& other) const {
    double result_real = real + other.real;
    double result_imaginary = imaginary + other.imaginary;
    return ComplexCalculator(result_real, result_imaginary);
}

ComplexCalculator ComplexCalculator::operator-
                                    (const ComplexCalculator& other) const {
    double result_real = real - other.real;
    double result_imaginary = imaginary - other.imaginary;
    return ComplexCalculator(result_real, result_imaginary);
}

ComplexCalculator ComplexCalculator::operator*
                                    (const ComplexCalculator& other) const {
    double result_real = real * other.real - imaginary * other.imaginary;
    double result_imaginary = real * other.imaginary + imaginary * other.real;
    return ComplexCalculator(result_real, result_imaginary);
}

ComplexCalculator ComplexCalculator::operator/
                                    (const ComplexCalculator& other) const {
    double denominator = other.real * other.real + other.imaginary
                                                         * other.imaginary;
    if (denominator == 0) {
        throw std::invalid_argument("Error: Division by zero");
    }
    double result_real = (real * other.real + imaginary * other.imaginary)
                                                 / denominator;
    double result_imaginary = (imaginary * other.real - real *
                                 other.imaginary) / denominator;
    return ComplexCalculator(result_real, result_imaginary);
}
