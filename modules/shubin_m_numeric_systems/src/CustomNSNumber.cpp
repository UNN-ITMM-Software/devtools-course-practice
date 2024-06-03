// Copyright 2024 Shubin Mikhail

#include <stdexcept>
#include <sstream>
#include "include/CustomNSNumber.hpp"

CustomNSNumber::CustomNSNumber(number_t _number, size_t _num_sys) {
  if (_num_sys < 2) {
    throw std::invalid_argument("Incorrect numeric system");
  }

  num_sys = _num_sys;

  number_t tmp = _number;
  number_t number_t_num_sys = static_cast<number_t>(_num_sys);

  if (tmp < 0) {
    tmp *= -1;
    negative = true;
  }

  while (tmp > 0) {
    digits.push_back(tmp % number_t_num_sys);
    tmp = tmp / number_t_num_sys;
  }

  if (digits.size() == 0) {
    digits.push_back(0);
  }
}

CustomNSNumber::CustomNSNumber(const CustomNSNumber& _num) {
  num_sys = _num.num_sys;
  negative = _num.negative;
  digits = _num.digits;
}

CustomNSNumber::CustomNSNumber(CustomNSNumber&& _num) {
  num_sys = _num.num_sys;
  negative = _num.negative;
  digits = std::move(_num.digits);

  _num.num_sys = 0;
  _num.negative = false;
}

CustomNSNumber::CustomNSNumber(const std::string &_number, size_t _num_sys) {
  std::string tmp_string = _number;
  if (_num_sys < 2) {
    throw std::invalid_argument("Incorrect numeric system");
  }
  if (_number.empty()) {
    throw std::invalid_argument("Input string is empty");
  }
  num_sys = _num_sys;
  if (_number[0] == '-') {
    negative = true;
    tmp_string.erase(0, 2);
  } else {
      negative = false;
  }

  std::vector<digit_t> tmp_vector;
  std::istringstream iss(tmp_string);
  std::string s;

  while (getline(iss, s, ' ')) {
    try {
      tmp_vector.push_back(std::stoul(s));
    } catch (...) {
      throw std::invalid_argument("Incorrect string element");
    }
  }

  for (size_t i = tmp_vector.size(); i > 0; i--) {
    if (_num_sys > tmp_vector[i - 1]) {
      digits.push_back(tmp_vector[i - 1]);
    } else {
      throw std::invalid_argument("Incorrect digit");
    }
  }
}

void CustomNSNumber::SetNumSys(size_t _num_sys) {
  if (_num_sys < 2) {
    throw std::invalid_argument("Incorrect numeric system");
  }

  CustomNSNumber res = CustomNSNumber(_num_sys);
  digit_t temp_number = digits[digits.size() - 1];
  digit_t digit_t_num_sys = static_cast<digit_t>(num_sys);
  digit_t digit_t__num_sys = static_cast<digit_t>(_num_sys);

  for (size_t i = 0; i < digits.size() - 1; i++) {
    temp_number *= digit_t_num_sys;
  }
  while (temp_number > 0) {
    res.digits.push_back(temp_number % digit_t__num_sys);
    temp_number = temp_number / digit_t__num_sys;
  }
  for (size_t i = digits.size() - 1; i > 0; i--) {
    temp_number = digits[i - 1];
    for (size_t j = 0; j < i - 1; j++) {
      temp_number *= digit_t_num_sys;
    }
    size_t k = 0;
    while (temp_number > 0) {
      res.digits[k] += temp_number % digit_t__num_sys;
      temp_number = temp_number / digit_t__num_sys;
      k++;
    }
  }
  digit_t move_digit = 0;
  for (size_t i = 0; i < res.digits.size(); i++) {
    temp_number = res.digits[i] + move_digit;
    res.digits[i] = temp_number % digit_t__num_sys;
    move_digit = temp_number / digit_t__num_sys;
  }
  if (move_digit > 0) {
    res.digits.push_back(move_digit);
  }

  num_sys = res.num_sys;
  digits = res.digits;

  if (digits.size() == 0) {
    digits.push_back(0);
  }
}

size_t CustomNSNumber::GetNumSys() const noexcept {
  return num_sys;
}

size_t CustomNSNumber::GetLength() const noexcept {
  return digits.size();
}

CustomNSNumber CustomNSNumber::ToNumSys(size_t _num_sys) const {
  if (_num_sys < 2) {
    throw std::invalid_argument("Incorrect numeric system");
  }

  CustomNSNumber res = CustomNSNumber(_num_sys);
  digit_t temp_number = digits[digits.size() - 1];
  digit_t digit_t_num_sys = static_cast<digit_t>(num_sys);
  digit_t digit_t__num_sys = static_cast<digit_t>(_num_sys);

  for (size_t i = 0; i < digits.size() - 1; i++) {
    temp_number *= digit_t_num_sys;
  }
  while (temp_number > 0) {
    res.digits.push_back(temp_number % digit_t__num_sys);
    temp_number = temp_number / digit_t__num_sys;
  }
  for (size_t i = digits.size() - 1; i > 0; i--) {
    temp_number = digits[i - 1];
    for (size_t j = 0; j < i - 1; j++) {
      temp_number *= digit_t_num_sys;
    }
    size_t k = 0;
    while (temp_number > 0) {
      res.digits[k] += temp_number % digit_t__num_sys;
      temp_number = temp_number / digit_t__num_sys;
      k++;
    }
  }

  digit_t move_digit = 0;
  for (size_t i = 0; i < res.digits.size(); i++) {
    temp_number = res.digits[i] + move_digit;
    res.digits[i] = temp_number % digit_t__num_sys;
    move_digit = temp_number / digit_t__num_sys;
  }
  if (move_digit > 0) {
    res.digits.push_back(move_digit);
  }

  res.negative = negative;

  if (res.digits.size() == 0) {
    res.digits.push_back(0);
  }

  return res;
}

number_t CustomNSNumber::ToDec() const noexcept {
  number_t res = 0;

  number_t temp_number = 0;
  number_t number_t_num_sys = static_cast<number_t>(num_sys);
  for (size_t i = 0; i < digits.size(); i++) {
    temp_number = static_cast<number_t>(digits[i]);
    for (size_t j = 0; j < i; j++) {
      temp_number *= number_t_num_sys;
    }
    res += temp_number;
  }

  if (negative) {
    res *= -1;
  }

  return res;
}

bool CustomNSNumber::IsNegative() const noexcept {
  return negative;
}

CustomNSNumber CustomNSNumber::operator+(const CustomNSNumber& _num) {
  if (num_sys != _num.num_sys) {
    throw std::invalid_argument("Numeric systems don't match");
  }

  CustomNSNumber res = CustomNSNumber(num_sys);
  CustomNSNumber temp = _num;
  digit_t digit_t_num_sys = static_cast<digit_t>(res.num_sys);

  if (negative == _num.negative) {
    res.negative = negative;
    digit_t temp_number = 0;
    digit_t move_digit = 0;
    for (size_t i = 0; i < std::max(digits.size(), temp.digits.size()); i++) {
      temp_number = ((i < digits.size()) ? (digits[i]) : (0)) +
                    ((i < temp.digits.size()) ? (temp.digits[i]) : (0)) +
                    move_digit;
      res.digits.push_back(temp_number % digit_t_num_sys);
      move_digit = temp_number / digit_t_num_sys;
    }
    if (move_digit > 0) {
      res.digits.push_back(move_digit);
    }
  } else {
    temp.negative = negative;
    res.negative = (temp > *this) ? (!(negative)) : (negative);
    digit_t temp_number = 0;
    digit_t this_number = 0;
    digit_t other_number = 0;
    digit_t move_digit = 0;
    for (size_t i = 0; i < std::max(digits.size(), temp.digits.size()); i++) {
      this_number = (i < digits.size()) ? (digits[i]) : (0);
      other_number = (i < temp.digits.size()) ? (temp.digits[i]) : (0);
      temp_number = digit_t_num_sys + ((res.negative == negative) ?
                    (this_number - other_number) :
                    (other_number - this_number)) - move_digit;
      res.digits.push_back(temp_number % digit_t_num_sys);
      move_digit = (temp_number / digit_t_num_sys >= 1) ? (0) : (1);
    }
  }

  digit_t temp_number = 0;
  digit_t move_digit = 0;
  for (size_t i = 0; i < res.digits.size(); i++) {
    temp_number = res.digits[i] + move_digit;
    res.digits[i] = temp_number % digit_t_num_sys;
    move_digit = temp_number / digit_t_num_sys;
  }
  if (move_digit > 0) {
    res.digits.push_back(move_digit);
  }

  if (res.digits.size() == 0) {
    res.digits.push_back(0);
  }

  return res;
}

CustomNSNumber CustomNSNumber::operator-(const CustomNSNumber& _num) {
  if (num_sys != _num.num_sys) {
    throw std::invalid_argument("Numeric systems don't match");
  }

  CustomNSNumber res = CustomNSNumber(num_sys);
  CustomNSNumber temp = _num;
  digit_t digit_t_num_sys = static_cast<digit_t>(res.num_sys);

  if (negative != _num.negative) {
    res.negative = negative;
    digit_t temp_number = 0;
    digit_t move_digit = 0;
    for (size_t i = 0; i < std::max(digits.size(), temp.digits.size()); i++) {
      temp_number = ((i < digits.size()) ? (digits[i]) : (0)) +
                    ((i < temp.digits.size()) ? (temp.digits[i]) : (0)) +
                    move_digit;
      res.digits.push_back(temp_number % digit_t_num_sys);
      move_digit = temp_number / digit_t_num_sys;
    }
    if (move_digit > 0) {
      res.digits.push_back(move_digit);
    }
  } else {
    res.negative = (temp > *this) ? (true) : (false);
    digit_t temp_number = 0;
    digit_t this_number = 0;
    digit_t other_number = 0;
    digit_t move_digit = 0;
    for (size_t i = 0; i < std::max(digits.size(), temp.digits.size()); i++) {
      this_number = (i < digits.size()) ? (digits[i]) : (0);
      other_number = (i < temp.digits.size()) ? (temp.digits[i]) : (0);
      temp_number = digit_t_num_sys + ((res.negative == negative) ?
                    (this_number - other_number) :
                    (other_number - this_number)) - move_digit;
      res.digits.push_back(temp_number % digit_t_num_sys);
      move_digit = (temp_number / digit_t_num_sys >= 1) ? (0) : (1);
    }
  }

  digit_t temp_number = 0;
  digit_t move_digit = 0;
  for (size_t i = 0; i < res.digits.size(); i++) {
    temp_number = res.digits[i] + move_digit;
    res.digits[i] = temp_number % digit_t_num_sys;
    move_digit = temp_number / digit_t_num_sys;
  }
  if (move_digit > 0) {
    res.digits.push_back(move_digit);
  }

  if (res.digits.size() == 0) {
    res.digits.push_back(0);
  }

  return res;
}

CustomNSNumber CustomNSNumber::operator*(const CustomNSNumber& _num) {
  if (num_sys != _num.num_sys) {
    throw std::invalid_argument("Numeric systems don't match");
  }

  CustomNSNumber res = CustomNSNumber(num_sys);
  CustomNSNumber temp = _num;
  digit_t digit_t_num_sys = static_cast<digit_t>(res.num_sys);

  if (negative != _num.negative) {
    res.negative = true;
  } else {
    res.negative = false;
  }

  digit_t temp_number = 0;
  digit_t move_digit = 0;
  for (size_t i = 0; i < temp.digits.size(); i++) {
    for (size_t j = 0; j < digits.size(); j++) {
      temp_number = temp.digits[i] * digits[j] + move_digit;
      if (i + j < res.digits.size()) {
        res.digits[i + j] += temp_number % digit_t_num_sys;
      } else {
        res.digits.push_back(temp_number % digit_t_num_sys);
      }
      move_digit = temp_number / digit_t_num_sys;
    }
    if (move_digit > 0) {
      res.digits.push_back(move_digit);
      move_digit = 0;
    }
  }

  for (size_t i = 0; i < res.digits.size(); i++) {
    temp_number = res.digits[i] + move_digit;
    res.digits[i] = temp_number % digit_t_num_sys;
    move_digit = temp_number / digit_t_num_sys;
  }
  if (move_digit > 0) {
    res.digits.push_back(move_digit);
  }

  if (res.digits.size() == 0) {
    res.digits.push_back(0);
  }

  return res;
}

bool CustomNSNumber::operator==(const CustomNSNumber& _num) const noexcept {
  return (ToDec() == _num.ToDec());
}

bool CustomNSNumber::operator!=(const CustomNSNumber& _num) const noexcept {
  return (ToDec() != _num.ToDec());
}

bool CustomNSNumber::operator<(const CustomNSNumber& _num) const noexcept {
  return (ToDec() < _num.ToDec());
}

bool CustomNSNumber::operator>(const CustomNSNumber& _num) const noexcept {
  return (ToDec() > _num.ToDec());
}

digit_t& CustomNSNumber::operator[](size_t ind) {
  return digits[ind];
}

const digit_t& CustomNSNumber::operator[](size_t ind) const {
  return digits[ind];
}

CustomNSNumber& CustomNSNumber::operator=(const CustomNSNumber& _num) {
  if (this != &_num) {
    num_sys = _num.num_sys;
    negative = _num.negative;
    digits = _num.digits;
  }

  return *this;
}

CustomNSNumber& CustomNSNumber::operator=(CustomNSNumber&& _num) {
  if (this != &_num) {
    num_sys = _num.num_sys;
    negative = _num.negative;
    digits = std::move(_num.digits);

    _num.num_sys = 0;
    _num.negative = false;
  }

  return *this;
}
