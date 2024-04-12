// Copyright 2024 Kulaev Zhenya
#pragma once

#include <algorithm>
#include <vector>
#include <random>

void streaching(std::vector<int>& image, int old_min,
    int old_max, int new_min, int new_max);

void increase_contrast(std::vector<int>& image, size_t m, size_t n,
    int new_min, int new_max);
