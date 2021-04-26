// Copyright 2021 Ostapovich Denis

#ifndef MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_
#define MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_

#include <string>

enum class TokenType {
    Number,
    String,
    Object,
    Array,
    Boolean,
    Null
};

struct Json {
    Json() {}
    Json(const Json& other) {}
};

struct Token {
    TokenType type;
    std::string value;

    Token(const TokenType type, const std::string value) {
        this->type = type;
        this->value = value;
    }

    Token(const Token& other) {
        this->type = other.type;
        this->value = other.value;
    }
};

class Lexer {
public:
    Lexer();
    explicit Lexer(const std::string& string);

    std::string getString();
    size_t getCursor();
    void setString(const std::string& string);
    Token getNextToken();
    bool hasTokens();
    bool isEOF();
private:
    std::string string;
    size_t cursor;
};

class JsonDeserializer {
public:
    JsonDeserializer();

    Json fromString(const std::string& jsonString);
    std::string getString();
    Lexer getLexer();
private:
    Lexer lexer;
    std::string string;
};

#endif  // MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_
