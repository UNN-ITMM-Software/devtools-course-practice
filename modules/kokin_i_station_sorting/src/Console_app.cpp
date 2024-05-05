// Copyright 2024 Vasilev Ivan
#include <iostream>
#include <string>

#include "../include/Console_app.h"
#include "../include/sort_station.h"

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
    double result = sortStation.evaluateFunction(expression);
    std::cout << "Result: " << result << std::endl;
}
