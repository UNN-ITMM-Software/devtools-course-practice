// Copyright 2021 Alibekov Murad

#ifndef MODULES_DIJKSTRAS_ALGORITHM_INCLUDE_DIJKSTRAS_ALGORITHM_APP_H_
#define MODULES_DIJKSTRAS_ALGORITHM_INCLUDE_DIJKSTRAS_ALGORITHM_APP_H_

#include <string>
#include <vector>

class Application {
 public:
    Application();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    struct Arguments {
        int N;
        int source_vertex;
        std::vector<double> graph;
    };
};

#endif  // MODULES_DIJKSTRAS_ALGORITHM_INCLUDE_DIJKSTRAS_ALGORITHM_APP_H_
