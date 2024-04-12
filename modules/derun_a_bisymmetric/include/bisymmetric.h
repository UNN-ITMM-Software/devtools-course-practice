// Copyright 2024 Derun Andrey

#ifndef MODULES_DERUN_A_BISYMMETRIC_INCLUDE_BISYMMETRIC_H_
#define MODULES_DERUN_A_BISYMMETRIC_INCLUDE_BISYMMETRIC_H_

#include <iostream>
#include <vector>

template <typename T> class BisymmetricMatrix {
 private:
  std::vector<std::vector<T>> matrix;
  int size;

 public:
  explicit BisymmetricMatrix(int n) : size(n) {
    matrix.resize(n, std::vector<T>(n, T()));
  }

  int getSize() const { return size; }

  void setElement(int i, int j, const T &value) {
    if (i < 0 || i >= size || j < 0 || j >= size) {
      std::cerr << "Invalid index\n";
      return;
    }
    matrix[i][j] = value;
    matrix[j][i] = value;
  }

  T getElement(int i, int j) const {
    if (i < 0 || i >= size || j < 0 || j >= size) {
      std::cerr << "Invalid index\n";
      return T();
    }
    return matrix[i][j];
  }

  std::vector<T> &operator[](int index) {
    if (index < 0 || index >= size) {
      std::cerr << "Invalid index\n";
      return matrix[0];
    }
    return matrix[index];
  }

  void display() const {
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        std::cout << matrix[i][j] << " ";
      }
      std::cout << "\n";
    }
  }
};

#endif  // MODULES_DERUN_A_BISYMMETRIC_INCLUDE_BISYMMETRIC_H_
