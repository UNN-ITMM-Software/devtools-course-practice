// Copyright 2024 Kriseev Mikhail

#include <iostream>

#include "include/numerical_integrator.h"

int main(int argc, char* argv[]) {
  std::cout << NumericalIntegrator::Application::run(argc, argv) << std::endl;
}
