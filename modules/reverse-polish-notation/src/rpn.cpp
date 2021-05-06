// Copyright 2021 Chirkov Roman

#include "include/rpn.h"

#include <stack>
#include <string>

RPN::RPN() { line = ""; }

RPN::RPN(std::string s) {
  if (s == "") {
    line += s;
    return;
  }
  if (isOperator(s[0])) {
    throw "wrong source string: the first simbol is operator";
  }

  for (size_t i = 0; i < s.size(); i++) {
    if (std::isalpha(s[i]) || std::isdigit(s[i])) {
      line += s[i];
      continue;
    }

    if (isOperator(s[i])) {
      putSpaceIfNeeded();

      while (!op_stack.empty()) {
        if (priority(s[i]) <= priority(op_stack.top())) {
          putSpaceIfNeeded();
          line += op_stack.top();
          op_stack.pop();
        } else {
          break;
        }
      }

      putSpaceIfNeeded();
      op_stack.push(s[i]);
      continue;
    }

    if (s[i] == '(') {
      op_stack.push(s[i]);
      continue;
    }

    if (s[i] == ')') {
      if (op_stack.empty()) throw "extra right parenthesis";
      while (op_stack.top() != '(') {
        putSpaceIfNeeded();
        line += op_stack.top();
        op_stack.pop();
      }
      op_stack.pop();
      continue;
    }

    throw "unsupported symbol";
  }

  while (!op_stack.empty()) {
    if (op_stack.top() == '(') throw "extra parenthesis";
    putSpaceIfNeeded();
    line += op_stack.top();
    op_stack.pop();
  }
}

bool RPN::isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int RPN::priority(char c) {
  switch (c) {
    case '(':
      return 1;
    case '-':
      return 2;
    case '+':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
    case '^':
      return 4;
  }
  throw "unsupported symbol";
}

void RPN::putSpaceIfNeeded() {
  if (line[line.size() - 1] != ' ') {
    line += " ";
  }
}

std::string RPN::getLine() { return line; }
