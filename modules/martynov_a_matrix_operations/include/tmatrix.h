  // Copyright 2024 Martynov Aleksandr

#ifndef MODULES_MARTYNOV_A_MATRIX_OPERATIONS_INCLUDE_TMATRIX_H_
#define MODULES_MARTYNOV_A_MATRIX_OPERATIONS_INCLUDE_TMATRIX_H_

#include <iostream>
#include <utility>
#include <algorithm>

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

template<typename T>
class TDynamicVector {
 protected:
    size_t sz;
    T* pMem;

 public:
    explicit TDynamicVector(size_t size = 1) : sz(size) {
        if (sz == 0)
            throw std::out_of_range("Vector size should be greater than zero");
        if (sz > MAX_VECTOR_SIZE)
            throw - 1;
        pMem = new T[sz]();
    }
    TDynamicVector(T* arr, size_t s) : sz(s) {
        assert(arr != nullptr && "TDynamicVector requires non-nullptr arg");
        pMem = new T[sz];
        std::copy(arr, arr + sz, pMem);
    }
    TDynamicVector(const TDynamicVector& v) {
        sz = v.sz;
        pMem = new T[sz];
        std::copy(v.pMem, v.pMem + sz, pMem);
    }
    TDynamicVector(TDynamicVector&& v) noexcept {
        pMem = nullptr;
        swap(*this, v);
    }
    ~TDynamicVector() {
        if (pMem != nullptr)
            delete[] pMem;
    }
    TDynamicVector& operator=(const TDynamicVector& v) {
        if (*this == v) {
            return *this;
        }
        if (sz != v.sz) {
            T* p = new T[v.sz];
            delete[] pMem;
            sz = v.sz;
            pMem = p;
        }
         std::copy(v.pMem, v.pMem + v.sz, pMem);
        return *this;
    }
    TDynamicVector& operator=(TDynamicVector&& v) noexcept {
        swap(*this, v);
        return *this;
    }

    size_t size() const noexcept {
        return sz;
    }

    T& operator[](size_t ind) {
        if (ind < 0 || ind >= sz)
            throw - 1;
        return pMem[ind];
    }
    const T& operator[](size_t ind) const {
        if (ind < 0 || ind >= sz)
            throw - 1;
        return pMem[ind];
    }
    T& at(size_t ind) {
        if (ind < 0 || ind >= sz)
            throw - 1;
        return pMem[ind];
    }
    const T& at(size_t ind) const {
        if (ind < 0 || ind >= sz)
            throw - 1;
        return pMem[ind];
    }
    bool operator==(const TDynamicVector& v) const  {
        if (sz != v.sz) {
            return false;
        }
        for (size_t i = 0; i < sz; i++) {
            if (pMem[i] != v.pMem[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const TDynamicVector& v) const {
        if (*this == v) {
            return false;
        }
        return true;
    }
    TDynamicVector operator+(T val) {
        TDynamicVector tmp(sz);
        for (size_t i = 0; i < sz; i++) {
            tmp.pMem[i] = pMem[i] + val;
        }
        return tmp;
    }
    TDynamicVector operator-(double val) {
        TDynamicVector tmp(sz);
        for (size_t i = 0; i < sz; i++) {
            tmp.pMem[i] = pMem[i] - val;
        }
        return tmp;
    }
    TDynamicVector operator*(double val) {
        TDynamicVector tmp(sz);
        for (size_t i = 0; i < sz; i++) {
            tmp.pMem[i] = pMem[i] * val;
        }
        return tmp;
    }
    TDynamicVector operator+(const TDynamicVector& v) {
        if (sz != v.sz) {
            throw "Vectors are different size";
        }
        TDynamicVector tmp(sz);
        for (size_t i = 0; i < sz; i++) {
            tmp.pMem[i] = pMem[i] + v.pMem[i];
        }
        return tmp;
    }
    TDynamicVector operator-(const TDynamicVector& v) {
        if (sz != v.sz) {
            throw "Vectors are different size";
        }
        TDynamicVector tmp(sz);
        for (size_t i = 0; i < sz; i++) {
            tmp.pMem[i] = pMem[i] - v.pMem[i];
        }
        return tmp;
    }
    T operator*(const TDynamicVector& v) {
        if (sz != v.sz) {
            throw "Vectors are different size";
        }
        T value = 0;
        for (size_t i = 0; i < sz; i++) {
            value += pMem[i] * v.pMem[i];
        }
        return value;
    }

    friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept {
        std::swap(lhs.sz, rhs.sz);
        std::swap(lhs.pMem, rhs.pMem);
    }
};

template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>> {
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;

 public:
  explicit TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s) {
      if (sz > MAX_MATRIX_SIZE) {
          throw -1;
      }
      for (size_t i = 0; i < sz; i++) {
          pMem[i] = TDynamicVector<T>(sz);
      }
  }
  explicit TDynamicMatrix(const TDynamicVector<TDynamicVector<T>>& V) :
TDynamicVector<TDynamicVector<T>>(V) {}
  using TDynamicVector<TDynamicVector<T>>::operator[];
  bool operator==(const TDynamicMatrix& m) const noexcept {
      return TDynamicVector<TDynamicVector<T>>::operator==(m);
  }
  TDynamicVector<T> operator*(const T& val) {
      return TDynamicVector<TDynamicVector<T>>::operator*(val);
  }
  TDynamicVector<T> operator*(const TDynamicVector<T>& v) {
      TDynamicVector<T> tdv(sz);
      for (size_t i = 0; i < sz; i++) {
          tdv[i] = v * pMem[i];
      }
      return tdv;
  }
  TDynamicMatrix operator+(const TDynamicMatrix& m) {
    TDynamicMatrix<T> result(*this);
    size_t size = m.size();
    if (sz != size)
      throw "sizes aren't eq";

    for (size_t q = 0; q < size; q++) {
      for (size_t w = 0; w < size; w++) {
        result[q][w] += m[q][w];
      }
    }
    return result;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m) {
    TDynamicMatrix<T> result(*this);
    size_t size = m.size();
    if (sz != size)
      throw "sizes aren't eq";

    for (size_t q = 0; q < size; q++) {
      for (size_t w = 0; w < size; w++) {
        result[q][w] -= m[q][w];
      }
    }
    return result;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m) {
      if (sz != m.sz) {
          throw "sizes of matrix must are equals";
      }
      TDynamicMatrix tdm(sz);
      for (size_t i = 0; i < sz; i++) {
          for (size_t k = 0; k < sz; k++) {
              tdm[i][k] += pMem[i][k] * m.pMem[k][i];
          }
      }
      return tdm;
  }
  T findDeterm(const TDynamicMatrix& m) {
    T det = 1.0;
    TDynamicMatrix<T>tdm(m);
    for (size_t i = 0; i < tdm.size(); i++) {
      size_t pivot = i;
      for (size_t j = i + 1; j < tdm.size(); j++) {
        if (abs(tdm[j][i]) > abs(tdm[pivot][i])) {
          pivot = j;
        }
      }
      if (pivot != i) {
        swap(tdm[i], tdm[pivot]);
        det *= -1;
      }
      if (tdm[i][i] == 0) {
        return 0;
      }
      det *= tdm[i][i];
      for (size_t j = i + 1; j < tdm.size(); j++) {
        double factor = tdm[j][i] / tdm[i][i];
        for (size_t k = i + 1; k < tdm.size(); k++) {
          tdm[j][k] -= factor * tdm[i][k];
        }
      }
    }
    return det;
  }
  TDynamicMatrix<T> findInverse(const TDynamicMatrix& m) {
    size_t size = m.size();
    TDynamicMatrix<T> matE(size);
    TDynamicMatrix<T> A(m);
    T determ = A.findDeterm(A);
    if (determ == 0.0)
      throw "determinant = 0!";
    for (size_t q = 0; q < size; q++) {
      for (size_t w = 0; w < size; w++) {
        if (q == w)
          matE[q][w] = 1.0;
        else
          matE[q][w] = 0.0;
      }
    }

    for (size_t i = 0; i < size; i++) {
      auto temp1 = A[i][i];
      auto temp2 = temp1;
      for (size_t j = 0; j < size; j++) {
        if (i != j) {
          temp2 = A[j][i] / A[i][i];
          for (size_t q = 0; q < size; q++) {
            A[j][q] = A[j][q] - A[i][q] * temp2;
            matE[j][q] = matE[j][q] - matE[i][q] * temp2;
          }
        }
        temp2 = temp1;
      }
    }
    for (size_t i = 0; i < size; i++) {
      for (size_t j = 0; j < size; j++) {
        matE[i][j] = matE[i][j] / A[i][i];
      }
    }
    return matE;
  }
};
#endif  // MODULES_MARTYNOV_A_MATRIX_OPERATIONS_INCLUDE_TMATRIX_H_
