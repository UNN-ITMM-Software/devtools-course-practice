// Copyright 2024 Kokin Ivan
#ifndef MODULES_KOKIN_SORT_STATION_ORG_INCLUDE_CONSOLE_APP_H_
#define MODULES_KOKIN_SORT_STATION_ORG_INCLUDE_CONSOLE_APP_H_

#include <string>

#include "include/sort_station.h"


class ConsoleApp {
 public:
  void run(int argc, const char** argv);

 private:
  void printHelp();
  std::string calculateExpression(const std::string& expression);
  SortStationDerived sortStation;
};

#endif  // MODULES_KOKIN_SORT_STATION_ORG_INCLUDE_CONSOLE_APP_H_
