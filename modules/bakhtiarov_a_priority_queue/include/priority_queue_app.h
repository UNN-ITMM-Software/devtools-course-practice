// Copyright 2024 Fedotov Kirill

#pragma once

#include <string>
#include <utility>

#include "include/priority_queue.h"

class PriorityQueueApplication {
 private:
    std::string msg;
    TQueue_insert<int> queue;
    bool Validate(int argc, char* argv[]);
    void Help(const char* application, const char* errMsg = nullptr);

 public:
    PriorityQueueApplication() = default;
    std::string ProcessQueueOperations(int argc, char* argv[]);
    std::string ProcessMultipleOperations(int argc, char *argv[]);
};
