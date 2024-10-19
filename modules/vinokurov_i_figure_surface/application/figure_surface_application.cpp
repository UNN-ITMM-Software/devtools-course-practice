// Copyright 2024 Andrey Karagodin

#include <stdlib.h>

#include <iostream>
#include <string>

#include "include/figure_surface_app.h"

int main(int argc, char** argv) {
  FigureSurfaceApp app;
  std::cout << app(argc, argv);
  return 0;
}
