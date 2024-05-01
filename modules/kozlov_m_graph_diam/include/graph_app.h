// Copyright 2024 Troitskiy Alexander
#ifndef MODULES_KOZLOV_M_GRAPH_DIAM_INCLUDE_GRAPH_H_
#define MODULES_KOZLOV_M_GRAPH_DIAM_INCLUDE_GRAPH_H_

#include <string>
#include <stdexcept>

#include "include/graph.h"

class Graph_app {
public:
    Graph_app() = default;

    std::string operator()(int argc, const char **argv);

private:
    void help(const char *appname, const char *message = "");
    bool validateNumberOfArguments(int argc, const char **argv);
    std::string message_;
};

#endif // MODULES_KOZLOV_M_GRAPH_DIAM_INCLUDE_GRAPH_H_
