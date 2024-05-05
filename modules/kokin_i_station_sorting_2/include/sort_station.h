// Copyright 2024 Kokin Ivan

#ifndef MODULES_KOKIN_I_STATION_SORTING_INCLUDE_SORT_STATION_H_
#define MODULES_KOKIN_I_STATION_SORTING_INCLUDE_SORT_STATION_H_

#include <string>
#include <stack>
#include <unordered_map>

class SortStation {
 public:
    virtual double evaluateFunction(const std::string& expression) = 0;

 protected:
    std::unordered_map<char, int> precedence = {
            {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}
    };
};

class SortStationDerived : public SortStation {
 public:
     double evaluateFunction(const std::string& expression) override;
     double evaluatePostfixExpression(const std::string& postfix);
 private:
     double applyOperator(double a, double b, char op);
     std::string convertToPostfix(const std::string& expression);
};

#endif  // MODULES_KOKIN_I_STATION_SORTING_INCLUDE_SORT_STATION_H_
