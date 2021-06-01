// Copyright 2021 Novozhilova Ekaterina

#ifndef MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_OPERATIONS_APP_H_
#define MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_OPERATIONS_APP_H_

#include <string>
#include <vector>
#include "include/matrix_operations.h"

class MyApplication {
 public:
    MyApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string parseOperation(const char* arg);
    std::string parseSecondType(const char* arg);
    std::string message_;
};



#endif  // MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_OPERATIONS_APP_H_
