// Copyright 2021 Pronkin Dmitry

#include "include/grosfeld_cipher_app.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>
#include <sstream>
#include <string>

GronsfeldCipherApp::GronsfeldCipherApp() : message_("") {}

void GronsfeldCipherApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a Gronsfeld cipher application.\n\n" \
          "Please provide arguments in the following format:\n\n" \
          " $" + appname + " <sourceString> <key> <operation>\n\n" \
          "Where <sourceString> - string to decrypt or encrypt, " \
          "<key> - cipher key, <operation> is one of 'decrypt' or 'encrypt'\n";
}

bool GronsfeldCipherApp::validateNumberOfArguments(
    int argc,
    const char** argv
    ) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

std::string parseSourceString(const char* arg) {
    std::string sourceString(arg);

    if (sourceString.find_first_not_of("abcdefghijklmnopqrstuvwxyz")
        != std::string::npos) {
        throw std::runtime_error("Wrong string format!");
    }

    return sourceString;
}

int parseKey(const char* arg) {
    char* end;
    int key = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::runtime_error("Wrong number format!");
    }

    return key;
}

char parseOperation(const char* arg) {
    char op;
    if (!strcmp(arg, "decrypt")) {
        op = 'd';
    } else if (!strcmp(arg, "encrypt")) {
        op = 'e';
    } else {
        throw std::runtime_error("Wrong operation format!");
    }
    return op;
}

std::string GronsfeldCipherApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.sourceString = parseSourceString(argv[1]);
        args.key = parseKey(argv[2]);
        args.operation = parseOperation(argv[3]);
    }
    catch(std::runtime_error& e) {
        return std::string(e.what());
    }

    GronsfeldCipher cipherObj(args.sourceString, args.key);

    std::ostringstream stream;
    switch (args.operation) {
     case 'd':
        stream << cipherObj.decode(args.sourceString, args.key);
        break;
     case 'e':
        stream << cipherObj.getCipher();
        break;
    }

    message_ = stream.str();

    return message_;
}
