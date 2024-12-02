// Copyright 2024 Fedotov Kirill

#include "include/set.h"

Set::Set() {}

// Constructor from string representation
Set::Set(const std::string& str) {
  // Remove { and }
  std::string cleaned = str.substr(1, str.length() - 2);
  std::stringstream ss(cleaned);
  std::string token;

  while (std::getline(ss, token, ',')) {
    if (!token.empty()) {
      int num = std::stoi(token);
      add(num);
    }
  }
}

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

std::string Set::toString() const {
  std::stringstream ss;
  ss << "{";
  for (size_t i = 0; i < elements.size(); ++i) {
    ss << elements[i];
    if (i < elements.size() - 1) {
      ss << ",";
    }
  }
  ss << "}";
  return ss.str();
}
