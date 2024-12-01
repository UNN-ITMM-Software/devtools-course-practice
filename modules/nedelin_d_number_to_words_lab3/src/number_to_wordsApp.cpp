// Copyright 2024 Nedelin Dmitry

#include "include/number_to_words.h"
#include "include/number_to_wordsApp.h"

#include <stdexcept>
#include <sstream>

#include <stdexcept>
#include <sstream>

std::vector<std::string> Application::runApp(int argc, const char** argv) {
    std::vector<std::string> output;

    if (argc != 2) {
        output.push_back("Usage: number_to_words <number>");
        return output;
    }

    std::string input = argv[1];
    try {
        output.push_back(processNumber(input));
    }
    catch (const std::invalid_argument&) {
        output.push_back("Invalid number format!");
    }

    return output;
}

std::string Application::processNumber(const std::string& input) {
    int number;
    try {
        number = std::stoi(input);
    }
    catch (...) {
        throw std::invalid_argument("Invalid input");
    }

    NumberToWords converter;
    return converter.convert(number);
}
