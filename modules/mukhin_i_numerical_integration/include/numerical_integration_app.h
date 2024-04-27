// Copyright 2024 Kriseev Mikhail
#ifndef MODULES_MUKHIN_I_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_APP_H_
#define MODULES_MUKHIN_I_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_APP_H_

#include <string>

namespace NumericalIntegrator {

enum class IntegrationMethod { quad, trapezoid };

class Application {
 public:
  static std::string run(int argc, char* argv[]);
};
}  // namespace NumericalIntegrator

#endif  // MODULES_MUKHIN_I_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_APP_H_
