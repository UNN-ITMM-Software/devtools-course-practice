// Copyright 2024 Moiseev Nikita

#include "include/ra_convertor_app.h"

#include <cstring>
#include <sstream>

bool ConverterApplication::validate(int argc, char* argv[]) {
    if (argc < 2) {
        help(argv[0]);
        return false;
    }
    if (std::strcmp(argv[1], "--help") == 0) {
        help(argv[0]);
        return false;
    }
    std::string input(argv[1]);
    Convertor convertor;
    try {
        int arabic_num = std::stoi(input);
        if (arabic_num < 1 || arabic_num > 15000) {
            help(argv[0], "Input must be greater than 0 and less than 15000");
            return false;
        }
    }
    catch (const std::invalid_argument&) {
        if (!convertor.isRomanValid(input)) {
            help(argv[0], "Incorrect input");
            return false;
        }
    }

    return true;
}

void ConverterApplication::help(const char* appName, const char* msg) {
    std::stringstream message;

    if (msg) message << "Error: " << msg << '\n';

    message << "This is an application for converting Roman numerals "
        << "to Arabic and vice versa\n";
    message << "Please provide a single Roman or Arabic numeral argument.\n\n";
    message << "Example usage:\n";
    message << " $ " << appName << " IX\n";
    message << " $ " << appName << " 9\n";

    hullMessage = message.str();
}

std::string ConverterApplication::operator()(int argc, char* argv[]) {
    if (validate(argc, argv)) {
        std::string input(argv[1]);
        Convertor convertor;

        try {
            int arabic_num = std::stoi(input);
            hullMessage = convertor.ArabicToRoman(arabic_num);
        }
        catch (const std::invalid_argument&) {
            int arabic_num = convertor.RomanToArabic(input);
            hullMessage = std::to_string(arabic_num);
        }
    }
    return hullMessage;
}
