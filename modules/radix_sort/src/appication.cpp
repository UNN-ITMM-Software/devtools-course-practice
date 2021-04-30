// Copyright 2021 Kolesin Andrey
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

#include "include/application.h"

const char Application::NOT_INTEGER[] = "Some argumnets are not integers";
const char Application::OUT_OF_RANGE[] = "Some argumnets are out of range";
Application::Application() {}

bool isInt(std::string s) {
    int start = (s[0] == '-') ? 1 : 0;
    for (size_t i = start; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

std::string Application::operator()(int argc, const char** argv) {
    arr = std::vector<int>();
    if (argc == 1) {
        return help(argv[0]);
    }
    try {
        for (int i = 1; i < argc; i++) {
            if (!isInt(argv[i])) {
                throw -1;
            }
            int integer = std::stoi(argv[i]);
            arr.push_back(integer);
        }
    } catch (int e) {
        if (e == -1) {
            return NOT_INTEGER;
        } else {
            throw;
        }
    } catch (std::invalid_argument e) {
        return NOT_INTEGER;
    } catch (std::out_of_range e) {
        return OUT_OF_RANGE;
    }
    RadixSort::radixSort<int>(arr.begin(), arr.end());
    std::string result = "";
    for (size_t i = 0; i < arr.size(); i++) {
        if (i > 0) {
            result += " ";
        }
        result += std::to_string(arr[i]);
    }
    return result;
}

std::vector<int> Application::getArr() const { return arr; }

std::string Application::help(const char* appname) {
    return std::string("This is a radix sort application.\n") +
           "Please provide some integers to sort.\nExample: \n" +

           " $ " + appname + " 3 -5 1000 3023";
}
