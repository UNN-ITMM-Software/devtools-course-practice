// Copyright 2021 Ostapovich Denis

#include <stdexcept>
#include <string>
#include <regex>
#include <list>
#include <utility>
#include <sstream>

#include "..\include\json-deserializer.h"

std::string sliceLeft(const std::string& src, int count) {
    std::string dst(src);
    dst.erase(dst.begin(), dst.begin() + count);
    return dst;
}

std::string sliceRight(const std::string& src, int count) {
    std::string dst(src);
    dst.erase(dst.end() - count, dst.end());
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
        return Token(TokenType::Eof);
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

std::vector<Token> Lexer::getTokens() {
    std::vector<Token> tokens;
    while (hasTokens()) {
        tokens.push_back(getNextToken());
    }
    return tokens;
}

JsonDeserializer::JsonDeserializer() {
    lexer = Lexer();
    lookahead = nullptr;
    document = nullptr;
}

JsonDeserializer::JsonDeserializer(const std::string& str) {
    lexer = Lexer(str);
    lookahead = nullptr;
    document = nullptr;
}

Lexer JsonDeserializer::getLexer() {
    return lexer;
}

JsonDocument& JsonDeserializer::parse() {
    lookahead = new Token(lexer.getNextToken());
    document = new JsonDocument();

    document->setRoot(literal());

    return *document;
}

JsonDocument& JsonDeserializer::parse(const std::string& jsonString) {
    if (jsonString.size() == 0) {
        throw std::invalid_argument("String can not be empty");
    }

    lexer.setString(jsonString);

    return parse();
}

Token JsonDeserializer::eat(const TokenType expectedTokenType) {
    Token token = *lookahead;

    if (token.tokenType != expectedTokenType) {
        std::stringstream ss;
        ss << "Unexpected token: " << token.value << std::endl;

        throw ss.str();
    }

    lookahead = &lexer.getNextToken();

    return token;
}

JsonNode JsonDeserializer::literal() {
    switch (lookahead->tokenType) {
    case TokenType::String: {
        return stringLiteral();
    }
    case TokenType::Number: {
        return numericLiteral();
    }
    case TokenType::Null: {
        return nullLiteral();
    }
    case TokenType::Boolean: {
        return boolLiteral();
    }
    case TokenType::LeftBracket: {
        return arrayLiteral();
    }
    case TokenType::LeftBrace: {
        return objectLiteral();
    }
    default: {
        throw "Parse Error!";
    }
    }
}

JsonValue JsonDeserializer::stringLiteral() {
    Token token = eat(TokenType::String);
    return JsonValue(NodeType::StringLiteral, token.value);
}

JsonValue JsonDeserializer::numericLiteral() {
    Token token = eat(TokenType::Number);
    return JsonValue(NodeType::NumericLiteral, token.value);
}

JsonObject JsonDeserializer::objectLiteral() {
    JsonObject obj = JsonObject(NodeType::ObjectLiteral);

    return obj;
}

JsonNode JsonDeserializer::arrayLiteral() {
    return JsonNode(NodeType::ArrayLiteral);
}

JsonValue JsonDeserializer::boolLiteral() {
    Token token = eat(TokenType::Boolean);
    return JsonValue(NodeType::BooleanLiteral, token.value);
}

JsonValue JsonDeserializer::nullLiteral() {
    Token token = eat(TokenType::Null);
    return JsonValue(NodeType::Null, token.value);
}

JsonDocument::JsonDocument() {
    rootNode = nullptr;
    isEmpty = false;
}

JsonDocument::JsonDocument(const JsonDocument& other) {
    isEmpty = other.isEmpty;
    rootNode = new JsonNode(*other.rootNode);
}

JsonNode& JsonDocument::getRoot() {
    return *rootNode;
}

void JsonDocument::setRoot(const JsonNode& rootNode) {
    if (this->rootNode == nullptr) {
        this->rootNode = new JsonNode(rootNode);
    }
    else {
        *this->rootNode = rootNode;
    }

    if (rootNode.getNodeType() != NodeType::UnknownLiteral) {
        isEmpty = false;
    }
}

bool JsonDocument::empty()
{
    return isEmpty;
}

//JsonDocument& JsonDocument::operator=(const JsonDocument& other) {
//    if (this == &other) {
//        return *this;
//    }
//
//    rootNode = new JsonNode;
//    *rootNode = *other.rootNode;
//
//    return *this;
//}

JsonArray::JsonArray() :
    JsonNode(), dataType(TokenType::Unknown),size(0), jsonArray(std::vector<JsonNode>()) { }

JsonNode::JsonNode() : nodeType(NodeType::UnknownLiteral) { }

JsonNode::JsonNode(const NodeType type) : nodeType(type) { }

JsonNode::JsonNode(const JsonNode& other) {
    this->nodeType = other.nodeType;
}

JsonNode::~JsonNode(){}

JsonNode& JsonNode::operator=(const JsonNode& other) {
    if (this == &other) {
        return *this;
    }

    nodeType = other.nodeType;

    return *this;
}

NodeType JsonNode::getNodeType() const {
    return nodeType;
}

JsonObject::JsonObject(NodeType nodeType) : JsonNode(nodeType) { }

JsonValue::JsonValue(NodeType nodeType, const std::string& value) :
    JsonNode(nodeType), value(value) { }

JsonValue::JsonValue(const JsonValue& other) : JsonNode(other){
    value = other.value;
}

JsonValue& JsonValue::operator=(const JsonValue& other) {
    if (this == &other) {
        return *this;
    }

    nodeType = other.nodeType;
    value = other.value;

    return *this;
}

std::string JsonValue::getValue() {
    return value;
}
