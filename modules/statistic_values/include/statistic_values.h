// Copyright 2021 Prokofeva Elizaveta

#ifndef MODULES_STATISTIC_VALUES_INCLUDE_STATISTIC_VALUES_H_
#define MODULES_STATISTIC_VALUES_INCLUDE_STATISTIC_VALUES_H_

#include <vector>
using std::vector;

namespace statValues {
    double meanValue(vector<double> v, vector<double> p, int n);
    double variance(vector<double> v, vector<double> p, int n);
    double start(vector<double> v, vector<double> p, int n, int k);
    double centr(vector<double> v, vector<double> p, int n, int k);
}

#endif  // MODULES_STATISTIC_VALUES_INCLUDE_STATISTIC_VALUES_H_
