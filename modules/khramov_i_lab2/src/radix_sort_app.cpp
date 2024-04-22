// Copyright 2024 Pozdnyakov Vasya

#include "include/radix_sort_app.h"

#include <cstring>
#include <exception>

bool RadixSortApplication::Validate(int argc, char* argv[]) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    }
    bool inArray = false;
    for (int i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "--help") == 0) {
            Help(argv[0]);
            return false;
        } else if (std::strcmp(argv[i], "-a") == 0) {
            inArray = true;
        } else if (std::strcmp(argv[i], "-r") == 0) {
            order = false;
            if (inArray) inArray = false;
        } else if (inArray) {
            try {
                array.emplace_back(std::stoi(argv[i]));
            } catch (const std::exception& e) {
                Help(argv[0], "at least one of array elements is not number");
                return false;
            }
        } else {
            Help(argv[0], "incorrect input");
            return false;
        }
    }
    if (array.size() == 0) {
        Help(argv[0], "array elements are not entered");
        return false;
    }
    return true;
}

void RadixSortApplication::Help(const char* appName, const char* errorMsg) {
    if (errorMsg != nullptr) {
        returnMsg += "Error: ";
        returnMsg += errorMsg;
        returnMsg += '\n';
    }
    returnMsg += "Usage:\n";
    returnMsg += '\t';
    returnMsg += appName;
    returnMsg += " -a <number1 number2 ...> = input integer array\n";
    returnMsg += '\t';
    returnMsg += appName;
    returnMsg += " -r = reverse sorting\n";
}

std::string RadixSortApplication::Sort(int argc, char* argv[]) {
    if (Validate(argc, argv)) {
        RadixSort<int>::radixSort(array, order);
        for (size_t i = 0; i < array.size(); i++) {
            returnMsg += std::to_string(array[i]);
            returnMsg += ' ';
        }
        returnMsg += '\n';
    }
    return returnMsg;
}
