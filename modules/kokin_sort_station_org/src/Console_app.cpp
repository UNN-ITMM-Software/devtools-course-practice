// Copyright 2024 Kokin Ivan
#include "Console_app.h"

#include <iostream>
#include <string>

void ConsoleApp::run(int argc, const char** argv) {
  if (argc == 1) {
    printHelp();
  } else if (argc == 2) {
    std::string expression = argv[1];
    calculateExpression(expression);
  } else {
    std::cerr << "Invalid number of arguments." << std::endl;
    printHelp();
  }
}

void ConsoleApp::printHelp() {
  std::cout << "Usage: " << std::endl;
  std::cout << "  SortStation [expression]" << std::endl;
  std::cout << "Example: " << std::endl;
  std::cout << "  SortStation 2+2" << std::endl;
}

std::string ConsoleApp::calculateExpression(const std::string& expression) {
  std::string s =
      "Result: " + std::to_string(sortStation.calculateFunction(expression));
  std::cout << s << std::endl;
  return s;
}
