// Copyright 2024 Morgachev Stepan

#ifndef MODULES_MORGACHEV_S_BATCHER_MERGE_INCLUDE_BATCHER_MERGE_H_
#define MODULES_MORGACHEV_S_BATCHER_MERGE_INCLUDE_BATCHER_MERGE_H_

#include <vector>
#include <random>
#include <stdexcept>
#include <utility>

template<typename T>
class BatcherMerge {
 public:
  static void batcherMerge(std::vector<T>& vector) {
      size_t size = vector.size();
      if (size == 0) {
          throw std::invalid_argument("The array is empty");
       }
      for (size_t p = 1; p < size; p += p) {
          for (size_t k = p; k > 0; k /= 2) {
              for (size_t j = k % p; j + k < size; j += 2 * k) {
                  for (size_t i = 0; i < size - j - k; i++) {
                      if ((i + j) / (2 * p) == (i + j + k) / (2 * p)) {
                          compareAndSwap(vector[j + i], vector[j + i + k]);
                      }
                  }
              }
          }
      }
  }

  static std::vector<T> getRandomVector(size_t size) {
      std::random_device dev;
      std::mt19937 gen(dev());
      std::vector<T> vector(size);
      for (size_t i = 0; i < size; i++) {
          vector[i] = gen() % 100;
      }
      return vector;
  }

 private:
  static void compareAndSwap(T& a, T& b) {
      if (b < a)
          std::swap(a, b);
      }
};

#endif  // MODULES_MORGACHEV_S_BATCHER_MERGE_INCLUDE_BATCHER_MERGE_H_
