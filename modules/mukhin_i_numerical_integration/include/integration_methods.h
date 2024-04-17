// Copyright 2024 Mukhin Ivan

#include <functional>

class IntegrationMethods{
 public:
    static double integrate_trapezoid(const std::function<double(double)>& f, double x0, double xn, int n);
    static double integrate_quads(const std::function<double(double)>& f, double x0, double xn, int n);
};