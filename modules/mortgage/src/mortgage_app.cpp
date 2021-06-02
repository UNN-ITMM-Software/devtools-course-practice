// Copyright 2021 Ludina Daria

#include <string>
#include <sstream>

#include "include/mortgage.h"
#include "include/mortgage_app.h"

mortgage_app::mortgage_app() : message_("") {}

void mortgage_app::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
      "This is a mortgage calculator application.\n\n" +
      "Please provide arguments in the following format:\n\n"+

      "  $ " + appname + " <c_cost> <d_downPayment> " +
      "<c_creditTerm> <i_interestRate> \n\n" +

      "Where all arguments are integer numbers, " +
      "and <i_interestRate> is double-precision number.\n";
}

bool mortgage_app::validateNumberOfArguments(int argc,
const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 5) {
    help(argv[0], "ERROR: Should be 4 arguments.\n\n");
    return false;
  }
  return true;
}

std::string mortgage_app::operator()(int argc, const char** argv) {
  Arguments args;

  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  try {
    args.c_cost =  static_cast<unsigned int>(std::stoul(argv[1]));
    args.d_downPayment =  static_cast<unsigned int>(std::stoul(argv[2]));
    args.c_creditTerm  =  static_cast<unsigned int>(std::stoul(argv[3]));
    args.i_interestRate = std::stod(argv[4]);
    if (args.i_interestRate < 0) {
      return std::string("Interest rate must be greater than zero!");
    }
  }
     catch (std::exception &error) {
    return std::string("Wrong number format!");
  }

  mortgage calculator(args.c_cost, args.d_downPayment,
  args.c_creditTerm, args.i_interestRate);
  calculator.calc();
  std::ostringstream stream;
  stream << "c_cost = " << calculator.getCost() << " "
       << "d_downPayment = " << calculator.getDownPayment() << " "
       << "c_creditTerm = " << calculator.getCreditTerm() << " "
       << "i_interestRate = " << calculator.getInterestRate() << " "
       << "payment = " << calculator.getMonthlyPayment();


  message_ = stream.str();
  return message_;
}
