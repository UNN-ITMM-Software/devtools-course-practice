// Copyright 2024 Mukhin Ivan

#include "include/integration_methods.h"
#include <cstdint>
#include <cstdlib>
#include <stdexcept>

double IntegrationMethods::integrate_trapezoid(
        const std::function<double(double)> &f,
        double x0, double xn, int n
    ) {
    if (n <= 0) {
        throw std::invalid_argument("Number of splits must be positive.");
    }
    double step = std::abs(xn - x0) / static_cast<double>(n);
    double result = 0.0;
    for (uint32_t i = 0; i < static_cast<uint32_t>(n); i++) {
        double x_next = x0 + (i + 1) * step;
        result += (step) * (f(x_next) + f(x_next - step)) / 2.0;
    }
    return result;
}

double IntegrationMethods::integrate_quads(
        const std::function<double(double)> &f,
        double x0, double xn, int n
    ) {
    if (n <= 0) {
        throw std::invalid_argument("Number of splits must be positive.");
    }
    double step = std::abs(xn - x0) / static_cast<double>(n);
    double result = 0.0;
    for (uint32_t i = 0; i < static_cast<uint32_t>(n); i++) {
        double x_next = x0 + i * step;
        result += f(x_next + step / 2.0);
    }
    return step * result;
}

