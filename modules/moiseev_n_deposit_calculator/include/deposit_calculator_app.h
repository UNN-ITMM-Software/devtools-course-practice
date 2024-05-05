// Copyright 2024 Podyachikh Mikhail

#ifndef MODULES_MOISEEV_N_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_APP_H_
#define MODULES_MOISEEV_N_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_APP_H_

#include <string>

namespace Deposit {

class Application {
 public:
  Application() = default;

  std::string operator()(int argc, const char **argv);

 private:
  std::string help(const char *appname, const char *message = "");
  void parse(int argc, const char **argv);

  struct {
    double depositAmount;
    double interestRate;
    int months;
  } arguments;
};

}  // namespace Deposit

#endif  // MODULES_MOISEEV_N_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_APP_H_
