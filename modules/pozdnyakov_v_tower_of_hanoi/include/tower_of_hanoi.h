// Copyright 2024 Pozdnyakov Vasya

#ifndef MODULES_POZDNYAKOV_V_TOWER_OF_HANOI_INCLUDE_TOWER_OF_HANOI_H_
#define MODULES_POZDNYAKOV_V_TOWER_OF_HANOI_INCLUDE_TOWER_OF_HANOI_H_

#include <vector>
#include <stdexcept>

class TowerOfHanoi {
 protected:
    static std::vector<std::vector<int>> RecursiveCalculate(int n,
     int from, int to);
 public:
    static std::vector<std::vector<int>> CalculateSteps(int n);
};

#endif  // MODULES_POZDNYAKOV_V_TOWER_OF_HANOI_INCLUDE_TOWER_OF_HANOI_H_
