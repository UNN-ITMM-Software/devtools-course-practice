// Copyright 2024 Konovalov Igor

#ifndef MODULES_KONOVALOV_I_EULER_FUNCTION_LAB2_INCLUDE_KONOVALOV_I_EULER_F_H_
#define MODULES_KONOVALOV_I_EULER_FUNCTION_LAB2_INCLUDE_KONOVALOV_I_EULER_F_H_

#include <vector>

class EulerFunction {
 private:
  static bool contains_divider(int n, std::vector<int>& v);

 public:
  static int euler(int n);
  static int euler_naive(int n);
};

#endif  // MODULES_KONOVALOV_I_EULER_FUNCTION_LAB2_INCLUDE_KONOVALOV_I_EULER_F_H_
