// Copyright 2021 Zhbanova Nadezhda

#include "include/calculate_price.h"
#include "include/calculate_price_application.h"

#include <string>
#include <sstream>
#include <limits>
#include <stdexcept>

std::string CalculatePriceApplication::operator()(int argc,
        const char ** argv) {
    char * e;
    std::ostringstream stream;

    if (!ValidateNambersOfArguments(argc, argv)) {
        return message_;
    }

    if (!IsArgumentsInteger(argv)) {
        return message_;
    }

    for (int i = 1; i < 6; i++) {
        books.push_back(strtol(argv[i], &e, 10));
    }

    try {
        CalculatePrice price(books[0], books[1], books[2],
                             books[3], books[4]);

        double sum = price.TotalSum();
        stream << "Total Sum = " << sum;
    }
    catch (std::string & s) {
        Help(argv[0]);
        message_ = "ERROR: " + s + ".\n\n" + message_;
        return message_;
    }

    message_ = stream.str();

    return message_;
}

void CalculatePriceApplication::Help(const char *appname) {
    message_ = "This is application for class calculate price.\n\n"
           "Usage:\n" "> " + std::string(appname) +
           " actions that described below.\n"
           "Actions:\n" +
           std::string(appname) + " <book_1> <book_2> "
           "<book_3> <book_4> <book_5>\n\n"
           "Where all arguments are not negative integer numbers.\n";
}

bool CalculatePriceApplication::ValidateNambersOfArguments(int argc,
        const char ** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 6) {
        Help(argv[0]);
        message_ = "ERROR: Should be 5 arguments.\n\n" + message_;
        return false;
    }
    return true;
}

bool CalculatePriceApplication::IsArgumentsInteger(const char ** argv) {
    for (int i = 1; i < 6; i++) {
        char * e;
        int64_t value = strtol(argv[i], &e, 10);
        if (e[0]) {
            Help(argv[0]);
            message_ = "ERROR: Wrong number format.\n\n" + message_;
            return false;
        }
        if (value <= static_cast<int64_t>(std::numeric_limits<int>::min()) ||
            value >= static_cast<int64_t>(std::numeric_limits<int>::max())) {
            Help(argv[0]);
            message_ = "ERROR: Number is out of bounds.\n\n" + message_;
            return false;
        }
    }
    return true;
}
