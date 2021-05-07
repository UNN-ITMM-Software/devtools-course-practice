// Copyright 2021 Anastasia Kurnikova

#ifndef MODULES_AVL_TREE_INCLUDE_AVL_APPLICATION_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_APPLICATION_H_

#include <string>
#include <map>

#include "include/avl.h"

enum class etOperation {
    eSEARCH_ELEMENT = 0,
    eSEARCH_MAX_ELEMENT = 1,
    eSEARCH_MIN_ELEMENT = 2
};

static struct responseHeaderMap : public std::map<std::string, etOperation> {
    responseHeaderMap() {
        this->operator[]("-s") = etOperation::eSEARCH_ELEMENT;
        this->operator[]("-smin") = etOperation::eSEARCH_MIN_ELEMENT;
        this->operator[]("-smax") = etOperation::eSEARCH_MAX_ELEMENT;
    }
    ~responseHeaderMap() {}
} xmap;

class CAvlApplication {
 public:
    const char* op;
    key searchElem;
    CAvlApplication() = default;
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const std::string& message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    bool ValidateArguments(int argc, const char** argv);
    std::string _message;
    CAvl avl;
};

#endif  // MODULES_AVL_TREE_INCLUDE_AVL_APPLICATION_H_
