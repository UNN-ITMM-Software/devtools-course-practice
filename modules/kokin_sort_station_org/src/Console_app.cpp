// Copyright 2024 Kokin Ivan
#include <iostream>
#include <string>

#include "Console_app.h"

void ConsoleApp::run(int argc, const char** argv) {
  if (argc == 1) {
    printHelp();
  } else if (argc == 2) {
    std::string expression = argv[1];
    evaluateExpression(expression);
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

void ConsoleApp::evaluateExpression(const std::string& expression) {
    std::string result = std::to_string(sortStation
            .evaluateCalculate(expression));
    std::cout << "Result: " << result << std::endl;
}
