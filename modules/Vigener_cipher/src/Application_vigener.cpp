// Copyright 2021 Chernyh Daria

#include "include/Application_vigener.h"

#include <cstring>
#include <sstream>
#include <string>

#include "include/Vigener.h"

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
  message_ =
        std::string(message) +
        "This is  an application that calculates the Vigener cipher.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <key> <message> " +
        "<operation>\n\n" +

        "Where all arguments are strings, " +
        "and <operation> is one of 'e' - encrypt message," +
        "'d' - decrypt message.\n";
}

char CheckOperation(const char* arg) {
    char op;
    if (strcmp(arg, "e") == 0) {
        op = 'e';
    } else if (strcmp(arg, "d") == 0) {
        op = 'd';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string CheckString(const char* arg) {
    std::string value(arg);
    int lenght = static_cast<int>(strlen(arg));
    for (int i = 0; i < lenght; i++) {
        if (!isalpha(arg[i])) {
            throw std::string("Wrong string format!");
        }
    }
    return value;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.key = CheckString(argv[1]);
        args.str_input = CheckString(argv[2]);
        args.operation = CheckOperation(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    Vigener_cipher chip(args.key);
    std::string str_out;

    std::ostringstream stream;
    switch (args.operation) {
    case 'e':
        str_out = chip.encrypt(args.str_input);
        stream << "Encrypt = " << str_out;
        break;
    case 'd':
        str_out = chip.decrypt(args.str_input);
        stream << "Decrypt = " << str_out;
        break;
    }

    message_ = stream.str();

    return message_;
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}
