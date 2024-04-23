// Copyright 2024 Soloninko Andrey

#include <iostream>
#include <cstring>
#include <sstream>

#include "include/ins_sort_app.h"

bool SortApp::validate(int argc, char* argv[]) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc > 8) {
    help(argv[0], "the maximum number of points is 7");
    return false;
  } else if (std::strcmp(argv[1], "--help") == 0) {
    help(argv[0]);
    return false;
  }
}

void SortApp::help(const char* appName, const char* msg) {
  std::stringstream message;

  if (msg) message << "Error: " << msg << '\n';

  message <<  "This is an application for sorting an array of numbers";
  message << "by insertion sort.\n\n";
  message <<  "Please provide arguments in the following format:\n\n";

  sortMsg = message.str();
}

std::string SortApp::operator()(int argc, char* argv[]) {
  
  return "hullMessage";
}