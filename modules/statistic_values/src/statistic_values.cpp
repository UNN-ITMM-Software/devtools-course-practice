// Copyright 2021 Prokofeva Elizaveta

#include <vector>
#include <cmath>

#include "include/statistic_values.h"

double statValues::meanValue(vector<double> v, vector<double> p, int n) {
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += v[i] * p[i];
    }
    return res;
}

double statValues::variance(vector<double> v, vector<double> p, int n) {
    double res = 0.0;
    double mean_value = statValues::meanValue(v, p, n);
    for (int i = 0; i < n; i++) {
        res += p[i] * pow((v[i] - mean_value), 2);
    }
    return res;
}

double statValues::start(vector<double> v, vector<double> p, int n, int k) {
    double res = 0.0;
    for (int i = 0; i < n; i++) {
            res += pow(v[i], k) * p[i];
    }
    return res;
}

double statValues::centr(vector<double> v, vector<double> p, int n, int k) {
    double res = 0.0;
    double mean_value = statValues::meanValue(v, p, n);
    for (int i = 0; i < n; i++) {
        res += p[i] * pow((v[i] - mean_value), k);
    }
    return res;
}
