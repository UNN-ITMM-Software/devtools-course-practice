// Copyright 2024 Konovalov Igor

#include "include/konovalov_i_euler_f.h"
#include <math.h>
#include <stdexcept>

bool EulerFunction::contains_divider(int n, const std::vector<int>& v) {
  for (const int& i : v) {
    if (n % i == 0)
      return true;
  }
  return false;
}

int EulerFunction::euler(int n) {
  if (n < 1)
    throw std::invalid_argument("invalid number for euler function");

  int res = 1;
  for (int i = 2; i <= n; i++) {
    int r = 1;
    while (n % i == 0) {
      r *= i;
      n /= i;
    }
    if (r != 1)
      res *= (r - r / i);
  }
  return res;
}

int EulerFunction::euler_naive(int n) {
  if (n < 1)
    throw std::invalid_argument("invalid number for euler function");

  int res = 0;
  std::vector<int> prev{};
  for (int i = 1; i <= n; i++) {
    if (i != 1 && n % i == 0) {
      prev.push_back(i);
    } else if (!contains_divider(i, prev)) {
      res++;
    }
  }
  return res;
}
