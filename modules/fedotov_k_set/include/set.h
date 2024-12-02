// Copyright 2024 Fedotov Kirill
#ifndef MODULES_FEDOTOV_K_SET_INCLUDE_SET_H_
#define MODULES_FEDOTOV_K_SET_INCLUDE_SET_H_

#include <algorithm>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class Set {
 private:
  std::vector<int> elements;

 public:
  Set();
  Set(const std::string& str);

  void add(int element);
  void remove(int element);
  bool contains(int element) const;
  Set unionWith(const Set& other) const;
  Set intersectWith(const Set& other) const;
  void print() const;
  std::string toString() const;
};

#endif  // MODULES_FEDOTOV_K_SET_INCLUDE_SET_H_
