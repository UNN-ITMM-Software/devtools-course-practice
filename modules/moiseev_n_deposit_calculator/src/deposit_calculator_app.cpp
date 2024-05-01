// Copyright 2024 Podyachikh Mikhail

// double depositAmount, double interestRate, int months

#include <stdexcept>
#include <sstream>
#include "../include/deposit_calculator_app.h"
#include "../include/deposit_calculator.h"

std::string Deposit::Application::help(const char *appname,
                                       const char *message) {
  return std::string(message) +
      "This is a deposit calculator application.\n\n"
      "Please provide arguments in the following format:\n\n"
      "  $ " + appname + " <deposit_amount> <interest_rate> <n_months> \n\n"
      "Where <deposit_amount> & <interest_rate> arguments "
      "are double-precision numbers, "
      "and <n_months> is integer number.\n";
}

void Deposit::Application::parse(int argc, const char **argv) {
  if (argc == 1) {
    throw help(argv[0], "");
  }
  if (argc != 4) {
    throw help(argv[0], "ERROR: Should be 3 arguments.\n\n");
  }

  char *end1, *end2, *end3;
  arguments = {
      strtod(argv[1], &end1),
      strtod(argv[2], &end2),
      static_cast<int>(strtol(argv[3], &end3, 10)),
  };
  if (end1[0] || end2[0] || end3[0]) {
    throw std::string("Wrong arguments format!");
  }
}

std::string Deposit::Application::operator()(int argc, const char **argv) {
  try {
    parse(argc, argv);

    DepositCalculator calculator;
    double profit = calculator.calculateProfit(arguments.depositAmount,
                                               arguments.interestRate,
                                               arguments.months);
    double profitCap = calculator.calculateProfitCapitalization(
        arguments.depositAmount, arguments.interestRate, arguments.months);

    std::stringstream message;
    message << "Profit = " << profit << "\n";
    message << "Profit capitalisation = " << profitCap << "\n";
    return message.str();
  } catch (std::string &err) {
    return err;
  } catch (std::invalid_argument &err) {
    return err.what();
  }
}
