// Copyright 2021 Evgeniy Napylov

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/queue_app.h"

int main(int argc, const char** argv) {
    QueueApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
