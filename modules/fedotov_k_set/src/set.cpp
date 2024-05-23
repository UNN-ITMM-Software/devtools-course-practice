// Copyright 2024 Fedotov Kirill

#include "include/set.h"

Set::Set() {}

void Set::add(int element) {
  if (!contains(element)) {
    elements.push_back(element);
  }
}

void Set::remove(int element) {
  auto it = std::find(elements.begin(), elements.end(), element);
  if (it != elements.end()) {
    elements.erase(it);
  }
}

bool Set::contains(int element) const {
  return std::find(elements.begin(), elements.end(), element) != elements.end();
}

Set Set::unionWith(const Set& other) const {
  Set result = *this;
  for (int elem : other.elements) {
    result.add(elem);
  }
  return result;
}

Set Set::intersectWith(const Set& other) const {
  Set result;
  for (int elem : elements) {
    if (other.contains(elem)) {
      result.add(elem);
    }
  }
  return result;
}

void Set::print() const {
  std::cout << "{ ";
  for (int elem : elements) {
    std::cout << elem << " ";
  }
  std::cout << "}" << std::endl;
}