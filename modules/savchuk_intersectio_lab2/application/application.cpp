// Copyright 2024 Belan Vadim

#include "include/console_application.h"

int main(int argc, char* argv[]) {
  Application app;
  return app.main(argc, std::vector<std::string>(argv, argv + argc));
}
