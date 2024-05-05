// Copyright 2024 Shubin Mikhail

#pragma once

#ifndef CUSTOM_NS_NUMBER
#define CUSTOM_NS_NUMBER

#include <iostream>
#include <vector>
#include <string>

using digit_t = size_t;
using number_t = int64_t;

class CustomNSNumber {
 protected:
  size_t num_sys = 0;
  std::vector<digit_t> digits;
  bool negative = false;

 public:
  explicit CustomNSNumber(size_t _num_sys = 10) : num_sys(_num_sys) {}
  explicit CustomNSNumber(number_t _number, size_t _num_sys = 10);
  explicit CustomNSNumber(const std::string& _number, size_t _num_sys = 10);
  CustomNSNumber(const CustomNSNumber& _num);
  CustomNSNumber(CustomNSNumber&& _num);
  ~CustomNSNumber() = default;

  void SetNumSys(size_t _num_sys);
  size_t GetNumSys() const noexcept;
  size_t GetLength() const noexcept;
  CustomNSNumber ToNumSys(size_t _num_sys) const;
  number_t ToDec() const noexcept;
  bool IsNegative() const noexcept;

  CustomNSNumber operator+(const CustomNSNumber& _num);
  CustomNSNumber operator-(const CustomNSNumber& _num);
  CustomNSNumber operator*(const CustomNSNumber& _num);

  bool operator==(const CustomNSNumber& _num) const noexcept;
  bool operator!=(const CustomNSNumber& _num) const noexcept;
  bool operator>(const CustomNSNumber& _num) const noexcept;
  bool operator<(const CustomNSNumber& _num) const noexcept;

  digit_t& operator[](size_t ind);
  const digit_t& operator[](size_t ind) const;

  CustomNSNumber& operator=(const CustomNSNumber& _num);
  CustomNSNumber& operator=(CustomNSNumber&& _num);

  friend std::ostream& operator<<(std::ostream& ostr,
                                  const CustomNSNumber& _num) {
    if (_num.negative) {
      ostr << "- ";
    }
    for (size_t i = _num.digits.size(); i > 0; i--) {
      ostr << _num.digits[i - 1] << ' ';
    }
    ostr << "_" << _num.num_sys;
    return ostr;
  }
};

#endif
