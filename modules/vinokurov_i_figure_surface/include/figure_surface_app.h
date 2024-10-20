// Copyright 2024 Karagodin Andrey

#ifndef MODULES_VINOKUROV_I_FIGURE_SURFACE_INCLUDE_FIGURE_SURFACE_APP_H_
#define MODULES_VINOKUROV_I_FIGURE_SURFACE_INCLUDE_FIGURE_SURFACE_APP_H_

#include <cstring>
#include <sstream>
#include <string>

#include "include/figure_surface.h"

class FigureSurfaceApp {
 public:
  FigureSurfaceApp() = default;
  std::string operator()(int argc, char* argv[]);

 private:
  FigureSurface figureSurface;
  void help(const char* appName, const char* msg = nullptr);
  bool validate(int argc, char* argv[]);
  void shapes(const char** msg = nullptr);
  static std::string getOperationType(const char* arg);
  std::string message_;
};

#endif  // MODULES_VINOKUROV_I_FIGURE_SURFACE_INCLUDE_FIGURE_SURFACE_APP_H_
