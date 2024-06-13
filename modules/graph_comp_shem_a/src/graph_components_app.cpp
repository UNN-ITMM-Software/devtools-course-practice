// Copyright 2024 Shemiakina Alesia

#include "include/graph_components_app.h"

#include <cstring>
#include <sstream>
#include <iostream>

bool GraphComponentsApplication::validate(int argc, char* argv[]) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (std::strcmp(argv[1], "--help") == 0) {
    help(argv[0]);
    return false;
  }
  n = std::stoi(argv[1]);
  return true;
}

void GraphComponentsApplication::help(const char* appName, const char* msg) {
  std::stringstream message;

  if (msg) message << "Error: " << msg << '\n';

  message << "This program calculates number of graph components";
  message_ = message.str();
}

std::string GraphComponentsApplication::operator()(int argc, char* argv[]) {
  bool b = validate(argc, argv);
  std::vector<std::vector<int>> v(n);
  for (int i = 2; i < argc; i++) {
    std::istringstream ss;
    ss.str(argv[i]);
    for (std::string s; std::getline(ss, s, ','); ) {
      v[i - 2].push_back(std::stoi(s));
    }
  }
  if (b) {
    std::stringstream str;
    str << graph_components_numbers(n, v);
    message_ = str.str();
  }
  return message_;
}
