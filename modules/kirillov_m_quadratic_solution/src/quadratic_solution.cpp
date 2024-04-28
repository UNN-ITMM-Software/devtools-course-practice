// Copyright 2024 Kirillov Maxim

#include <stdexcept>
#include <vector>
#include <unordered_set>
#include "../include/quadratic_solution.h"

QuadraticSolver::QuadraticSolver(double _a, double _b, double _c) {
    this->a = _a;
    this->b = _b;
    this->c = _c;
}

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

RealResult QuadraticSolver::solveRealRoots() const {
    if (a == 0) {
        if (b == 0) {
            return { c != 0, {} };
        }
        return {true, {-c / b}};
    }
    double discriminator = getDiscriminant();
    if (discriminator < 0) {
        throw std::runtime_error("No real roots");
    }
    double sqrt_disc = sqrt(discriminator);
    double root1 = (-b - sqrt_disc) / (2 * a);
    double root2 = (-b + sqrt_disc) / (2 * a);
    return {true, {root1, root2}};
}

ComplexResult QuadraticSolver::solveComplexRoots() const {
    double discriminator = getDiscriminant();
    ComplexHash hasher;
    if (discriminator >= 0) {
        double sqrt_disc = sqrt(discriminator);
        double root1 = (-b - sqrt_disc) / (2 * a);
        double root2 = (-b + sqrt_disc) / (2 * a);
        ComplexRoots roots(2, hasher);
        roots.insert(root1);
        roots.insert(root2);
        return {true, roots};
    } else {
        double realPart = -b / (2 * a);
        double imagPart = std::sqrt(-discriminator) / (2 * a);
        ComplexRoots roots(2, hasher);
        roots.insert({realPart, imagPart});
        roots.insert({realPart, -imagPart});
        return {true, roots};
    }
}
