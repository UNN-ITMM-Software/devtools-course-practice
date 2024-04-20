// Copyright 2024 Pozdnyakov Vasya

#include "include/radix_sort_app.h"

#include <cstring>
#include <exception>

bool RadixSortApplication::Validate(int argc, char* argv[]) {
    if (argc == 1) {
        Help();
        return false;
    }
    bool inArray = false;
    for (int i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "--help") == 0) {
            Help();
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
                Help("at least one of array elements is not number");
                return false;
            }
        } else {
            Help("incorrect input");
            return false;
        }
    }
    if (array.size() == 0) {
        Help("array elements are not entered");
        return false;
    }
    return true;
}

void RadixSortApplication::Help(const char* errorMsg) {
    if (errorMsg != nullptr) {
        returnMsg += "Error: ";
        returnMsg += errorMsg;
        returnMsg += '\n';
    } 
    returnMsg += "Ussage:\n";
    returnMsg += "\t-a <array> = input int array\n";
    returnMsg += "\t-r = reverse sorting\n";
}

std::string RadixSortApplication::Sort(int argc, char* argv[]) {
    if (Validate(argc, argv)){
        RadixSort<int>::radixSort(array, order);
        for (size_t i = 0; i < array.size(); i++) {
            returnMsg += std::to_string(array[i]);
            returnMsg += ' ';
        }
        returnMsg += '\n';
    }
    return returnMsg;
    
}