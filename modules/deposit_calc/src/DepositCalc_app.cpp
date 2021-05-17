// Copyright 2021 Belik Julia

#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "include/DepositCalc.h"
#include "include/DepositCalc_app.h"

using std::stoi;

DepositCalc_app::DepositCalc_app() : message_("") {}

void DepositCalc_app::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a deposit calc application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <deposit Sum> " +
        "<day> <month> <year> <interest Rate>" +
        " <number Of Months> <capitalization>\n\n" +

        "Where deposit Sum, day, month, year," +
        " number Of Months are integer numbers, \n" +
        "Interest Rate is double, \n" +
        "and capitalization is \n 0 - No capitalization \n 1 - Once a day \n" +
        " 2 - Once a week \n 3 - Once a month \n 4 - Once a year ";
}

bool DepositCalc_app::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 8) {
        help(argv[0], "Error: Should be 8 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Error: Wrong number format.\n\n");
    }

    return value;
}

bool DepositCalc_app::validateArguments(const char** argv,
    std::vector<int> daysInMonths) {
    if (std::stoi(argv[1]) < 0) {
        help(argv[0], "Error: Sum must be positive.\n\n");
        return false;
    }
    if (std::stoi(argv[3]) < 0) {
        help(argv[0], "Error: Number of months must be positive.\n\n");
        return false;
    }
    if (std::stoi(argv[2]) < 0) {
        help(argv[0], "Error: Number of days must be positive.\n\n");
        return false;
    }
    if (argv[5][0] == '-') {
        help(argv[0], "Error: Interest rate must be positive.\n\n");
        return false;
    }
    if (std::stoi(argv[2]) <= 0 ||
        std::stoi(argv[2]) > daysInMonths[std::stoi(argv[3]) % 12]
        || std::stoi(argv[3]) <= 0 || std::stoi(argv[3]) > 12 ||
        std::stoi(argv[4]) < 0) {
        help(argv[0], "Error: Incorrect date.\n\n");
        return false;
    }
    if (std::stoi(argv[7]) < 0 || std::stoi(argv[7]) > 4) {
        help(argv[0], "Error: Wrong value.\n\n");
        return false;
    }
    return true;
}

std::string DepositCalc_app::operator()(int argc, const char** argv) {
    depositCalc depc;
    Arguments args;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    if (!validateArguments(argv, depc.getDaysInMonths())) {
        return message_;
    }
    try {
        args.depositSum = parseDouble(argv[1]);
        args.numberOfMonths = parseDouble(argv[6]);
        args.interestRate = parseDouble(argv[5]);
        args.day = parseDouble(argv[2]);
        args.month = parseDouble(argv[3]);
        args.year = parseDouble(argv[4]);
        args.capitalization = parseDouble(argv[7]);
    }
    catch (std::string& str) {
        return str;
    }
    depc.setDepositSum(args.depositSum);
    depc.setDate(args.day, args.month, args.year);
    depc.setInterestRate(args.interestRate);
    depc.setNumberOfMonths(args.numberOfMonths);
    depc.setCapitalization(args.capitalization);
    std::ostringstream stream;
    int res;
    depc.calculate();
    res = depc.getResult();
    stream << "Profitability= " << res << ".";
    message_ = stream.str();
    return message_;
}
