// Copyright 2024 Pozdnyakov Vasya

#ifndef MODULES_POZDNYAKOV_V_TOWER_OF_HANOI_INCLUDE_TOWER_OF_HANOI_H_
#define MODULES_POZDNYAKOV_V_TOWER_OF_HANOI_INCLUDE_TOWER_OF_HANOI_H_

#include <stdexcept>
#include <string>
#include <vector>

class TowerOfHanoi {
 public:
  TowerOfHanoi() = default;
  std::string GetStepsAsString(const std::vector<std::vector<int>>& steps);

 protected:
  std::vector<std::vector<int>> RecursiveCalculate(int numberOfRings,
                                                   int fromRod, int toRod);

 public:
  std::vector<std::vector<int>> CalculateSteps(int numberOfRings);
};

#endif  // MODULES_POZDNYAKOV_V_TOWER_OF_HANOI_INCLUDE_TOWER_OF_HANOI_H_
