// Copyright 2021 Chirkov Roman

#ifndef MODULES_REVERSE_POLISH_NOTATION_INCLUDE_RPN_H_
#define MODULES_REVERSE_POLISH_NOTATION_INCLUDE_RPN_H_

#include <stack>
#include <string>

class RPN {
 private:
  std::stack<char> op_stack;
  std::string line;

 public:
  RPN();
  explicit RPN(std::string s);
  static bool isOperator(char c);
  static int priority(char c);
  void putSpaceIfNeeded();
  std::string getLine();
};

#endif  // MODULES_REVERSE_POLISH_NOTATION_INCLUDE_RPN_H_
