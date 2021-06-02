// Copyright 2021 Mishin Ilya

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/cipher.h"
#include "include/ceasar_application.h"

std::string CeasarApplication::getHelp(const std::string& filename) const {
    return "This is an application that designed " \
        "for encryption and decryption Caesar chipher " \
        "for given arguments. \n\n" \
        "Please provide arguments in the following format:\n$ " +
        filename + " <-e \"encoded_string\"> or <-d" +
        " \"decoded_string\"> [-k key {default = 1}] \n\n" \
        "Example: " + filename + " -d \"cipher\" -k 2.\n\n";
}

int checkKey(const char* argv) {
    int i = 0;
    for (; argv[i] != '\0'; ++i) {
        if (argv[i] < '0' || argv[i] > '9') {
            throw std::runtime_error("ERROR: Wrong number format!\n");
        }
    }
    int x = std::stoi(argv);
    return x;
}

std::string CeasarApplication::operator()(int argc, const char** argv) const {
    if (argc != 3 && argc != 5) {
        return getHelp(argv[0]);
    }
    std::ostringstream ss;
    std::string cipher_str;
    int key = 1;
    bool decode;
    for (int i = 1; i < argc; ++i) {
        try {
            if (std::string(argv[i]) == "-e") {
                cipher_str = std::string(argv[i + 1]);
                ++i;
                decode = false;
            } else {
                if (std::string(argv[i]) == "-d") {
                    cipher_str = std::string(argv[i + 1]);
                    ++i;
                    decode = true;
                } else {
                    if (std::string(argv[i]) == "-k") {
                        key = checkKey(argv[i + 1]);
                        ++i;
                    } else {
                    throw std::runtime_error("ERROR: Wrong argument format!\n");
                    }
                }
            }
        }
        catch (std::exception& exc) {
            return exc.what() + getHelp(argv[0]);
        }
    }

    std::string res;
    CeasarCipher cipherator;
    if (decode) {
        res = cipherator.decode(cipher_str, key);
    } else {
        res = cipherator.encode(cipher_str, key);
    }

    ss << res;
    return ss.str();
}
