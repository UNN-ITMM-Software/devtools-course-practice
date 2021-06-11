// Copyright 2021 Panova Olga

#ifndef MODULES_3D_SEARCH_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAM_APP_H_
#define MODULES_3D_SEARCH_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAM_APP_H_

#include <string>
#include "include/search-graph-diameter.h"

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    struct Arguments {
        int n;
        list l;
    };
};

#endif  // MODULES_3D_SEARCH_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAM_APP_H_
