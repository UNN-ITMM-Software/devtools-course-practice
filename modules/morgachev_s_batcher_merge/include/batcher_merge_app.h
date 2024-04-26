// Copyright 2024 Chuvashov Andrey

#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "../include/batcher_merge.h"

class BatcherMergeApplication {
 private:
    std::string returnMessage;
    std::vector<int> array;
    void help(const char* appName, const char* errorMessage = nullptr);
    bool validate(int argc, char* argv[]);
 public:
    BatcherMergeApplication() = default;
    std::string Sort(int argc, char* argv[]);
};
