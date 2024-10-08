// Copyright 2024 Tushentsova Karina

#include <cstring>
#include <exception>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "include/Combinations.h"
#include "include/Combinations_app.h"

void CombinationsApp::help(const char* appName, const char* errorMessage) {
    std::stringstream message;

    if (errorMessage) {
        message << "Error: " << errorMessage << '\n';
    }

    message << "Generator of all possible combinations of k array elements\n"
        << "Usage: " << appName << " \"<array>/<k>\"\n\n"
        << "Enter the array elements separated by commas, a fraction at "
        << "the end, \nand the number of elements in the permutation\n"
        << "Make sure to enclose the expression in double quotes.\n\n"
        << "Examples:\n"
        << appName << " \"1,2,3/2\"";

    helpMssg = message.str();
}

bool CombinationsApp::validate(int argc, char* argv[]) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }

    if (std::strcmp(argv[1], "--help") == 0) {
        help(argv[0]);
        return false;
    }

    if (argc != 2) {
        help(argv[0], "You have to enter two arguments\n");
        return false;
    }
    input = argv[1];
    return true;
}

std::string CombinationsApp::operator()(int argc, char* argv[]) {
    if (validate(argc, argv)) {
        std::string str = input;
        std::vector<int> arr;
        std::string part;
        int k;

        size_t index_k = str.find('/');
        if (index_k == std::string::npos) {
            helpMssg = "Error: Add '/' to the request";
            return helpMssg;
        }

        std::string k_str = str.substr(index_k + 1);
        if (k_str.empty()) {
            helpMssg = "Error: Add <k> to the request";
            return helpMssg;
        } else {
            k = stoi(k_str);
        }

        if (k == 0) {
            helpMssg = "Error: <k> cannot be equal to 0";
            return helpMssg;
        }

        str.erase(index_k + 1);
        if (str == "/") {
            helpMssg = "Error: Enter the array";
            return helpMssg;
        }

        int i = 0;

        while (str[i]) {
            if (str[i] == ',' || str[i] == '/') {
                arr.push_back(stoi(part));
                part = "";
            } else {
                part += str[i];
            }
            i++;
        }

        auto vec = generateCombinations(arr, k);

        int n = static_cast<int>(vec.size());
        std::string result = "{";
        for (int i = 0; i < n; i++) {
            result += " { ";
            for (int j = 0; j < k; j++)
                result += std::to_string(vec[i][j]) + ", ";
            result.pop_back();
            result.pop_back();
            result += " },";
        }
        result.pop_back();
        result += " }";

        helpMssg += "Result: " + result;
    }
    return helpMssg;
}
