// Copyright 2021 Kolesin Andrey

#ifndef MODULES_RADIX_SORT_INCLUDE_APPLICATION_H_
#define MODULES_RADIX_SORT_INCLUDE_APPLICATION_H_

#include <vector>
#include <string>

#include "include/radix_sort.h"

class Application {
    std::vector<int> arr;
    std::string help(const char* appname);
 public:
    static const char NOT_INTEGER[];
    static const char OUT_OF_RANGE[];
    Application();
    std::vector<int> getArr() const;
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_RADIX_SORT_INCLUDE_APPLICATION_H_
