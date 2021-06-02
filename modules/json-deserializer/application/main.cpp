// Copyright 2021 Ostapovich Denis

#include <string>

#include "include/application.h"

using jsonDeserializer::Application;

int main(int argc, const char** argv) {
  Application app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
