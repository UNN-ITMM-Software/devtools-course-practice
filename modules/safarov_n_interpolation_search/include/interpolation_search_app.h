// Copyright 2024 Borovkov Sergey
#ifndef MODULES_SAFAROV_N_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_APP_H_
#define MODULES_SAFAROV_N_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_APP_H_

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/interpolation_search.h"

class SearchApp {
 public:
  SearchApp() = default;
  std::string search_application(int argc, char* argv[]);

 private:
  std::string searchMsg{};
  std::vector<int> sequence;
  bool validate(int argc, char* argv[]);
  void help(const char* appName, const char* msg = nullptr);
};
#endif  // MODULES_SAFAROV_N_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_APP_H_
