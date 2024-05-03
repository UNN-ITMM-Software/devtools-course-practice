// Copyright 2024 Vasilev Ivan

#pragma once
#include <vector>

void combinationsUtil(const std::vector<int>& arr, size_t n, int k, int index,
    std::vector<int>& data, int i,
    std::vector<std::vector<int>>& result);

std::vector<std::vector<int>> generateCombinations
(const std::vector<int>& arr, int k);

