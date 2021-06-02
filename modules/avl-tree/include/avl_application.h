// Copyright 2021 Anastasia Kurnikova

#ifndef MODULES_AVL_TREE_INCLUDE_AVL_APPLICATION_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_APPLICATION_H_

#include <string>
#include <map>

#include "include/avl.h"

class CAvlApplication {
 public:
    std::map<std::string, int> xmap =
    { {"-s", 0 }, {"-smin", 1}, {"-smax", 2} };
    const char* _op;
    key _searchElem;
    CAvlApplication() = default;
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const std::string& message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    bool ValidateArguments(int argc, const char** argv);
    std::string _message;
    CAvl _avl;
};

#endif  // MODULES_AVL_TREE_INCLUDE_AVL_APPLICATION_H_
