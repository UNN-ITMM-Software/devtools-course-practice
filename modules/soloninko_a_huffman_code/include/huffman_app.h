// Copyright 2024 Lesnikov Nikita

#pragma once

#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>

#include "include/huffman.h"

class HuffmanApp {
 public:
  std::string operator()(int argc, char** argv);

 private:
  static std::string _encode(int argc, char** argv);
  static std::string _decode(int argc, char** argv);
  static std::unordered_map<std::string, char> _getCodes(int argc, char** argv);
  static std::string _validate(int argc, char** argv);
  static bool _validateNumArgs(int num);
  static bool _validateEncoded(const char* str);
  static bool _validateCodes(int argc, char** argv);
  static std::string _help(const char* appName);
};
