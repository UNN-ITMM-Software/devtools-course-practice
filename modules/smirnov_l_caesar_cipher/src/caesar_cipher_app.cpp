// Copyright 2024 Khodyrev Fedor

#include "include/caesar_cipher_app.h"

#include <cstring>
#include <exception>
#include <sstream>

bool CaesarCipherApplication::Validate(int argc, char *argv[]) {
    int required_argc = 4;
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (std::strcmp(argv[1], "--help") == 0) {
        Help(argv[0]);
        return false;
    } else if (std::strcmp(argv[2], "encryption") != 0
     && std::strcmp(argv[2], "decryption") != 0) {
        Help(argv[0], "Operation must be either 'encryption' or 'decryption'.");
        return false;
    } else if (argc != required_argc) {
        Help(argv[0], "Incorrect number of arguments.");
        return false;
    } else {
        try {
            int offset = std::stoi(argv[1]);

            cipher = CaesarCipher(offset);
        } catch(const std::exception& e) {
            Help(argv[0], "Invalid arguments.");
            return false;
        }
    }
    return true;
}

void CaesarCipherApplication::Help(const char *application,
                                         const char *errMsg) {
    std::stringstream message;

    if (errMsg) {
        message << "Error: " << errMsg << '\n';
    }

    message << "Usage:\n";
    message << '\t' << application << " <offset> <operation> <string>\n";
    message << "Where:\n";
    message << '\t' << " <offset> is offset during encryption/decryption\n";
    message << '\t' << " <operation> is the current operation\n";
    message << '\t' << " <string> is the input\n";
    msg = message.str();
}

std::string CaesarCipherApplication::CaesarCipherCryptography
(int argc, char *argv[]) {
    if (Validate(argc, argv)) {
        try {
            if (std::strcmp(argv[2], "encryption") == 0) {
                std::string output = cipher.CaesarCipherEncoder(argv[3]);
                return output;
            } else if (std::strcmp(argv[2], "decryption") == 0) {
                std::string output = cipher.CaesarCipherDecoder(argv[3]);
                return output;
            }
        }
        catch(const std::exception& e) {
            return "Error: Invalid input.";
        }
    }
    return msg;
}
