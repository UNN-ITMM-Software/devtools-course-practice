// Copyright 2024 Kistrimova Ekaterina

#ifndef MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_APP_H_
#define MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_APP_H_

#include <string>
#include <vector>

#include "include/tbitfield.h"

class TBitFieldApp {
  TBitField myBitField;
  std::vector<std::string> parse(int argc, const char** argv);
  void help(std::vector<std::string>& output);
  void setbit(std::vector<std::string>& output, int index);
  void clearbit(std::vector<std::string>& output, int index);
  void getbit(std::vector<std::string>& output, int index);
  void print(std::vector<std::string>& output);

 public:
  TBitFieldApp() : myBitField(8) {}
  std::vector<std::string> runApp(int argc, const char** argv);
};

#endif  // MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_APP_H_
