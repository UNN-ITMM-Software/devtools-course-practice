// Copyright 2021 Ostapovich Denis

#include <stdexcept>
#include <string>
#include <regex>
#include <list>
#include <utility>
#include <sstream>

#include "include/json-deserializer.h"

std::string sliceLeft(const std::string& src, int count) {
    std::string dst(src);
    dst.erase(dst.begin(), dst.begin() + count);
    return dst;
}

std::string sliceRight(const std::string& src, int count) {
    std::string dst(src);
    dst.erase(dst.end(), dst.end() + count);
    return dst;
}

std::string slice(const std::string& src, int fromStart, int fromEnd) {
    auto res = sliceLeft(src, fromStart);
    return sliceRight(res, fromEnd);
}

Lexer::Lexer() : cursor(0), string("") { }

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

Token Lexer::getNextToken() {
    if (!hasTokens()) {
        throw "No more tokens in string";
    }

    auto sliced = sliceLeft(string, cursor);

    for (auto spec : specifications) {
        auto matchedValue = match(spec.second, sliced);

        if (matchedValue.empty()) {
            continue;
        }

        if (spec.first == TokenType::Whitespace) {
            return this->getNextToken();
        }

        return Token(spec.first, matchedValue);
    }

    std::stringstream ss;
    ss << "Syntax error, unexpected token: " << sliced[0] << std::endl;

    throw ss.str();
}

std::string Lexer::match(const std::string& expression,
    const std::string& src) {
    std::smatch matched;
    std::regex_search(src, matched, std::regex(expression));
    cursor += matched[0].length();
    return matched[0];
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
