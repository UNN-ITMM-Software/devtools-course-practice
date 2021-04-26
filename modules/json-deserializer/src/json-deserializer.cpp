// Copyright 2021 Ostapovich Denis

#include <stdexcept>
#include <string>
#include <regex> 

#include "include/json-deserializer.h"

std::string lslice(const std::string& src, int count) {
    std::string dst(src);
    dst.erase(dst.begin(), dst.begin() + count);
    return dst;
}

std::string rslice(const std::string& src, int count) {
    std::string dst(src);
    dst.erase(dst.end(), dst.end() + count);
    return dst;
}

std::string slice(const std::string& src, int fromStart, int fromEnd) {
    auto res = lslice(src, fromStart);
    return rslice(res, fromEnd);
}

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
}

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

    auto sliced = lslice(string, cursor);

    std::regex expression("^[0-9]+");
    std::smatch matched;
    std::regex_search(sliced, matched, expression);
    if (!matched.empty()) {
        cursor += matched[0].length();
        return Token(TokenType::Number, matched[0]);
    }

    std::regex_search(sliced, matched, std::regex("^\"[^\"]*\""));
    if (!matched.empty()) {
        cursor += matched[0].length();
        return Token(TokenType::String, matched[0]);
    }


    throw "Unknown token type";
}

bool Lexer::hasTokens() {
    return cursor < string.size();
}

JsonDeserializer::JsonDeserializer() {
    lexer = Lexer();
    string = "";
}

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
