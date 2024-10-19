// Copyright 2024 Vanushkin Dmitry

#pragma once
#include <string>

class LongNumberCalculator {
 public:
  std::string operator()(int argc, const char** argv);

 private:
  struct Args {
    enum class Action { ADD, MINUS, MULTPLY, COMPARE } action;

    std::string leftOperand;
    std::string rightOperand;

    Args(int argc, const char** argv);

   private:
    static bool IsNumber(const std::string& numberAsString);
  };
};
