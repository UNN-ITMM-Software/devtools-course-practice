// Copyright 2024 Kirillov Maxim
#pragma once

#include <vector>
#include <complex>

class QuadraticSolver {
 private:
    double a;
    double b;
    double c;
 public:
    QuadraticSolver(double a, double b, double c) : a(a), b(b), c(c) {}
    double getA() const;
    double getB() const;
    double getC() const;
    double getDiscriminant() const;
    std::vector<double> solve() const;
    std::vector<std::complex<double>> solveComplex() const;
};
