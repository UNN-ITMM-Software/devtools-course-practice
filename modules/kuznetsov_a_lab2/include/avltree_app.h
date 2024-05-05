// Copyright 2024 Nogin Denis
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "include/avltree.h"

class AvlTreeApplication {
  enum class Option { INSERT, REMOVE, FIND };

 private:
  avlTree<int> tree{};
  std::string hullMessage{};
  Option argument{};
  bool validate(int argc, char *argv[]);
  void help(const char *appName, const char *msg = nullptr);

 public:
  AvlTreeApplication() = default;
  std::string operator()(int argc, char *argv[]);
};
