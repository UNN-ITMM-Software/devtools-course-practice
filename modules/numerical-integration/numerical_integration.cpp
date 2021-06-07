// Copyright 2021 Tareev Daniil

#include <cmath>
#include <string>

#include "include/numerical_integration.h"

NumericalIntegration::NumericalIntegration(double _a, double _b) {
    if (_a >= _b) {
        throw static_cast<std::string>(
            "The left border should be less than the right border");
    }

    a = _a;
    b = _b;
}

NumericalIntegration& NumericalIntegration::operator=(
    const NumericalIntegration& obj) {
    a = obj.a;
    b = obj.b;

    return *this;
}

bool NumericalIntegration::operator == (
    const NumericalIntegration& obj) const {
    return (a == obj.a) && (b == obj.b);
}

void NumericalIntegration::Set_integration_borders(double _a, double _b) {
    a = _a;
    b = _b;
}

double NumericalIntegration::Get_left_border() const {
    return a;
}

double NumericalIntegration::Get_right_border() const {
    return b;
}

double NumericalIntegration::Left_rectangle_method(
    FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + i * h;
        I += func->f(x);
    }

    return I * h;
}

double NumericalIntegration::Right_rectangle_method(
    FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 1; i <= N; i++) {
        double x = a + i * h;
        I += func->f(x);
    }

    return I * h;
}

double NumericalIntegration::Middle_rectangle_method(
    FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        I += func->f(x);
    }

    return I * h;
}

double NumericalIntegration::Trapezoid_method(
    FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + i * h;
        I += (func->f(x) + func->f(x + h)) / 2.0;
    }

    return I * h;
}

double NumericalIntegration::Simpsons_method(
    FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i += 2) {
        double x = a + i * h;
        I += func->f(x - h) + 4.0 * func->f(x) + func->f(x + h);
    }

    return I * h / 3.0;
}

double NumericalIntegration::Gauss_method(
    FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + i * h;
        double t1 = (2.0 * x + h) / 2.0;
        double t2 = h / (2.0 * sqrt(3.0));
        I += func->f(t1 - t2) + func->f(t1 + t2);
    }

    return I * h / 2.0;
}