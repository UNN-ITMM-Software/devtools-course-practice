// Copyright 2024 Vasilev Ivan
#ifndef MODULES_KOKIN_I_STATION_SORTING_INCLUDE_CONSOLE_APP_H_
#define MODULES_KOKIN_I_STATION_SORTING_INCLUDE_CONSOLE_APP_H_

#include <string>

#include "../include/sort_station.h"
class ConsoleApp {
 public:
  void run(int argc, const char** argv);

 private:
  void printHelp();
  void evaluateExpression(const std::string& expression);
  SortStationDerived sortStation;
};

#endif  // MODULES_KOKIN_I_STATION_SORTING_INCLUDE_CONSOLE_APP_H_
