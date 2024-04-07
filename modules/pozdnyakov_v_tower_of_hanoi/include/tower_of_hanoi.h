// Copyright 2024 Pozdnyakov Vasya

#include <vector>
#include <stdexcept>

class TowerOfHanoi {
 protected:
    static std::vector<std::vector<int>> RecursiveCalculate(int n, int from, int to);
 public:
    static std::vector<std::vector<int>> CalculateSteps(int n);
};
