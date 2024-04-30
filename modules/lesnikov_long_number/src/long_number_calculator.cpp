// Copyright 2024 Vanushkin Dmitry

#include "include/long_number_calculator.h"

#include "include/LongNumber.h"


std::string LongNumberCalculator::operator()(int argc, const char **argv) {
    try {
        auto args = Args(argc, argv);

        auto left = LongNumber(args.leftOperand);
        auto right = LongNumber(args.rightOperand);

        switch (args.action) {
            case Args::Action::ADD: {
                return (left + right).getString();
            }
            case Args::Action::MINUS: {
                return (left - right).getString();
            }
            case Args::Action::MULTPLY: {
                return (left * right).getString();
            }
            case Args::Action::COMPARE: {
                if (left > right) {
                    return  ">";
                }
                if (left < right) {
                    return "<";
                }
                return "=";
            }
        }
    } catch (const std::exception &ex) {
        return ex.what();
    }
}

LongNumberCalculator::Args::Args(int argc, const char **argv) {
    if (argc != 4) {
        auto message = std::string("Usage: ") + argv[0]
        + " LEFT_OPERAND ACTION RIGHT_OPERAND\n"
                "ACTION is one of the follow list:\n"
                " '+': add big numbers\n"
                " '-': minus big numbers\n"
                " '*': multiply big numbers\n"
                " 'cmp': compare big numbers";
        throw std::exception(message.c_str());
    }

    if (!IsNumber(argv[1])) {
        throw std::exception("Invalid LEFT_OPERAND, it is must be a number");
    }

    if (!IsNumber(argv[3])) {
        throw std::exception("Invalid RIGHT_OPERAND, it is must be a number");
    }

    auto inputAction = std::string(argv[2]);
    if (inputAction == "+") {
        action = Action::ADD;
    } else if (inputAction == "-") {
        action = Action::MINUS;
    } else if (inputAction == "*") {
        action = Action::MULTPLY;
    } else if (inputAction == "cmp") {
        action = Action::COMPARE;
    } else {
        throw std::exception("Invalid ACTION");
    }

    leftOperand = argv[1];
    rightOperand = argv[3];
}

bool LongNumberCalculator::Args::IsNumber(const std::string &numberAsString) {
    auto isNegative = numberAsString[0] == '-';
    if (isNegative && numberAsString.size() == 1) {
        return false;
    }
    for (size_t i = isNegative ? 1 : 0; i < numberAsString.size(); ++i) {
        auto symbol = numberAsString[i];
        if (symbol < '0' || symbol > '9') {
            return false;
        }
    }

    return true;
}
