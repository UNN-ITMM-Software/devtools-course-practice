// Copyright 2024 Zhatkin Vyacheslav

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "include/sort_station_app.h"

void SortStationApp::help(const char* appName, const char* msg = nullptr) {
    std::stringstream ss;

    if (msg) ss << "Error: " << msg << '\n';

    ss << "Calculator for evaluating mathematical expressions\n";
    ss << "Provide an argument for the expression to evaluate\n";
    ss << "Example usage:\n";
    ss << " $ " << appName << " \"2+2*2\"\n";
    ss << " $ " << appName << " \"3*(4+2)\"\n";

    message_ = ss.str();
}

bool SortStationApp::validate(const int argc, char* argv[]) {
    if (argc != 2) {
        help(argv[0]);
        return false;
    }
    if (std::strcmp(argv[1], "--help") == 0) {
        help(argv[0]);
        return false;
    }
    return true;
}

std::string SortStationApp::operator()(const int argc, char* argv[]) {
    if (!validate(argc, argv)) {
        return message_;
    }

    try {
        std::string expression = argv[1];
        double result = sortStation.evaluateFunction(expression);
        message_ = "Result: " + std::to_string(result);
    }
    catch (const std::exception& e) {
        message_ = "Error: " + std::string(e.what());
    }
    return message_;
}
