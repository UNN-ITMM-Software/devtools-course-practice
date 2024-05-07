// Copyright 2024 Dostavalov Semyon

#ifndef MODULES_KOCHETOV_N_DJARVIS_INCLUDE_DJARVIS_APP_H_
#define MODULES_KOCHETOV_N_DJARVIS_INCLUDE_DJARVIS_APP_H_

#include "include/djarvis.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class Application {
 public:
    Application() = default;

    std::string run(std::vector<std::string>& args);
};

#endif  // MODULES_KOCHETOV_N_DJARVIS_INCLUDE_DJARVIS_APP_H_

