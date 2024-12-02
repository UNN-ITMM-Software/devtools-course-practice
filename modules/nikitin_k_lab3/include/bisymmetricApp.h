// Copyright 2024 Nikitin Kirill

#pragma once

#include <string>
#include <vector>

#include "include/bisymmetric.h"

class BisymmetricApp {
  BisymmetricMatrix<int> matrix;
  std::vector<std::string> parse(int argc, const char** argv);
  void help(std::vector<std::string>& output);
  void print(std::vector<std::string>& output);
  void initialize(std::vector<std::string>& output);
  void convertSize(std::vector<std::string>& output, int elem);
  void isInside(std::vector<std::string>& output, int elem1, int elem2,
                int elem3);

 public:
  std::vector<std::string> runApp(int argc, const char** argv);
};
