// Copyright 2021 Bezrodnov Dmitry

#ifndef MODULES_HANOI_TOWER_INCLUDE_HANOI_APPLICATION_H_
#define MODULES_HANOI_TOWER_INCLUDE_HANOI_APPLICATION_H_

#include <string>
#include "include/hanoi_tower.h"

class HanoiApplication {
 public:
    std::string operator()(int argc, const char** argv);

 private:
    std::string help(const std::string& appname);
    int parseArgument(const char* arg);
    bool CheckArgument(const std::string& str);
};

#endif  // MODULES_HANOI_TOWER_INCLUDE_HANOI_APPLICATION_H_
