// Copyright 2024 Kachalov Mikhail

#pragma once

#include <string>
#include <vector>

class StatisticsApp {
 public:
    StatisticsApp();
    std::string operator()(int argc, char* argv[]) const;
 private:
    std::vector<float> ParseData(int argc, char* argv[], int startIndex) const;
};
