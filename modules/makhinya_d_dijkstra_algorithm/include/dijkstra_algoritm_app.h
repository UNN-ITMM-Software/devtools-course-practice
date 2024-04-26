// Copyright 2024 Safarov Nurlan
#pragma once

#include <vector>
#include <cstdint>
#include <array>
#include <limits>
#include <stdexcept>
#include <queue>
#include <iostream>
#include <string>

#include "include/dijkstra_algoritm.h"
/*
class DijkstraAlgorithmApp {
 public:
  DijkstraAlgorithmApp() = default;
  std::string dijkstra_algorithm_application(int argc, char* argv[]);

 private:
  std::string DijkstraAlgorithmMsg{};
  Solver<15> obj;
  bool validate(int argc, char* argv[]);
  void help(char* appName, char* msg = nullptr);
};*/

class DijkstraAlgorithmApp {
 public:
    DijkstraAlgorithmApp() = default;
    std::string dijkstra_algorithm_application(int argc, char* argv[]);
 private:
    bool validate(int argc, char* argv[]);
    void help(const char *appName, const char *msg = nullptr);
    std::string DijkstraAlgorithmMsg;
    Solver<15> obj;
};
