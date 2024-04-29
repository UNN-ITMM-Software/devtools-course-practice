// Copyright 2024 Chuvashov Andrey

#include "../include/batcher_merge_app.h"

bool BatcherMergeApplication::validate(int argc, char* argv[]) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    bool inArray = false;
    for (int i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "--help") == 0) {
            help(argv[0]);
            return false;
        } else if (std::strcmp(argv[i], "-init") == 0) {
            inArray = true;
        } else if (inArray) {
            try {
                array.emplace_back(std::stoi(argv[i]));
            } catch (const std::exception& e) {
                help(argv[0], "array contains not a number element");
                return false;
            }
        } else {
            help(argv[0], "invalid input");
            return false;
        }
    }
    if (array.size() == 0) {
        help(argv[0], "array is empty");
        return false;
    }
    return true;
}

void BatcherMergeApplication::help(const char* appName,
    const char* errorMessage) {
    if (errorMessage != nullptr) {
        returnMessage += "Error: ";
        returnMessage += errorMessage;
        returnMessage += '\n';
    }
    returnMessage += "Usage:\n";
    returnMessage += '\t';
    returnMessage += appName;
    returnMessage += " -init <int_1 int_2 ...> = input int array\n";
}

std::string BatcherMergeApplication::Sort(int argc, char* argv[]) {
    if (validate(argc, argv)) {
        BatcherMerge<int>::batcherMerge(array);
        for (size_t i = 0; i < array.size(); i++) {
            returnMessage += std::to_string(array[i]);
            returnMessage += ' ';
        }
        returnMessage += '\n';
    }
    return returnMessage;
}
