// Copyright 2021 Ostapovich Denis

#ifndef MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_
#define MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_

#include <string>
#include <regex>
#include <list>
#include <utility>

enum class TokenType {
    Number,
    String,
    Object,
    Array,
    Boolean,
    Null,
    Whitespace,
    Delimiter,
    Colon,
    LeftBrace,
    RightBrace,
    LeftBracket,
    RightBracket
};

using specification = std::pair<TokenType, std::string>;

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
 private:
     std::list<specification> specifications {
        specification(TokenType::String, "^\"[^\"]*\""),
        specification(TokenType::Number, "^-?\\d+"),
        specification(TokenType::Whitespace, "^\\s+"),
        specification(TokenType::Null, "^null"),
        specification(TokenType::Boolean, "^(true|false)"),
        specification(TokenType::Delimiter, "^,"),
        specification(TokenType::Colon, "^:"),
        specification(TokenType::LeftBrace, "^\\{"),
        specification(TokenType::RightBrace, "^\\}"),
        specification(TokenType::LeftBracket, "^\\["),
        specification(TokenType::RightBracket, "^\\]"),
     };
    std::string string;
    size_t cursor;
    std::string match(const std::string& expression, const std::string& src);
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
