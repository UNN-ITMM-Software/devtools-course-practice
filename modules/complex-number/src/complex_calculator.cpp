// Copyright 2017 Korniakov Kirill

#include "include/complex_number.h"
#include "include/complex_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

ComplexCalculator::ComplexCalculator() : message_("") {}

void ComplexCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a complex number calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <z1_real> <z1_imaginary> " +
          "<z2_real> <z2_imaginary> <operation>\n\n" +

          "Where all arguments are double-precision numbers, " +
          "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool ComplexCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string ComplexCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.z1_real      = parseDouble(argv[1]);
        args.z1_imaginary = parseDouble(argv[2]);
        args.z2_real      = parseDouble(argv[3]);
        args.z2_imaginary = parseDouble(argv[4]);
        args.operation    = parseOperation(argv[5]);
    }
    catch(std::string& str) {
        return str;
    }

    ComplexNumber z1;
    ComplexNumber z2;

    z1.setRe(args.z1_real);
    z1.setIm(args.z1_imaginary);
    z2.setRe(args.z2_real);
    z2.setIm(args.z2_imaginary);

    ComplexNumber z;
    std::ostringstream stream;
    switch (args.operation) {
     case '+':
        z = z1 + z2;
        stream << "Real = " << z.getRe() << " "
               << "Imaginary = " << z.getIm();
        break;
     case '-':
        z = z1 - z2;
        stream << "Real = " << z.getRe() << " "
               << "Imaginary = " << z.getIm();
        break;
     case '*':
        z = z1 * z2;
        stream << "Real = " << z.getRe() << " "
               << "Imaginary = " << z.getIm();
        break;
     case '/':
        try {
            z = z1 / z2;
            stream << "Real = " << z.getRe() << " "
                   << "Imaginary = " << z.getIm();
            break;
        }
        catch(std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
