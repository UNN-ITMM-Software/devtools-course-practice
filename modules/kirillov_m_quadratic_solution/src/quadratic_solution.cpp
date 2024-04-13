// Copyright 2024 Kirillov Maxim

#include <stdexcept>
#include <vector>
#include <unordered_set>
#include "../include/quadratic_solution.h"

double QuadraticSolver::getA() const {
    return a;
}

double QuadraticSolver::getB() const {
    return b;
}

double QuadraticSolver::getC() const {
    return c;
}

double QuadraticSolver::getDiscriminant() const {
    return b * b - 4 * a * c;
}

// Pair: first means if the roots are finite, second means what are the roots
std::pair<bool, std::unordered_set<double>> QuadraticSolver::solveRealRoots() const {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                return {false, {}};
            } else {
                return {true, {}};
            }
        } else {
            return {true, {-c / b}};
        }
    } else {
        double discriminator = getDiscriminant();
        if (discriminator < 0) {
            throw std::runtime_error("No real roots");
        } else {
            double sqrt_disc = sqrt(discriminator);
            double root1 = (-b - sqrt_disc) / (2 * a);
            double root2 = (-b + sqrt_disc) / (2 * a);
            return {true, {root1, root2}};
        }
    }
}


std::pair<bool, std::unordered_set<std::complex<double>>>
QuadraticSolver::solveComplexRoots() const {
    double discriminator = getDiscriminant();
    if (discriminator >= 0) {
        double sqrt_disc = sqrt(discriminator);
        double root1 = (-b - sqrt_disc) / (2 * a);
        double root2 = (-b + sqrt_disc) / (2 * a);
        return {true, {root1, root2}};
    } else {
        double realPart = -b / (2 * a);
        double imagPart = std::sqrt(-discriminator) / (2 * a);
        return {true, {
                std::complex<double>(realPart, imagPart),
                std::complex<double>(realPart, -imagPart)
        }};
    }
}
