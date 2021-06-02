// Copyright 2021 Gurylev Nikita

#ifndef MODULES_PQUEUE_INCLUDE_PQUEUE_APPLICATION_H_
#define MODULES_PQUEUE_INCLUDE_PQUEUE_APPLICATION_H_

#include <string>

#include "include/Pqueue.h"

class PriorityApp {
 public:
    PriorityApp() = default;
    std::string operator()(int argc, const char** argv);
 private:
    PQueue q;
    std::string message_;
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    int ParseOperation(const char** s);
};

#endif  // MODULES_PQUEUE_INCLUDE_PQUEUE_APPLICATION_H_
