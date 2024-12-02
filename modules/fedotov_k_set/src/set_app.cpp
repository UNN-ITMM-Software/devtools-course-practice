// Copyright 2024 Derun Andrey

#include "include/set_app.h"

#include <cstring>
#include <sstream>
#include <string>

void SetApp::help(const char* appname, const char* message) {
  std::stringstream ss;

  // Add any custom error message if provided
  if (message && *message != '\0') {
    ss << message << "\n\n";
  }

  // Detailed help message
  ss << "Set Operations Calculator\n\n";
  ss << "Usage: " << appname << " <set> <operation> <argument>\n\n";
  ss << "Supported operations:\n";
  ss << "  insert <element>     - Add an element to the set\n";
  ss << "  remove <element>     - Remove an element from the set\n";
  ss << "  union <set>          - Combine two sets\n";
  ss << "  intersect <set>      - Find common elements\n";
  ss << "  subset <set>         - Check if first set is subset of second\n";
  ss << "  size                 - Get number of elements in set\n\n";
  ss << "Set format: {1,2,3}\n\n";
  ss << "Examples:\n";
  ss << "  " << appname << " {1,2,3} insert 4\n";
  ss << "  " << appname << " {1,2,3} union {4,5}\n";
  ss << "  " << appname << " {1,2,3} difference {2,3}\n";

  message_ = ss.str();
}

bool SetApp::validate(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 4) {
    help(argv[0], "ERROR: Should be 4 arguments.\n\n");
    return false;
  }
  return true;
}

std::string SetApp::operator()(int argc, const char** argv) {
  if (!validate(argc, argv)) {
    return message_;
  }

  std::string set1Str = argv[1];
  std::string operation = argv[2];
  std::string set2Str = argv[3];

  Set set1(set1Str);

  if (operation == "insert") {
    int element = std::stoi(set2Str);
    set1.add(element);
    return set1.toString();
  } else if (operation == "remove") {
    int element = std::stoi(set2Str);
    set1.remove(element);
    return set1.toString();
  } else if (operation == "union") {
    Set set2(set2Str);
    Set result = set1.unionWith(set2);
    return result.toString();
  } else if (operation == "intersect") {
    Set set2(set2Str);
    Set result = set1.intersectWith(set2);
    return result.toString();
  } else {
    throw std::runtime_error("Invalid operation");
  }
}
