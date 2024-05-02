// Copyright 2024 Zhatkin Vyacheslav 

#pragma once

#include <string>

#include "include/sort_station.h"

class SortStationApp {
public:
    SortStationApp() = default;

    std::string operator()(int argc, char* argv[]);

private:
    std::string message_;
    SortStationDerived sortStation;

    bool validate(int argc, char* argv[]);

    void help(const char* appName, const char* msg = nullptr);
};
