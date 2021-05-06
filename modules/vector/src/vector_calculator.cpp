// Copyright 2021 Shagov Maksim

#include "include/vector.h"
#include "include/vector_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

VectorCalculator::VectorCalculator() : message_("") {}

void VectorCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
           "This is a vector calculator application.\n" \
          "Please provide arguments in the following format:\n" \
          "  $ " + appname + " <v1_x> <v1_y> <v1_z> " \
          "<v2_x> <v2_y> <v2_z> <operation>\n\n" \
          "Where all arguments are double-precision numbers, " \
          "and <operation> is one of 'norm', 'dot', '*', 'normalize'.\n";
}

bool VectorCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 8 || argc == 5) {
        return true;
    }
    help(argv[0], "ERROR: Should be 8 or 5 arguments.\n\n");
    return false;
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
    if (strcmp(arg, "dot") == 0) {
        op = 'd';
    } else if (strcmp(arg, "norm") == 0) {
        op = 'n';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "normalize") == 0) {
        op = 'l';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string VectorCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        if (argc == 8) {
            args.v_1.setX(parseDouble(argv[1]));
            args.v_1.setY(parseDouble(argv[2]));
            args.v_1.setZ(parseDouble(argv[3]));
            args.v_2.setX(parseDouble(argv[4]));
            args.v_2.setY(parseDouble(argv[5]));
            args.v_2.setZ(parseDouble(argv[6]));
            args.operation = parseOperation(argv[7]);
        } else {
            args.v_1.setX(parseDouble(argv[1]));
            args.v_1.setY(parseDouble(argv[2]));
            args.v_1.setZ(parseDouble(argv[3]));
            args.operation = parseOperation(argv[4]);
        }
    }
    catch(std::string& str) {
        return str;
    }

    Vector v_1;
    Vector v_2;

    v_1.setX(args.v_1.x());
    v_1.setY(args.v_1.y());
    v_1.setZ(args.v_1.z());
    v_2.setX(args.v_2.x());
    v_2.setY(args.v_2.y());
    v_2.setZ(args.v_2.z());

    std::ostringstream stream;
    Vector r_v;
    double r_d;
    switch (args.operation) {
     case 'd':
        r_d = v_1.dot(v_2);
        stream << "v_1 dot v_2 = " << r_d;
        break;
     case 'n':
        r_d = v_1.norm();
        stream << "v_1.norm() = " << r_d;
        break;
     case '*':
        r_v = v_1 * v_2;
        stream << "result.x = " << r_v.x() <<
                  " result.y = " << r_v.y() <<
                  " result.z = " << r_v.z();
        break;
     case 'l':
        try {
            r_v = v_1.normalize();
            stream << "result.x = " << r_v.x() <<
                      " result.y = " << r_v.y() <<
                      " result.z = " << r_v.z();
            break;
        }
        catch(std::runtime_error& str) {
            return str.what();
        }
    }

    message_ = stream.str();

    return message_;
}
