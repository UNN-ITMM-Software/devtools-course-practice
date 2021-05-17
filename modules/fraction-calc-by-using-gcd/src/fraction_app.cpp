// Copyright 2021 Gruzdeva Diana

#include "include/fraction_app.h"

#include <string>
#include <sstream>
#include <stdexcept>

#include "include/fraction.h"

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is a fraction calculator application.\n\n" +
    "Please provide arguments in the following format:\n\n" +
    "  $ " + appname + " <f1_num> <f1_den> "
    + "<f2_num> <f2_den> <operation>\n\n" +
    "Where all arguments are integer numbers, " +
    "and <operation> is one of '+', '-', '*', '/'.\n\n" +

    "Operation:\n'+' = addition,\n'-' = subtraction,\n" +
    "'*' = multiplication,\n'/' = division.\n ";
}

bool Application::validateNumberOfArguments(int argc,
    const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Wrong number of arguments.\n\n");
        return false;
    }
    return true;
}

std::string Application::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    if (argc == 6) {
        Operation5Args operation;
        message_ = operation(argv);
    }
    return message_;
}

char Operation5Args::parseOperation(std::string str) {
    if (str.size() == 1) {
        char op = str[0];
        switch (op) {
        case '+':
            return '+';
        case '-':
            return '-';
        case '*':
            return '*';
        case '/':
            return '/';
      }
    }
    throw std::string("Wrong operation format!");
    return ' ';
}

std::string Operation5Args::operator()(const char** argv) {
    char operation;
    Fraction f1;
    Fraction f2;

    try {
        f1 = Fraction(std::stoi(argv[1]), std::stoi(argv[2]));
        f2 = Fraction(std::stoi(argv[3]), std::stoi(argv[4]));
        operation = parseOperation(argv[5]);
    }
    catch (std::string& str) {
        return str;
    }
    catch (std::invalid_argument) {
        return std::string("Wrong number format!");
    }

    std::ostringstream stream;

    Fraction fr;

    switch (operation) {
    case '+':
        fr = f1 + f2;
        stream << "Numerator = " << fr.getNumerator() << " "
            << "Denominator = " << fr.getDenominator();
        break;
    case '-':
        fr = f1 - f2;
        stream << "Numerator = " << fr.getNumerator() << " "
            << "Denominator = " << fr.getDenominator();
        break;
    case '*':
        fr = f1 * f2;
        stream << "Numerator = " << fr.getNumerator() << " "
            << "Denominator = " << fr.getDenominator();
        break;
    case '/':
            fr = f1 / f2;
            stream << "Numerator = " << fr.getNumerator() << " "
                << "Denominator = " << fr.getDenominator();
            break;
    }

    return std::string(stream.str());
}
