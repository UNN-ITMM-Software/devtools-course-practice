// Copyright 2024 Pozdnyakov Vasya

#pragma once

#include <string>
#include <vector>

#include "include/radix_sort.h"

class RadixSortApplication {
 private:
    std::string returnMsg;
    std::vector<int> array;
    bool order = true;
    bool Validate(int argc, char* argv[]);
    void Help(const char* appName, const char* errorMsg = nullptr);
 public:
    RadixSortApplication() = default;
    std::string Sort(int argc, char* argv[]);
};

