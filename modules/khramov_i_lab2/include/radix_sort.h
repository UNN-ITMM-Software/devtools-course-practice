// Copyright 2024 Khramov Ivan

#ifndef MODULES_KHRAMOV_I_LAB2_INCLUDE_RADIX_SORT_H_
#define MODULES_KHRAMOV_I_LAB2_INCLUDE_RADIX_SORT_H_

#include <vector>
#include <memory>

class RadixSort {
 public:
  static void radixSort(std::vector<int>& array, bool order = true);
 private:
  static void countSort(std::vector<int>& array, int digit, bool order);
  static int getMaximumOrMinimum(std::vector<int>& array);
};

#endif  // MODULES_KHRAMOV_I_LAB2_INCLUDE_RADIX_SORT_H_
