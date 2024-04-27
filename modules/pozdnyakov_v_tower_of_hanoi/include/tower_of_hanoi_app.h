// Copyright 2024 Shmelev Ivan

#pragma once

#include <string>

#include "include/tower_of_hanoi.h"

class TowerOfHanoiApplication {
 private:
    std::string msg;
    TowerOfHanoi tower;
    bool Validate(int argc, char* argv[]);
    void Help(const char* application, const char* errMsg = nullptr);
 public:
    TowerOfHanoiApplication() = default;
    std::string TowerOfHanoiCount(int argc, char* argv[]);
};
