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

JsonDeserializer::JsonDeserializer(): lexer(Lexer()), lookahead(nullptr) { }

JsonDeserializer::JsonDeserializer(const std::string& str) : lexer(Lexer(str)),
lookahead(nullptr) { }

Lexer JsonDeserializer::getLexer() {
    return lexer;
}

JsonNode& JsonDocument::operator[](std::string key)
{
    if (!rootNode) {
        rootNode = new JsonNode();
    }

    return rootNode->getData()[key];
}

JsonNode& JsonDocument::operator[](int index)
{
    if (!rootNode) {
        rootNode = new JsonNode();
    }

    return rootNode->getData()[index];
}

JsonDocument JsonDeserializer::parse() {
    lookahead = new Token(lexer.getNextToken());

    JsonDocument document;
    document.setRoot(literal());

    return document;
}

JsonDocument JsonDeserializer::parse(const std::string& jsonString) {
    if (jsonString.size() == 0) {
        throw std::invalid_argument("String cannot be empty");
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

    lookahead = new Token(lexer.getNextToken());

    return token;
}

JsonNode JsonDeserializer::literal() {
    switch (lookahead->tokenType) {
    case TokenType::Number: {
        return numericLiteral();
    }
    case TokenType::String: {
        return stringLiteral();
    }
    case TokenType::Null: {
        return nullLiteral();
    }
    case TokenType::Boolean: {
        return booleanLiteral();
    }
    case TokenType::LeftBracket: {
        return array();
    }
    case TokenType::LeftBrace: {
        return object();
    }
    default: {
        std::stringstream ss;
        ss << "Parse Error! Toke: " << *lookahead;
        throw ss.str();
    }
    }
}

JsonNode JsonDeserializer::numericLiteral() {
    Token token = eat(TokenType::Number);

    return JsonNode(NodeType::Numeric, JsonData(token.value));
}

JsonNode JsonDeserializer::stringLiteral() {
    Token token = eat(TokenType::String);

    return JsonNode(NodeType::String, JsonData(token.value));
}

JsonNode JsonDeserializer::nullLiteral() {
    Token token = eat(TokenType::Null);

    return JsonNode(NodeType::Null, JsonData(token.value));
}

JsonNode JsonDeserializer::booleanLiteral() {
    Token token = eat(TokenType::Boolean);

    return JsonNode(NodeType::Boolean, JsonData(token.value));
}

JsonNode JsonDeserializer::array() {
    Token token = eat(TokenType::LeftBracket);

    JSONArray array;
    JsonNode nextToken = literal();
    NodeType expectedNodeType = nextToken.getNodeType();
    while(nextToken.getNodeType() == expectedNodeType) {
        array.push_back(nextToken);
        nextToken = literal();
    }

    return JsonNode(NodeType::Array, JsonData(array));
}

JsonNode JsonDeserializer::object() {
    Token token = eat(TokenType::LeftBrace);

    JSONObject object;

    return JsonNode(NodeType::Object, JsonData(object));
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

    if (rootNode.getNodeType() != NodeType::Unknown) {
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

JsonNode::JsonNode() : nodeType(NodeType::Unknown), data(nullptr) { }

JsonNode::JsonNode(const NodeType type) : nodeType(type), data(nullptr) { }

JsonNode::JsonNode(const JsonNode& other) {
    this->nodeType = other.nodeType;
    if (other.data) {
        this->data = new JsonData(*other.data);
    }
    else {
        this->data = nullptr;
    }
}

JsonNode::JsonNode(const NodeType type, const JsonData& data) {
    this->nodeType = type;
    this->data = new JsonData(data);
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

void JsonNode::setData(const JsonData& data) {
    JsonData copy = JsonData(data);
}

JsonData& JsonNode::getData() {
    return *data;
}

JsonData::JsonData() { }

JsonData::JsonData(const std::string value) {
    this->value = value;
}

JsonData::JsonData(const JSONObject& object) {
    this->object = object;
}

JsonData::JsonData(const JSONArray& array) {
    this->array = array;
}

JsonData::JsonData(const JsonData& other) {
    array = other.array;
    value = other.value;
    object = other.object;
}

std::string& JsonData::getValue() {
    return value;
}

JsonNode& JsonData::operator[](std::string key) {
    return object[key];
}

JsonNode& JsonData::operator[](int index) {
    return array[index];
}
