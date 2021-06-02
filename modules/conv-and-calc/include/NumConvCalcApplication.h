// Copyright 2021 Gapon Andrey

#ifndef MODULES_CONV_AND_CALC_INCLUDE_NUMCONVCALCAPPLICATION_H_
#define MODULES_CONV_AND_CALC_INCLUDE_NUMCONVCALCAPPLICATION_H_

#include <string>

class NumConvCalcApplication {
 public:
  NumConvCalcApplication() = default;
  std::string operator()(int argc, const char* argv[]) const;
 private:
  std::string help(const std::string& filename) const;
};

#endif  // MODULES_CONV_AND_CALC_INCLUDE_NUMCONVCALCAPPLICATION_H_
