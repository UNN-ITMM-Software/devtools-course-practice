// Copyright 2021 Ostapovich Denis

#ifndef MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_
#define MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_

#include <string>
#include <regex>
#include <list>
#include <utility>
#include <ostream>
#include <ostream>
#include <map>

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
    RightBracket,
    Eof
};

inline
std::ostream& operator<<(std::ostream& out, const TokenType& type) {
    switch (type) {
    case TokenType::Number: {
        out << "Number";
        break;
    }
    case TokenType::String: {
        out << "String";
        break;
    }
    case TokenType::Object: {
        out << "Object";
        break;
    }
    case TokenType::Array: {
        out << "Array";
        break;
    }
    case TokenType::Boolean: {
        out << "Boolean";
        break;
    }
    case TokenType::Null: {
        out << "Null";
        break;
    }
    case TokenType::Whitespace: {
        out << "Whitespace";
        break;
    }
    case TokenType::Delimiter: {
        out << "Delimiter";
        break;
    }
    case TokenType::Colon: {
        out << "Colon";
        break;
    }
    case TokenType::LeftBrace: {
        out << "LeftBrace";
        break;
    }
    case TokenType::RightBrace: {
        out << "RightBrace";
        break;
    }
    case TokenType::LeftBracket: {
        out << "LeftBracket";
        break;
    }
    case TokenType::RightBracket: {
        out << "RightBracket";
        break;
    }
    case TokenType::Eof: {
        out << "Eof";
        break;
    }
    }

    return out;
};

enum class NodeType {
    UnknownLiteral,
    NumericLiteral,
    StringLiteral,
    ObjectLiteral,
    ArrayLiteral,
    BooleanLiteral,
    Null
};

using specification = std::pair<TokenType, std::string>;

struct JsonNode {
    NodeType nodeType;

    JsonNode() : nodeType(NodeType::UnknownLiteral) { }

    JsonNode(const NodeType type) : nodeType(type) { }

    JsonNode(const JsonNode& other) : nodeType(other.nodeType) { }
};

class JsonDocument {
 public:
     JsonDocument();
     JsonNode getRoot();
     void setRoot(const JsonNode rootNode);
 private:
     JsonNode* rootNode{ nullptr };
     std::map<std::string, JsonNode> fields;
};

struct Token {
    TokenType tokenType;
    std::string value;

    Token(const TokenType type, const std::string value = "") {
        this->tokenType = type;
        this->value = value;
    }

    Token(const Token& other) {
        this->tokenType = other.tokenType;
        this->value = other.value;
    }

    friend bool operator==(const Token& lhs, const Token& rhs) {
        return lhs.tokenType == rhs.tokenType
            && lhs.value == rhs.value;
    }

    friend bool operator!=(const Token& lhs, const Token& rhs) {
        return !(lhs == rhs);
    }

    friend std::ostream& operator<<(std::ostream& out, const Token& token) {
        out << "{\n\tType: " << token.tokenType << std::endl;
        out << "\tValue: \"" << token.value << "\"\n}" << std::endl;

        return out;
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
    std::vector<Token> getTokens();
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

    JsonDocument parse(const std::string& jsonString);
    std::string getString();
    Lexer getLexer();
 private:
    Lexer lexer;
    Token* lookahead;
    std::string string;
    Token eat(const TokenType tokenType);
    JsonNode stringLiteral();
};

#endif  // MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_
