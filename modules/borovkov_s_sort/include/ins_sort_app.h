// Copyright 2024 Soloninko Andrey
#pragma once

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/insertion_sort.h"

class SortApp {
 public:
    SortApp() = default;
    std::string sort_application(int argc, char* argv[]);
 private:
    std::string sortMsg{};
    std::vector<int> test;
    bool validate(int argc, char *argv[]);
    void help(const char *appName, const char *msg = nullptr);
};
