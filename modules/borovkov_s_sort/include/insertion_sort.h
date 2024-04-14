// Copyright 2024 Borovkov Sergey
#ifndef MODULES_BOROVKOV_S_SORT_INCLUDE_INSERTION_SORT_H_
#define MODULES_BOROVKOV_S_SORT_INCLUDE_INSERTION_SORT_H_

#include <algorithm>
#include <iostream>
#include <vector>

namespace InsertionSort {
template <typename T>
void sort(std::vector<T>& arr) {
  int n = arr.size();
  for (int i = 1; i < n; ++i) {
    T key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}
}  // namespace InsertionSort

#endif  // MODULES_BOROVKOV_S_SORT_INCLUDE_INSERTION_SORT_H_
