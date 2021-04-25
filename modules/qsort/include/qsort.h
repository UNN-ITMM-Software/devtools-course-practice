// Copyright 2021 Taktaev Artem

#include <vector>

#ifndef MODULES_QSORT_INCLUDE_QSORT_H_
#define MODULES_QSORT_INCLUDE_QSORT_H_

namespace QSort {
    std::vector<double> createRandomVector(int vec_size);
    void Sort(std::vector<double> *arr, int left, int right);
}

#endif  // MODULES_QSORT_INCLUDE_QSORT_H_
