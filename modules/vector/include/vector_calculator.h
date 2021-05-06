// Copyright 2021 Shagov Maksim

#ifndef MODULES_VECTOR_INCLUDE_VECTOR_CALCULATOR_H_
#define MODULES_VECTOR_INCLUDE_VECTOR_CALCULATOR_H_

#include <string>
#include "include/vector.h"

class VectorCalculator {
 public:
    VectorCalculator();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    struct Arguments {
        Vector v_1;
        Vector v_2;
        char operation;
    };
};

#endif  // MODULES_VECTOR_INCLUDE_VECTOR_CALCULATOR_H_
