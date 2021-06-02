// Copyright 2021 Yurin Stanislav

#ifndef MODULES_WAVE_ALGORITHM_INCLUDE_APPLICATION_H_
#define MODULES_WAVE_ALGORITHM_INCLUDE_APPLICATION_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <utility>

namespace WaveLib {
using Point = std::pair<int, int>;
class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int mapHeight;
        int mapWidth;
        std::vector<int> map;
        Point start;
        Point finish;
    } Arguments;
};
}  // namespace WaveLib

#endif  // MODULES_WAVE_ALGORITHM_INCLUDE_APPLICATION_H_
