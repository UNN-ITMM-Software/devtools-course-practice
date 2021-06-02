// Copyright 2021 Tkachev Alexey

#ifndef MODULES_CONNECTIVITY_COMPONENTS_INCLUDE_APP_CONNECTIVITY_COMPONENTS_H_
#define MODULES_CONNECTIVITY_COMPONENTS_INCLUDE_APP_CONNECTIVITY_COMPONENTS_H_

#include <string>

#include "include/connectivity_components.h"

class AppConnComponents {
 private:
  std::string response;
  Graph graph;

 public:
    AppConnComponents();
    static std::string help();
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_CONNECTIVITY_COMPONENTS_INCLUDE_APP_CONNECTIVITY_COMPONENTS_H_
