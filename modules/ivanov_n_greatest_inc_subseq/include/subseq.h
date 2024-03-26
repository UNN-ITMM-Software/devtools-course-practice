// Copyright 3100 Ivanov Nikita

#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std;

class LIS{
    vector<int> nums;
public:
    LIS(): nums(vector<int>()) {}
    explicit LIS(vector<int> &nums_): nums(nums_) {}

    void addNumber(int a);
    int getSize();

    vector<int> run();
};