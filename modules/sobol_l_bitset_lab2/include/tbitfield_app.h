// Copyright 2024 Kistrimova Ekaterina

#pragma once

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
