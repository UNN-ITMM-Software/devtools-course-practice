// Copyright 2024 Derun Andrey

#ifndef MODULES_DERUN_A_BISYMMETRIC_INCLUDE_BISYMMETRIC_H_
#define MODULES_DERUN_A_BISYMMETRIC_INCLUDE_BISYMMETRIC_H_

#include <iostream>
#include <vector>

template <typename T>
class BisymmetricMatrix {
 private:
  std::vector<T> matrix;
  int size;
  int n;

  static int convertSize(int n) { return ((n + 1) / 2) * ((n + 1) / 2); }
  static bool isInside(int i, int j, int n) {
    int middle = n % 2 == 0 ? n / 2 : (n + 1) / 2;

    if (i < middle) {
      if (j > i) return false;
    } else {
      if (j > n - i - 1) return false;
    }
    return true;
  }
  static int convertIndex(int i1, int j1, int n) {
    int i2 = j1;
    int j2 = i1;

    int i3 = n - j1 - 1;
    int j3 = n - i1 - 1;

    int i4 = n - i1 - 1;
    int j4 = n - j1 - 1;

    int i0 = 0;
    int j0 = 0;

    if (isInside(i1, j1, n)) {
      i0 = i1;
      j0 = j1;
    } else if (isInside(i2, j2, n)) {
      i0 = i2;
      j0 = j2;
    } else if (isInside(i3, j3, n)) {
      i0 = i3;
      j0 = j3;
    } else if (isInside(i4, j4, n)) {
      i0 = i4;
      j0 = j4;
    } else {
      return -1;
    }

    int k = 0;
    int side = n;
    for (int j = 0; j < j0; j++) {
      k += side;
      side -= 2;
    }
    k += i0 - j0;

    return k;
  }

  static bool checkBisymmetric(
      const std::initializer_list<std::initializer_list<T>>& list) {
    int n = static_cast<int>(list.size());
    std::vector<std::vector<T>> m(n);

    int i = 0;
    for (const auto& row : list) {
      m[i] = std::vector<T>(row);
      i++;
    }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++)
        if (m[i][j] != m[j][i]) return false;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n - i; j++)
        if (m[i][j] != m[n - j - 1][n - i - 1]) return false;

    return true;
  }

 public:
  BisymmetricMatrix() : size(0), n(0) {}

  explicit BisymmetricMatrix(int n) : size(convertSize(n)), n(n) {
    matrix.resize(convertSize(n), T());
  }

  explicit BisymmetricMatrix(
      const std::initializer_list<std::initializer_list<T>>& list) {
    if (!checkBisymmetric(list)) {
      std::cerr << "List is not bisymmetric\n";
      throw std::logic_error("List is not bisymmetric");
    }

    n = static_cast<int>(list.size());
    size = convertSize(n);
    matrix.resize(size, T());

    std::vector<std::vector<T>> m(n);

    {
      int i = 0;
      for (const auto& row : list) {
        m[i] = std::vector<T>(row);
        i++;
      }
    }

    {
      int k = 0;

      int middle = (n % 2 == 0) ? (n / 2) : (n + 1) / 2;
      for (int j = 0; j < middle; j++)
        for (int i = j; i < n - j; i++) {
          matrix[k] = m[i][j];
          k++;
        }
    }
  }

  int getN() const { return n; }

  void setElement(int i, int j, const T& value) {
    if (i < 0 || i > n || j < 0 || j > n) {
      std::cerr << "Invalid index\n";
      throw std::out_of_range("Invalid index");
    }
    int i0 = convertIndex(i, j, n);
    matrix[i0] = value;
  }

  T getElement(int i, int j) const {
    if (i < 0 || i > n || j < 0 || j > n) {
      std::cerr << "Invalid index\n";
      throw std::out_of_range("Invalid index");
    }
    int i0 = convertIndex(i, j, n);
    return matrix[i0];
  }

  void display() const {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int i0 = convertIndex(i, j, n);
        std::cout << matrix[i0] << " ";
      }
      std::cout << "\n";
    }
  }
};

#endif  // MODULES_DERUN_A_BISYMMETRIC_INCLUDE_BISYMMETRIC_H_
