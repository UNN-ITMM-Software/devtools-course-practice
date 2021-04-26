// Copyright 2021 Tashirev Ivan
#include <vector>
#include <random>
#include <ctime>
#include <numeric>
#include"integral.h"

double func1(double x) { return 1 / (log(pow(x, 2)) + x); }
double func2(double x) { return exp(x) / (1 + pow(x, 3)); }
double func3(double x) { return sin(x) / (exp(x) + x); }

double get_Integral(double(*func)(double), int a, int b, int n) {
    double  h, res = 0.0;
    h = static_cast<double>(b - a) / static_cast<double>(n);
    for (int i = 0; i < n; i++) {
        double x = static_cast<double>(a) + h * static_cast<double>(i) + h / 2;
        res += func(x);
    }
    res = res * h;
    return res;
}
