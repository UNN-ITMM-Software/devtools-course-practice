// Copyright 2021 Solovev Alexandr

#ifndef MODULES_BATCHER_MERGESORT_INCLUDE_MERGESORT_H_
#define MODULES_BATCHER_MERGESORT_INCLUDE_MERGESORT_H_

#include <vector>

namespace MergeSort {
    std::vector<double> createRandomVector(size_t vec_size);
    void OddEvenMergeSort(std::vector<double> *a, int l, int r);
}

#endif  // MODULES_BATCHER_MERGESORT_INCLUDE_MERGESORT_H_
