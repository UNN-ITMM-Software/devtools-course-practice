// Copyright 2021 Nikolaev Denis
#include "include/generator.h"
#include <random>
#include <ctime>



bool generator::NextSet(int* a, int n, int m) {
    int j = m - 1;
    while (a[j] == n && j >= 0) j--;
    if (j < 0) return false;
    a[j]++;
    if (j == m - 1) return true;
    for (int k = j + 1; k < m; k++)
        a[k] = a[j];
    return true;
}
