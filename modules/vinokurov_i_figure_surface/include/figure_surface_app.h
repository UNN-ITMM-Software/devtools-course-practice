// Copyright 2024 Karagodin Andrey

#include "include/figure_surface.h"

#include <string>
#include <cstring>
#include <sstream>

class FigureSurfaceApp
{
public:
    FigureSurfaceApp() = default;
    std::string operator()(int argc, char* argv[]);
private:
    FigureSurface figureSurface;
    void help(const char* appName, const char* msg = nullptr);
    bool validate(int argc, char* argv[]);
    void shapes(const char* appName, const char** msg = nullptr);
    std::string getOperationType(const char* arg);
    std::string message_;
};
