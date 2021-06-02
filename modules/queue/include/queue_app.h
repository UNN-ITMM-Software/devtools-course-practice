// Copyright 2021 Evgeniy Napylov

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_APP_H_

#include <string>
#include "include/queue.h"

class QueueApp {
 public:
    QueueApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    Queue queue;
};

#endif  // MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
