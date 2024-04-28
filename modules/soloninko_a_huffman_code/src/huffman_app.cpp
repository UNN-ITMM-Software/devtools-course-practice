// Copyright 2024 Lesnikov Nikita

#include "include/huffman_app.h"

std::string HuffmanApp::operator()(int argc, char** argv) {
    std::string validateStr = _validate(argc, argv);
    if (validateStr.size() > 0) {
        return validateStr;
    }
    if (argc == 1) {
        return _help(argv[0]);
    } else if (argc == 2) {
        return _encode(argc, argv);
    }
    return _decode(argc, argv);
}

std::string HuffmanApp::_encode(int argc, char** argv) {
    std::string data = argv[1];
    std::stringstream message;

    Huffman huffman;

    huffman.buildHuffmanTree(data);
    std::string encoded = huffman.encode(data);
    std::unordered_map<char, std::string> codes =
        huffman.getHaffmanCodesCharStr();

    message << encoded << " ";

    for (const auto& i : codes) {
        message << i.first << " " << i.second << " ";
    }

    return message.str();
}

std::string HuffmanApp::_decode(int argc, char** argv) {
    Huffman huffman;

    return huffman.decode(argv[1], _getCodes(argc, argv));
}

std::unordered_map<std::string, char> HuffmanApp::_getCodes(
    int argc, char** argv) {
    std::unordered_map<std::string, char> codes;

    for (int i = 2; i < argc - 1; i += 2) {
        codes[argv[i + 1]] = argv[i][0];
    }

    return codes;
}

std::string HuffmanApp::_validate(int argc, char** argv) {
    if (!_validateNumArgs(argc)) {
        return "Incorrect number of arguments!";
    }
    if (argc > 2 && !_validateEncoded(argv[1])) {
        return "Invalid string for decoding!";
    }
    if (!_validateCodes(argc, argv)) {
        return "Invalid codes!";
    }
    return "";
}

bool HuffmanApp::_validateNumArgs(int num) {
    return num == 1 || num % 2 == 0;
}
bool HuffmanApp::_validateEncoded(const char* str) {
    for (int i = 0; i < static_cast<int>(strlen(str)); i++) {
        if (str[i] != '1' && str[i] != '0') {
            return false;
        }
    }
    return true;
}

bool HuffmanApp::_validateCodes(int argc, char** argv) {
    for (int i = 2; i < argc - 1; i += 2) {
        if (strlen(argv[i]) > 1) {
            return false;
        }
        if (!_validateEncoded(argv[i + 1])) {
            return false;
        }
    }
    return true;
}

std::string HuffmanApp::_help(const char* appName) {
    std::stringstream message;
    message << "This is an application that allows you to ";
    message << "find the optimal Huffman code for a given sequence ";
    message << "of characters.This operation ";
    message << "allows you to compress data.\n ";
    message << "For encoding, you must enter the data to be compressed in ";
    message << "text format.\n";
    message << appName << " abc\n";
    message << "The output will be a compressed string and ";
    message << "a list of new character codes.\n ";
    message << "To decode, you must enter a string and a list of ";
    message << "character codes in the format:\n";
    message << appName << " 10101001 a 10101 b 110 ....";
    return message.str();
}
