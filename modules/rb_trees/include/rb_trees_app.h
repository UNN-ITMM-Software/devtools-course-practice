// Copyright 2021 Kirichenko Nikita

#ifndef MODULES_RB_TREES_INCLUDE_RB_TREES_APP_H_
#define MODULES_RB_TREES_INCLUDE_RB_TREES_APP_H_

#include <string>

#include <sstream>

#include "include/rb_trees.h"

class RBTreeApp {
 public:
    RBTreeApp() = default;
    std::string operator()(int argc, const char** argv);
 private:
    std::string Help(const char* appname);
    int ParseOperation(const char** argv);
    int ParseNumber(const char* s);
    RBTree t_;
    std::stringstream out_;
};

#endif  // MODULES_RB_TREES_INCLUDE_RB_TREES_APP_H_
