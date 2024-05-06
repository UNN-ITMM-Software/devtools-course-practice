// Copyright 2024 Kistrimova Ekaterina

#ifndef TBITFIELD_APP_H
#define TBITFIELD_APP_H

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

#endif  // TBITFIELD_APP_H
