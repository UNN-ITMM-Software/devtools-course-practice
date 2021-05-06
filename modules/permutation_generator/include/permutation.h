// Copyright 2021 Romanyuk Sergey
#ifndef MODULES_PERMUTATION_GENERATOR_INCLUDE_PERMUTATION_H_
#define MODULES_PERMUTATION_GENERATOR_INCLUDE_PERMUTATION_H_
#include <algorithm>
#include <utility>

class Permutation {
 public:
    void swap(int *a, int i, int j);
    bool NextSet(int *a, int n);
    int fact(int N);
    int* get_arr(int n);
};

#endif  // MODULES_PERMUTATION_GENERATOR_INCLUDE_PERMUTATION_H_
