// Copyright 2024 Safarov Nurlan
#pragma once

#include <array>
#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/dijkstra_algoritm.h"

class DijkstraAlgorithmApp {
 public:
  std::string dijkstra_algorithm_application(int argc, char* argv[]);

 private:
  Solver<20> obj;

  bool validate(int argc, char* argv[]);
  std::string help(const char* application, int check_code);
  std::string dijkstra_algorithm_msg;
};
