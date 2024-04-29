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

class DijkstraAlgorithmApp {
 public:
    std::string dijkstra_algorithm_application(int argc, char* argv[]);
 private:
    Solver<20> obj;

    bool validate(int argc, char* argv[]);
    std::string help(const char* application, int check_code);
    std::string dijkstra_algorithm_msg;
};
