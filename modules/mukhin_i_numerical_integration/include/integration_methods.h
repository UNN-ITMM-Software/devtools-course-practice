// Copyright 2024 Mukhin Ivan
#ifndef MODULES_MUKHIN_I_NUMERICAL_INTEGRATION_INCLUDE_INTEGRATION_METHODS_H_
#define MODULES_MUKHIN_I_NUMERICAL_INTEGRATION_INCLUDE_INTEGRATION_METHODS_H_

#include <functional>

class IntegrationMethods{
 public:
    static double integrate_trapezoid(const std::function<double(double)>& f,
                                      double x0, double xn, int n);
    static double integrate_quads(const std::function<double(double)>& f,
                                  double x0, double xn, int n);
};

#endif  // MODULES_MUKHIN_I_NUMERICAL_INTEGRATION_INCLUDE_INTEGRATION_METHODS_H_
