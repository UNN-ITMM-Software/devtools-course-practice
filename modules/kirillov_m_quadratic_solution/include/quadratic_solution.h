// Copyright 2024 Kirillov Maxim

#pragma once

#include <vector>
#include <complex>
#include <utility>
#include <unordered_set>

struct ComplexHash {
    size_t operator()(const std::complex<double>& value) const {
        std::hash<double> hasher;
        size_t h1 = hasher(value.real());
        size_t h2 = hasher(value.imag());
        return h1 ^ (h2 << 1);
    }
};

using ComplexRoots = std::unordered_set<std::complex<double>, ComplexHash>;
using RealRoots = std::unordered_set<double>;
using ComplexResult = std::pair<bool, ComplexRoots>;
using RealResult = std::pair<bool, RealRoots>;

class QuadraticSolver {
 private:
    double a;
    double b;
    double c;
 public:
    QuadraticSolver(double a = 0, double b = 0, double c = 0): a(a), b(b), c(c) {}
    double getA() const;
    double getB() const;
    double getC() const;
    double getDiscriminant() const;
    RealResult solveRealRoots() const;
    ComplexResult solveComplexRoots() const;
};
