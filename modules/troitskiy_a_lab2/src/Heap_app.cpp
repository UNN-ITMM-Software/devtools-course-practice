// Copyright 2024 Kozlov Mikhail

#include "include/Heap_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

void Heap_app::help(const char *appname, const char *message) {
  message_ = std::string(message) +
             "This is a max-heap application.format - 1st arg is strig of "
             "uppercase characters first character is always B - build heap, T "
             "- max elem , P - pop, A - add elem";
}
bool Heap_app::validateNumberOfArguments(int argc, const char **argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  }
  return true;
}

double parseDouble(const char *arg) {
  char *end;
  double value = strtod(arg, &end);

  if (end[0]) {
    throw std::logic_error("Wrong number format!");
  }

  return value;
}

uint64_t parseInt(const char *arg) {
  char *end;
  double value = strtol(arg, &end, 10);

  if (end[0]) {
    throw std::logic_error("Wrong number format!");
  }

  return value;
}

void check_first(char c, bool first) {
  if (c != 'B' && first)
    throw std::logic_error("Wrong operation");

  if (c == 'B' && !first)
    throw std::logic_error("Wrong operation");
}

std::string Heap_app::operator()(int argc, const char **argv) {
  Arguments args;
  std::vector<Arguments> ops;
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  const char *op = argv[1];
  args.operation = 'B';
  try {
    check_first(op[0], 1);
  } catch (std::logic_error &str) {
    return str.what();
  }
  double el;
  uint64_t N;
  try {
    N = parseInt(argv[2]);
  } catch (std::logic_error &str) {
    return str.what();
  }
  int ptr = 3;
  for (uint64_t i = 0; i < N; ++i) {
    try {
      el = parseDouble(argv[ptr]);
      args.nums.push_back(el);
    } catch (std::logic_error &str) {
      return str.what();
    }
    ptr++;
  }
  Heap<1000> H(args.nums);
  int i = 1;
  while (op[i]) {
    args.nums.clear();
    char s = op[i];
    try {
      check_first(op[i], 0);
    } catch (std::logic_error &str) {
      return str.what();
    }
    if (s == 'A') {
      try {
        args.nums.push_back(parseDouble(argv[ptr]));
      } catch (std::logic_error &str) {
        return str.what();
      }
      ptr++;
      args.operation = 'A';
    }
    if (s == 'T') {
      args.operation = 'T';
    }
    if (s == 'D') {
      args.operation = 'D';
    }
    ops.push_back(args);
    i++;
  }
  std::ostringstream stream;
  for (const auto &elem : ops) {
    // char c = elem.operation;
    // printf("%c\n",c);
    switch (elem.operation) {
    case 'A':
      H.push(elem.nums[0]);
      break;
    case 'T':
      try {
        stream << H.top() << " ";
      } catch (std::logic_error &str) {
        return str.what();
      }
      break;
    case 'D':
      try {
        H.pop();
      } catch (std::logic_error &str) {
        return str.what();
      }
      break;
    }
  }
  while (H.size()) {
    stream << H.top() << " ";
    H.pop();
  }
  message_ = stream.str();

  return message_;
}
