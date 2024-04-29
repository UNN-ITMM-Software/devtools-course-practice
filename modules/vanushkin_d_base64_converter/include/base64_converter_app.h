// Copyright 2024 Vinichuk Timofey
#pragma once

#include "include/base64_converter.h"
#include <stdexcept>
#include <string>

class Base64ConverterApplication {
 public:
  Base64ConverterApplication() = default;

  std::string operator()(int argc, char *argv[]);

 private:
  void help(const char *appname, const char *message = "");
  bool validate(int argc, char *argv[]);
  std::string message_;
};
