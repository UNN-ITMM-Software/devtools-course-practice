// Copyright 2021 Anastasia Kurnikova

#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>

#include "include/avl_application.h"

std::string CAvlApplication::operator()(int argc, const char ** argv) {
    if (ValidateArguments(argc, argv)) {
        int64_t key;
        switch (xmap[_op]) {
        case 0:
            key = _avl.Find(_searchElem);
            return std::string(std::to_string(key));
            break;
        case 2:
            key = _avl.FindMax();
            return std::string(std::to_string(key));
            break;
        case 1:
            key = _avl.FindMin();
            return std::string(std::to_string(key));
            break;
        }
    }
    return _message;
}

void CAvlApplication::Help(const char* appname, const std::string& message) {
    _message = std::string(message) +
        "\n\nThis is an avl application.\n"
        "Please provide arguments in the following format:\n\n"
        "$ " + appname +
        + " <key_1> <key_2> ... <key_k> <operation> <key>\n\n"
        "Where word_key is string and word_value is integer number, " +
        "and <operation> is one of\n"
        "-s' - search element,\n"
        "-smin' - search min element,\n"
        "-smax' - search max elemet,\n";
}

bool CAvlApplication::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc < 3) {
        Help(argv[0], "ERROR: Should be at least 2 arguments.\n\n");
        return false;
    }
    return true;
}

bool CAvlApplication::ValidateArguments(int argc, const char ** argv) {
    if (!ValidateNumberOfArguments(argc, argv))
        return false;
    const char* itOp = nullptr;
    int indexOperation = 0;
    for (; indexOperation != argc; indexOperation++)
        if (strcmp(argv[indexOperation], "-s") == 0
        || strcmp(argv[indexOperation], "-smin") == 0
        || strcmp(argv[indexOperation], "-smax") == 0) {
            itOp = argv[indexOperation];
            break;
        }
    if (itOp) {
        int i = 1;
        while (i < indexOperation) {
            try {
                _avl.Insert(key(std::stoi(argv[i])));
            }
            catch(const std::exception &e) {
                Help(argv[0], "Invalid key!" + std::string(e.what()));
                return false;
            }
            i++;
        }
        if (i == indexOperation) {
            _op = itOp;
            if (xmap[_op] == 0) {
                if (i + 1 != argc) {
                    _searchElem = std::stoi(argv[i + 1]);
                    return true;
                } else {
                    Help(argv[0], "Invalid search element!");
                    return false;
                }
            }
            return true;
        }
    }
    Help(argv[0], "Invalid operation!");
    return false;
}
