// Copyright 2024 Vinichuk Timofey
#include "../include/base64_converter_app.h"
#include <sstream>

bool Base64ConverterApplication::validate(int argc, char* argv[]) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        help(argv[0]);
        return false;
    } else if (argc == 3 && strcmp(argv[1], "ENCODE") != 0
                         && strcmp(argv[1], "DECODE") != 0) {
        help(argv[0], "Incorrect second argument");
        return false;
    } else if (argc != 3) {
        help(argv[0], "Incorrect number of arguments");
        return false;
    }
    return true;
}


void Base64ConverterApplication::help(const char* appname,
                                        const char* message) {
    std::ostringstream stream;
    std::string str = message ? "Error: " + std::string(message) + "\n" : "";
    stream << str;
    stream << "This application does Base64 encoding and decoding.\n";
    stream << "Arguments must come in the following format:\n";
    stream << " <operation> - The action you need: ENCODE or DECODE .\n";
    stream << " <input_string> - Encoded or decoded string.\n";

    message_ = stream.str();
}

std::string Base64ConverterApplication::operator()(int argc, char* argv[]) {
    if (validate(argc, argv)) {
        std::string operation = std::string(argv[1]);
        std::string input_string = std::string(argv[2]);
        std::ostringstream stream;
        if (operation == "ENCODE") {
            Base64Encoder encoder = Base64Encoder(input_string);
            stream << "Encoded value: " << encoder.Encode() << "\n";
        } else {
            Base64Decoder decoder = Base64Decoder(input_string);
            std::string result;
            try {
                result = decoder.Decode();
                stream << "Decoded value: " << result << "\n";
            } catch (const std::runtime_error& e) {
                stream << "Undencoded string format!\n";
            }
        }
        message_ = stream.str();
    }
    return message_;
}
