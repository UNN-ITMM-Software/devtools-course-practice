// Copyright 2024 Kozlov Mikhail

#ifndef MODULES_KOZLOV_M_D_HEAP_LAB3_INCLUDE_HEAP_H_
#define MODULES_KOZLOV_M_D_HEAP_LAB3_INCLUDE_HEAP_H_

#include <algorithm>
#include <array>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <int N> class Heap {
private:
  std::array<double, N> t;
  uint64_t real_size = 0;
  void heapify(int n);

public:
  Heap() = default;
  Heap(const std::vector<double> &arr);
  void push(const double &el);
  void pop();
  double top();
  uint64_t size();
  bool empty();
};

template <int N> void Heap<N>::heapify(int n) {
  uint64_t left = 2 * n + 1;
  uint64_t right = 2 * n + 2;
  if (left < real_size) {
    if (t[n] < t[left]) {
      std::swap(t[n], t[left]);
      heapify(left);
    }
  }
  if (right < real_size) {
    if (t[n] < t[right]) {
      std::swap(t[n], t[right]);
      heapify(right);
    }
  }
}

template <int N> Heap<N>::Heap(const std::vector<double> &arr) {
  for (const auto &el : arr)
    push(el);
}

template <int N> void Heap<N>::push(const double &el) {
  if (real_size == N) {
    throw std::logic_error("Heap overflow");
  }
  uint64_t i = real_size;
  t[i] = el;
  int parent = (i - 1) / 2;
  while (parent >= 0 && i > 0) {
    if (t[i] > t[parent]) {
      std::swap(t[i], t[parent]);
    }
    i = parent;
    parent = (i - 1) / 2;
  }
  real_size++;
}

template <int N> void Heap<N>::pop() {
  if (real_size == 0)
    throw std::logic_error("Empty heap");
  t[0] = t[--real_size];
  heapify(0);
}

template <int N> double Heap<N>::top() {
  if (real_size == 0)
    throw std::logic_error("Empty heap");
  return t[0];
}

template <int N> uint64_t Heap<N>::size() { return real_size; }

template <int N> bool Heap<N>::empty() { return real_size == 0; }

#endif // MODULES_KOZLOV_M_D_HEAP_LAB3_INCLUDE_HEAP_H_