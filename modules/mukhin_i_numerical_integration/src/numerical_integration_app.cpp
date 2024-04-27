// Copyright 2024 Kriseev Mikhail

#include "include/numerical_integration_app.h"

#include <cmath>
#include <cstring>
#include <sstream>

#include "include/integration_methods.h"

std::string NumericalIntegrator::Application::run(int argc, char **argv) {
  std::stringstream out;
  std::string usageString =
      "Usage: " + std::string(argv[0]) +
      " [method: trapezoid | quad] <lower bound> <upper bound> "
      "<number of intervals>\n\n"
      "Integrates function y=tan(x) on specified interval. \n"
      "Two methods available: quad and trapezoid. If not specified, "
      "quad method is used.";
  if (argc < 4) {
    out << "Too few arguments!\n" << usageString;
  } else if (argc == 4) {
    try {
      double lowerBound = std::stod(argv[1]);
      double upperBound = std::stod(argv[2]);
      int intervals = std::stoi(argv[3]);
      out << IntegrationMethods::integrate_quads(
          [=](double x) { return tan(x); }, lowerBound, upperBound, intervals);
    } catch (std::invalid_argument &e) {
      out << "Error: some of the arguments are incorrect!";
    }
  } else if (argc == 5) {
    try {
      double lowerBound = std::stod(argv[2]);
      double upperBound = std::stod(argv[3]);
      int intervals = std::stoi(argv[4]);
      if (strcmp("quad", argv[1]) == 0) {
        out << IntegrationMethods::integrate_quads(
            [=](double x) { return tan(x); }, lowerBound, upperBound,
            intervals);
      } else if (strcmp("trapezoid", argv[1]) == 0) {
        out << IntegrationMethods::integrate_trapezoid(
            [=](double x) { return tan(x); }, lowerBound, upperBound,
            intervals);
      } else {
        throw std::invalid_argument("method");
      }
    } catch (std::exception &e) {
      out << "Error: some of the arguments are incorrect!";
    }
  } else {
    out << "Too many arguments!\n" << usageString;
  }
  return out.str();
}
