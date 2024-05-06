// Copyright 2024 Kistrimova Ekaterina

#ifndef MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_APP_H_
#define MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_APP_H_

#include <string>
#include <vector>
#include "include/tbitfield.h"

// class TBitFieldApp {
//  public:
//     TBitFieldApp(int argc, char** argv);
//     std::string Run();

//  private:
//     std::vector<std::string> args;
//     TBitField bitField;

//     void ProcessArguments();
//     void PerformBitFieldOperations();
// };

class TBitFieldApp {
    // TBitField tbitfield;
    std::vector<std::string> parse(int argc, const char** argv);
    void help(std::vector<std::string>& output);
 public:
    TBitFieldApp() {}
    std::vector<std::string> runApp(int argc, const char** argv);
};

#endif  // MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_APP_H_
