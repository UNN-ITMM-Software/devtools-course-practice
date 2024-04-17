#include "include/integration_methods.h"
#include <cstdlib>

double IntegrationMethods::integrate_trapezoid(const std::function<double (double)> &f,
                                               double x0, double xn, int n) {
    double step = std::abs(xn - x0) / (double)n;
    double result = 0.0;
    for(int i = 0; i < n; i++){
        double x_next = x0 + (i + 1) * step;
        result += (step) * (f(x_next) + f(x_next - step)) / 2.0;
    }
    return result;
}

double IntegrationMethods::integrate_quads(const std::function<double (double)> &f,
                                           double x0, double xn, int n) {
    double step = std::abs(xn - x0) / (double)n;
    double result = 0.0;
    for(int i = 0; i < n; i++){
        double x_next = x0 + i * step;
        result += f(x_next + step / 2.0);
    }
    return step * result;
}

