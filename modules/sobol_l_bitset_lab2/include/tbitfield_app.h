// Copyright 2024 Kistrimova Ekaterina

#ifndef MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_APP_H_
#define MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_APP_H_

#include <string>
#include <vector>
#include "tbitfield.h"

class TBitFieldApp {
public:
    TBitFieldApp(int argc, char** argv);
    std::string Run();

private:
    std::vector<std::string> args;
    TBitField bitField;

    void ProcessArguments();
    void PerformBitFieldOperations();
};

#endif  // MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_APP_H_
