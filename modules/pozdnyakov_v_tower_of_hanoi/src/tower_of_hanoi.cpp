// Copyright 2024 Pozdnyakov Vasya

#include "include/tower_of_hanoi.h"
#include <sstream>
#include <iostream>

#define SUM_OF_RODS_NUMBERS 6
#define START_ROD 1
#define END_ROD 3

std::vector<std::vector<int>> TowerOfHanoi::RecursiveCalculate
    (int numberOfRings, int fromRod, int toRod) {
    if ((fromRod < START_ROD && fromRod > END_ROD)
    || (toRod < START_ROD && toRod > END_ROD)) {
        throw std::range_error("Number of rods must be 1, 2 or 3");
    }

    if (numberOfRings == 1) {
        return std::vector<std::vector<int>>(1, {fromRod, toRod});
    }

    int unused = SUM_OF_RODS_NUMBERS - fromRod - toRod;

    std::vector<std::vector<int>> localResult =
        RecursiveCalculate(numberOfRings - 1, fromRod, unused);
    localResult.push_back({fromRod, toRod});
    std::vector<std::vector<int>> secondRecursiveResult =
        RecursiveCalculate(numberOfRings - 1, unused, toRod);
    localResult.insert(localResult.end(),
    secondRecursiveResult.begin(), secondRecursiveResult.end());

    return localResult;
}

std::vector<std::vector<int>> TowerOfHanoi::CalculateSteps(int numberOfRings) {
    if (numberOfRings <= 0) {
        throw std::range_error("Number of rings must be positive");
    }

    return RecursiveCalculate(numberOfRings, START_ROD, END_ROD);
}

std::string TowerOfHanoi::GetStepsAsString
(const std::vector<std::vector<int>>& steps) {
    std::stringstream ss;
    for (const auto& step : steps) {
        ss << "Move from " << step[0] << " to " << step[1] << std::endl;
    }
    return ss.str();
}
