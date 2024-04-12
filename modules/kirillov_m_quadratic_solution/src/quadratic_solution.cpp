// Copyright 2024 Kirillov Maxim

#include <stdexcept>
#include <vector>
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

std::vector<double> QuadraticSolver::solve() const {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                return {};
            } else {
                throw std::runtime_error("No roots");
            }
        } else {
            return { -c / b };
        }
    } else {
        double discriminator = getDiscriminant();
        if (discriminator < 0) {
            throw std::runtime_error("No real roots");
        }
        double sqrt_disc = sqrt(discriminator);
        double root1 = (-b - sqrt_disc) / (2 * a);
        double root2 = (-b + sqrt_disc) / (2 * a);
        return { root1, root2 };
    }
}

std::vector<std::complex<double>> QuadraticSolver::solveComplex() const {
    double discriminator = getDiscriminant();
    double sqrt_disc = sqrt(discriminator);
    if (discriminator >= 0) {
        double root1 = (-b - sqrt_disc) / (2 * a);
        double root2 = (-b + sqrt_disc) / (2 * a);
        return { root1, root2 };
    } else {
        double realPart = -b / (2 * a);
        double imagPart = std::sqrt(-discriminator) / (2 * a);
        return {
            std::complex<double>(realPart, imagPart),
            std::complex<double>(realPart, -imagPart)
        };
    }
}
