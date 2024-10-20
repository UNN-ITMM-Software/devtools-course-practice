// Copyright 2024 Kudinov Nikita
#pragma once

#include <string>

#include "include/KMP.h"

class KMPApplication {
 public:
  KMPApplication() = default;
  std::string operator()(int argc, char* argv[]);

 private:
  std::string outputMessage;
  bool validate(int argc, char* argv[]);
  void help(const char* appName);
};
