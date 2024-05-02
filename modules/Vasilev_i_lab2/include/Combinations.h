// Copyright 2024 Vasilev Ivan
#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <algorithm>


namespace KCombinations {
void combinationsUtil(const std::vector<int>& arr, int n, int k, int index,
                      std::vector<int>& data, int i,
                      std::vector<std::vector<int>>& result) {
    if (index == k) {
        result.push_back(data);
        return;
    }
    if (i >= n) {
        return;
    }
    data[index] = arr[i];
    combinationsUtil(arr, n, k, index + 1, data, i + 1, result);
    combinationsUtil(arr, n, k, index, data, i + 1, result);
}

std::vector<std::vector<int> >generateCombinations
(const std::vector<int>& arr, int k) {
    std::vector<std::vector<int>> result;
    int n = arr.size();
    std::vector<int> data(k);
    combinationsUtil(arr, n, k, 0, data, 0, result);
    return result;
}

}  // namespace KCombinations
