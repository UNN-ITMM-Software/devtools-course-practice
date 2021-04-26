// Copyright 2021 Ostapovich Denis

#include <stdexcept>

#include "include/json-deserializer.h"

bool isJsonQuotes(char ch) {
    return ch == '\"';
}

Lexer::Lexer() {
    cursor = 0;
    string = "";
}

Lexer::Lexer(const std::string& string) {
    if (string.empty()) {
        throw std::invalid_argument("String can not be empty");
    }

    cursor = 0;
    this->string = string;
};

size_t Lexer::getCursor() {
    return cursor;
}

std::string Lexer::getString() {
    return string;
}

void Lexer::setString(const std::string& string) {
    this->string = string;
}

bool Lexer::isEOF() {
    return cursor == string.size();
}

Token Lexer::getNextToken() {
    if (!hasTokens()) {
        throw "No more tokens in string";
    }

    if (std::isdigit(string[cursor])) {
        std::string number;
        while (std::isdigit(string[cursor])) {
            number += string[cursor++];
        }

        return Token(TokenType::Number, number);
    }

    if (isJsonQuotes(string[cursor])) {
        std::string str;

        do {
            str += string[cursor++];
        } while (!isJsonQuotes(string[cursor]) && !isEOF());
        str += string[cursor++];

        return Token(TokenType::String, str);
    }



    throw "Unknown token type";
};

bool Lexer::hasTokens() {
    return cursor < string.size();
}

JsonDeserializer::JsonDeserializer() {
    lexer = Lexer();
    string = "";
};

std::string JsonDeserializer::getString() {
    return string;
}

Lexer JsonDeserializer::getLexer() {
    return lexer;
}

Json JsonDeserializer::fromString(const std::string& jsonString) {
    if (jsonString.size() == 0) {
        throw std::invalid_argument("String can not be empty");
    }

    Json json;

    return json;
}
