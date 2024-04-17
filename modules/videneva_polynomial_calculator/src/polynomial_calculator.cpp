// Copyright 2024 Videneva Ekaterina

#include "include/polynomial_calculator.h"
#include <math.h>
#include <string.h>

#define EPS 1e-7
polynomial_calculator::polynomial_calculator() {}

polynomial_calculator::
polynomial_calculator(double a0) {
    coeff_a.push_back(a0);
}

polynomial_calculator::
polynomial_calculator(const std::vector<double> coeff_a_, int len) {
    coeff_a.clear();
    int size = coeff_a_.size();
    if (size != len)
        throw "The number of coefficients does not correspond to the length!";
    for (int i = len - 1; i >= 0; i--)
        coeff_a.push_back(coeff_a_[i]);
}

int polynomial_calculator::GetSize() const {
    return coeff_a.size();
}

polynomial_calculator::
polynomial_calculator(const polynomial_calculator& _Polynom) {
    coeff_a.clear();
    for (int i = 0; i < _Polynom.GetSize(); i++) {
        coeff_a.push_back(_Polynom.coeff_a[i]);
    }
}

polynomial_calculator& polynomial_calculator::
operator=(const polynomial_calculator& v) {
    if (this != &v) {
    coeff_a.clear();
    for (int i = 0; i < v.GetSize(); i++) {
        coeff_a.push_back(v.coeff_a[i]);
    }
  }
  return *this;
}

polynomial_calculator& polynomial_calculator::
operator=(polynomial_calculator&& v) noexcept {
if (this != &v) {
    coeff_a = std::move(v.coeff_a);
  }
  return *this;
}

polynomial_calculator::
polynomial_calculator(polynomial_calculator&& v) noexcept {
  coeff_a = std::move(v.coeff_a);
}

double polynomial_calculator::value(double x) {
    double f = 0;
    for (int i = GetSize() - 1; i >= 0; --i) {
        f = f * x + coeff_a[i];
    }
    return f;
}

bool polynomial_calculator::operator ==
(const polynomial_calculator& _Polynom) const {
    if (this->GetSize() != _Polynom.GetSize())
        return false;
    for (int i = GetSize() - 1; i >= 0; --i)
        if (abs(this->coeff_a[i] - _Polynom.coeff_a[i]) > EPS)
            return false;
    return true;
}

bool polynomial_calculator::operator !=
(const polynomial_calculator& _Polynom) const {
    if (*this == _Polynom)
        return false;
    else
        return true;
}

polynomial_calculator polynomial_calculator
::operator + (const polynomial_calculator& _Polynom) {
    polynomial_calculator C;
    int n = std::min(this->GetSize(), _Polynom.GetSize());
    for (int i = 0; i < n; ++i) {
        C.coeff_a.push_back(coeff_a[i] + _Polynom.coeff_a[i]);
    }
    if (this->GetSize() > n) {
        for (int i = n; i < this->GetSize(); ++i) {
            C.coeff_a.push_back(coeff_a[i]);
        }
    } else {
        for (int i = n; i < _Polynom.GetSize(); ++i) {
            C.coeff_a.push_back(_Polynom.coeff_a[i]);
        }
    }
    return C;
}

polynomial_calculator polynomial_calculator
::operator - (const polynomial_calculator& _Polynom) {
    polynomial_calculator C;
    int n = std::min(this->GetSize(), _Polynom.GetSize());
    for (int i = 0; i < n; ++i) {
        double tmp = coeff_a[i] - _Polynom.coeff_a[i];
        C.coeff_a.push_back(tmp);
    }
    if (this->GetSize() > n) {
        for (int i = n; i < this->GetSize(); ++i) {
            C.coeff_a.push_back(coeff_a[i]);
        }
    } else {
        for (int i = n; i < _Polynom.GetSize(); ++i) {
            C.coeff_a.push_back(-_Polynom.coeff_a[i]);
        }
    }
    return C;
}

polynomial_calculator polynomial_calculator
::operator * (const polynomial_calculator& _Polynom) {
    polynomial_calculator C;
    std::vector<double> A;
    std::vector<double> S;
    std::vector<double> res;
    int n = std::min(this->GetSize(), _Polynom.GetSize());
    int m = std::max(this->GetSize(), _Polynom.GetSize());
    int index = -1;
    if (this->GetSize() > _Polynom.GetSize())
        index = 0;
    else
        index = 1;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (index == 0) {
                double tmp = coeff_a[i] * _Polynom.coeff_a[j];
                A.push_back(tmp);
                S.push_back(i + j);
            } else {
                double tmp = coeff_a[j] * _Polynom.coeff_a[i];
                A.push_back(tmp);
                S.push_back(i + j);
            }
        }
    }
    for (int i = 0; i < n * m; i++) {
        if (S[i] == i) {
            C.coeff_a.push_back(A[i]);
        } else {
            if (S[i] < C.coeff_a.size()) {
                if (S[i] < i)
                    C.coeff_a[S[i]] += A[i];
            } else {
                C.coeff_a.push_back(A[i]);
            }
        }
    }
    return C;
}

polynomial_calculator polynomial_calculator
::operator + (const double& _Num) const {
    if (this->coeff_a.size() == 0) {
        polynomial_calculator C;
        C.coeff_a.push_back(_Num);
        return C;
    } else {
        std::vector<double> a;
        for (int i = this->coeff_a.size() - 1; i >= 0; i--)
            a.push_back(this->coeff_a[i]);
        a[a.size() - 1] += _Num;
        polynomial_calculator C(a, a.size());
        return C;
    }
}

polynomial_calculator polynomial_calculator
::operator - (const double& _Num) const {
    double Num = _Num * (-1.0);
    polynomial_calculator C;
    C = *this + Num;
    return C;
}

polynomial_calculator polynomial_calculator
::operator * (const double& _Num) const {
    std::vector<double> a;
    for (int i = this->coeff_a.size() - 1; i >= 0; i--)
        a.push_back(this->coeff_a[i]*_Num);
    polynomial_calculator C(a, a.size());
    return C;
}
