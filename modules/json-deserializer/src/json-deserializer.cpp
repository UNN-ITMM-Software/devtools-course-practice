// Copyright 2021 Ostapovich Denis

#include "include/json-deserializer.h"

#include <list>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using simpleds::JsonData;
using simpleds::JsonDeserializer;
using simpleds::JsonDocument;
using simpleds::JsonNode;
using simpleds::Lexer;
using simpleds::NodeType;
using simpleds::Token;

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

Lexer::Lexer() : cursor(0), string("") {}

Lexer::Lexer(const std::string& string) {
  if (string.empty()) {
    throw std::invalid_argument("String can not be empty");
  }

  cursor = 0;
  this->string = string;
}

size_t Lexer::getCursor() { return cursor; }

std::string Lexer::getString() { return string; }

void Lexer::setString(const std::string& string) { this->string = string; }

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

bool Lexer::hasTokens() { return cursor < string.size(); }

std::vector<Token> Lexer::getTokens() {
  std::vector<Token> tokens;
  while (hasTokens()) {
    tokens.push_back(getNextToken());
  }
  return tokens;
}

JsonDeserializer::JsonDeserializer() : lexer(Lexer()), lookahead(nullptr) {}

JsonDeserializer::JsonDeserializer(const std::string& str)
    : lexer(Lexer(str)), lookahead(nullptr) {}

Lexer JsonDeserializer::getLexer() { return lexer; }

JsonNode& JsonDocument::operator[](std::string key) {
  if (!rootNode) {
    rootNode = new JsonNode();
  }

  return rootNode->getData()[key];
}

JsonNode& JsonDocument::operator[](int index) {
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
    case TokenType::RightBracket: {
      Token token = eat(lookahead->tokenType);
      return JsonNode(NodeType::ArrayEnd, JsonData(token.value));
    }
    case TokenType::RightBrace: {
      Token token = eat(lookahead->tokenType);
      return JsonNode(NodeType::ObjectEnd, JsonData(token.value));
    }
    case TokenType::Colon: {
      Token token = eat(lookahead->tokenType);
      return JsonNode(NodeType::Colon, JsonData(token.value));
    }
    case TokenType::Delimiter: {
      Token token = eat(lookahead->tokenType);
      return JsonNode(NodeType::Delimiter, JsonData(token.value));
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

  return JsonNode(NodeType::String, JsonData(slice(token.value, 1, 1)));
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
  eat(TokenType::LeftBracket);

  JSONArray array;
  JsonNode nextNode = literal();
  NodeType expectedNodeType = nextNode.getNodeType();
  NodeType actualType = expectedNodeType;
  while (actualType != NodeType::ArrayEnd) {
    if (actualType == expectedNodeType) {
      array.push_back(nextNode);
    }
    nextNode = literal();
    actualType = nextNode.getNodeType();
  }

  return JsonNode(NodeType::Array, JsonData(array));
}

JsonDeserializer::~JsonDeserializer() { delete lookahead; }

JsonNode JsonDeserializer::object() {
  eat(TokenType::LeftBrace);

  JSONObject object;
  JsonNode nextNode = literal();

  while (nextNode.getNodeType() != NodeType::ObjectEnd) {
    switch (nextNode.getNodeType()) {
      case NodeType::String: {
        auto key = nextNode.getData().getValue();
        nextNode = literal();
        if (nextNode.getNodeType() != NodeType::Colon) {
          throw "Invalid assignment expression!";
        }
        nextNode = literal();
        object.insert(std::make_pair(key, nextNode));
        break;
      }
      case NodeType::Colon: {
        break;
      }
      case NodeType::Delimiter: {
        break;
      }
      default: {
        throw "Invalid object expression!";
      }
    }

    nextNode = literal();
  }

  return JsonNode(NodeType::Object, JsonData(object));
}

JsonDocument::JsonDocument() {
  rootNode = nullptr;
  isEmpty = true;
}

JsonDocument::JsonDocument(const JsonDocument& other) {
  isEmpty = other.isEmpty;
  if (other.rootNode) {
    rootNode = new JsonNode(*other.rootNode);
  } else {
    rootNode = nullptr;
  }
}

JsonDocument::~JsonDocument() { delete rootNode; }

JsonNode& JsonDocument::getRoot() const { return *rootNode; }

void JsonDocument::setRoot(const JsonNode& rootNode) {
  if (this->rootNode == nullptr) {
    this->rootNode = new JsonNode(rootNode);
  } else {
    *this->rootNode = rootNode;
  }

  if (rootNode.getNodeType() != NodeType::Unknown) {
    isEmpty = false;
  }
}

bool JsonDocument::empty() { return isEmpty; }

JsonDocument& JsonDocument::operator=(const JsonDocument& other) {
  if (this != &other) {
    rootNode = new JsonNode(other.getRoot());
    isEmpty = other.isEmpty;
  }

  return *this;
}

JsonNode::JsonNode() : nodeType(NodeType::Unknown), data(nullptr) {}

JsonNode::JsonNode(const NodeType type) : nodeType(type), data(nullptr) {}

JsonNode::JsonNode(const JsonNode& other) {
  this->nodeType = other.nodeType;
  if (other.data) {
    this->data = new JsonData(*other.data);
  } else {
    this->data = nullptr;
  }
}

JsonNode::JsonNode(const NodeType type, const JsonData& data) {
  this->nodeType = type;
  this->data = new JsonData(data);
}

JsonNode::~JsonNode() { delete data; }

JsonNode& JsonNode::operator=(const JsonNode& other) {
  if (this != &other) {
    nodeType = other.nodeType;

    if (!other.data) {
      data = nullptr;
    } else {
      if (!data) {
        data = new JsonData;
      }
      *data = *other.data;
    }
  }

  return *this;
}

NodeType JsonNode::getNodeType() const { return nodeType; }

void JsonNode::setData(const JsonData& data) {
  JsonData copy = JsonData(data);
  if (!this->data) {
    this->data = new JsonData;
  }

  *this->data = data;
}

JsonData& JsonNode::getData() {
  if (!data) {
    data = new JsonData;
  }

  return *data;
}

bool JsonNode::equals(const JsonNode& other) const {
  if (this->nodeType != other.nodeType) {
    return false;
  }

  if (!this->data && !other.data) {
    return true;
  }

  if (!this->data || !other.data) {
    return false;
  }

  return *this->data == *other.data;
}

JsonData::JsonData() {}

JsonData::JsonData(const std::string value) { this->value = value; }

JsonData::JsonData(const JSONObject& object) { this->object = object; }

JsonData::JsonData(const JSONArray& array) { this->array = array; }

JsonData::JsonData(const JsonData& other) {
  array = other.array;
  value = other.value;
  object = other.object;
}

std::string& JsonData::getValue() { return value; }

JsonNode& JsonData::operator[](std::string key) { return object[key]; }

JsonNode& JsonData::operator[](int index) { return array[index]; }

bool JsonData::equals(const JsonData& other) const {
  return this->object == other.object && this->array == other.array &&
         this->value == other.value;
}

JsonData& JsonData::operator=(const JsonData& other) {
  if (this != &other) {
    object = other.object;
    array = other.array;
    value = other.value;
  }

  return *this;
}

bool simpleds::operator==(const JsonNode& lhs, const JsonNode& rhs) {
  return lhs.equals(rhs);
}

bool simpleds::operator!=(const JsonNode& lhs, const JsonNode& rhs) {
  return !(lhs.equals(rhs));
}

bool simpleds::operator==(const JsonData& lhs, const JsonData& rhs) {
  return lhs.equals(rhs);
}

bool simpleds::operator!=(const JsonData& lhs, const JsonData& rhs) {
  return !(lhs.equals(rhs));
}

bool simpleds::operator==(const Token& lhs, const Token& rhs) {
  return lhs.equals(rhs);
}

bool simpleds::operator!=(const Token& lhs, const Token& rhs) {
  return !(lhs.equals(rhs));
}
