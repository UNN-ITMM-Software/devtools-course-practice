// Copyright 2024 Kirillov Maxim
#pragma once

#include <vector>
#include <complex>
#include <utility>
#include <unordered_set>

namespace std {
template<>
struct hash<std::complex<double>> {
    size_t operator()(const std::complex<double>& value) const {
        size_t h1 = hash<double>()(value.real());
        size_t h2 = hash<double>()(value.imag());
        return h1 ^ (h2 << 1);
    }
};
}

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
    std::pair<bool, std::unordered_set<double>> solveRealRoots() const;
    std::pair<bool, std::unordered_set<std::complex<double>>>
    solveComplexRoots() const;
};
