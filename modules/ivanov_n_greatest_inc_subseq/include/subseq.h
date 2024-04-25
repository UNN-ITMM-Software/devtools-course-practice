// Copyright 2024 Ivanov Nikita

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cstdlib>
#include <ctime>


/**
 * @brief Longest increasing subsequence
 */
class LIS{
    std::vector<int> nums;
 public:
    LIS(): nums() {}
    explicit LIS(const std::vector<int> &nums_): nums(nums_) {}

    void addNumber(int a);
    size_t getSize();

    std::vector<int> run();
};
