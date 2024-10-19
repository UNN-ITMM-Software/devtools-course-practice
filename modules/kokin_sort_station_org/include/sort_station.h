// Copyright 2024 Kokin Ivan

#ifndef MODULES_KOKIN_SORT_STATION_ORG_INCLUDE_SORT_STATION_H_
#define MODULES_KOKIN_SORT_STATION_ORG_INCLUDE_SORT_STATION_H_

#include <string>
#include <unordered_map>

class SortStationDerived {
 public:
  double calculateFunction(const std::string& expression);
  double evaluatePostfixExpression(const std::string& postfix);

 private:
  double applyOperator(double a, double b, char op);
  std::string convertToPostfix(const std::string& expression);

 protected:
  std::unordered_map<char, int> precedence = {
      {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
};

#endif  // MODULES_KOKIN_SORT_STATION_ORG_INCLUDE_SORT_STATION_H_
