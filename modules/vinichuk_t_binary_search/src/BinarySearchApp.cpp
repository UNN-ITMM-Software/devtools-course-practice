// Copyright 2024 Borisov Saveliy

#include <cstring>
#include <sstream>

#include "include/BinarySearchApp.h"
#include "include/BinarySearch.h"

std::string BinarySearchApplication::operator()(int argc, char* argv[]) {
    if (!validate(argc, argv)) {
        return mMessage;
    }

    std::vector<int> arr = parseInput<int>(argv[1]);
    int target = std::stoi(argv[2]);
    int index = binsearch::binary_search(arr, target);

    if (index != binsearch::NOT_LISTED) {
        mMessage = "Target found at index: " + std::to_string(index);
    } else {
        mMessage = "Target not found";
    }

    return mMessage;
}

bool BinarySearchApplication::validate(int argc, char* argv[]) {
    if (argc == 1 || (argc == 2 && std::strcmp(argv[1], "--help") == 0)) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        help(argv[0], "Incorrect number of arguments");
        return false;
    }

    try {
        std::stoi(argv[2]);
    }
    catch (const std::invalid_argument&) {
        mMessage = "Error: Invalid target value";
        return false;
    }
    catch (const std::out_of_range&) {
        mMessage = "Error: Target value is out of range";
        return false;
    }

    return true;
}

void BinarySearchApplication::help(const char* appName, const char* msg) {
    std::stringstream message;
    if (msg) message << "Error: " << msg << '\n';
    message << "Usage:\n";
    message << '\t' << appName << " <array> <target>\n";
    message << "Example:\n";
    message << '\t' << appName << " \"1 2 3 4 5\" 3\n";
    mMessage = message.str();
}

template<typename T>
std::vector<T> BinarySearchApplication::parseInput(std::string input) {
    std::vector<T> arr;
    std::stringstream ss(input);
    T temp;
    while (ss >> temp) {
        arr.push_back(temp);
    }
    return arr;
}
