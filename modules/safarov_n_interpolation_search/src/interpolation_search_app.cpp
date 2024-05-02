// Copyright 2024 Borovkov Sergey
#include "include/interpolation_search_app.h"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

bool SearchApp::validate(int argc, char* argv[]) {
  if (argc == 1 || std::strcmp(argv[1], "--help") == 0) {
    help(argv[0]);
    return false;
  }

  for (int i = 1; i < argc - 1; i++) {
    try {
      sequence.push_back(std::stoi(argv[i]));
    } catch (const std::invalid_argument& e) {
      help(argv[0], "Invalid input: arguments must be integers.");
      sequence.clear();
      return false;
    }
  }

  return true;
}

void SearchApp::help(const char* appName, const char* msg) {
  std::string message =
      "This is an application for searching a target number in a sequence "
      "using interpolation search.\n\n"
      "Please provide arguments for searching.\n\n";

  if (msg != nullptr) {
    message += msg;
  }

  searchMsg = message;
}

std::string SearchApp::search_application(int argc, char* argv[]) {
  if (validate(argc, argv)) {
    if (sequence.empty()) {
      searchMsg = "Please provide the sequence to search in.";
      return searchMsg;
    }

    int target;
    try {
      target = std::stoi(argv[argc - 1]);
    } catch (const std::invalid_argument& e) {
      searchMsg = "Invalid input: target must be an integer.";
      return searchMsg;
    }

    int result = interpolationSearch(sequence, target);

    if (result != -1) {
      searchMsg = "Target number " + std::to_string(target) +
                  " found at index " + std::to_string(result);
    } else {
      searchMsg = "Target number " + std::to_string(target) +
                  " not found in the sequence.";
    }

    std::cout << searchMsg << '\n';
  }

  return searchMsg;
}
