// Copyright 2024 Soloninko Andrey

#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>


#include "include/ins_sort_app.h"
#include "include/insertion_sort.h"

bool SortApp::validate(int argc, char *argv[]) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (std::strcmp(argv[1], "--help") == 0) {
    help(argv[0]);
    return false;
  }
  for (int i = 1; i < argc; i++) {
    test.push_back(std::stoi(argv[i]));
  }
  return true;
}

void SortApp::help(const char *appName, const char *msg) {
  std::stringstream message;

  message << "This is an application for sorting an array of numbers ";
  message << "by insertion sort.\n\n";
  message << "Please provide arguments for sorting\n\n";

  sortMsg = message.str();
}

std::string SortApp::sort_application(int argc, char *argv[]) {
  if (validate(argc, argv)) {
    std::vector<std::string> str_test;
    InsertionSort::sort(test);
    for (size_t i = 0; i < test.size(); i++) {
      str_test.push_back(std::to_string(test[i]));
      if (i < test.size() - 1) {
        str_test.push_back(",");
      }
    }
    sortMsg = std::accumulate(str_test.begin(), str_test.end(), std::string{});
    std::cout << sortMsg;
  }
  return sortMsg;
}
