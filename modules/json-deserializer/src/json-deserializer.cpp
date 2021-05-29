// Copyright 2021 Ostapovich Denis

#include "include/json-deserializer.h"

#include <algorithm>
#include <list>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using simpleDeserializer::JSONData;
using simpleDeserializer::JSONDeserializer;
using simpleDeserializer::JSONDocument;
using simpleDeserializer::JSONNode;
using simpleDeserializer::Lexer;
using simpleDeserializer::NodeType;
using simpleDeserializer::Token;
using simpleDeserializer::TokenType;

bool simpleDeserializer::equalsIgnoreCase(std::string lhs, std::string rhs) {
  std::transform(lhs.begin(), lhs.end(), lhs.begin(), ::tolower);
  std::transform(rhs.begin(), rhs.end(), rhs.begin(), ::tolower);

  return lhs.compare(rhs) == 0;
}

std::ostream& simpleDeserializer::operator<<(std::ostream& out,
                                             const TokenType& type) {
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
    case TokenType::Unknown: {
      out << "Unknown";
      break;
    }
  }

  return out;
}

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

Token::Token(const TokenType type, const std::string& value) {
  this->tokenType = type;
  this->value = value;
}

Token::Token(const Token& other) {
  this->tokenType = other.tokenType;
  this->value = other.value;
}

bool Token::equals(const Token& other) const {
  return this->tokenType == other.tokenType && this->value == other.value;
}

std::string simpleDeserializer::Token::print() {
  std::stringstream ss;

  ss << "{\n\tType: " << this->tokenType << std::endl;
  ss << "\tValue: \"" << this->value << "\"\n}" << std::endl;

  return ss.str();
}

Token& Token::operator=(const Token& other) {
  if (this != &other) {
    tokenType = other.tokenType;
    value = other.value;
  }

  return *this;
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

JSONDeserializer::JSONDeserializer() : lexer(Lexer()), lookahead(nullptr) {}

JSONDeserializer::JSONDeserializer(const std::string& str)
    : lexer(Lexer(str)), lookahead(nullptr) {}

Lexer JSONDeserializer::getLexer() { return lexer; }

JSONNode& JSONDocument::operator[](std::string key) {
  if (!rootNode) {
    throw "No data!";
  }

  return rootNode->getData()[key];
}

JSONNode& JSONDocument::operator[](int index) {
  if (!rootNode) {
    throw "No data!";
  }

  return rootNode->getData()[index];
}

JSONDocument JSONDeserializer::parse() {
  lookahead = new Token(lexer.getNextToken());

  JSONDocument document;
  document.setRoot(literal());

  return document;
}

JSONDocument JSONDeserializer::parse(const std::string& jsonString) {
  if (jsonString.size() == 0) {
    throw std::invalid_argument("String cannot be empty");
  }

  lexer.setString(jsonString);

  return parse();
}

Token JSONDeserializer::eat(const TokenType expectedTokenType) {
  Token token = *lookahead;

  lookahead = new Token(lexer.getNextToken());

  return token;
}

JSONNode JSONDeserializer::literal() {
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
      return JSONNode(NodeType::ArrayEnd, JSONData(token.value));
    }
    case TokenType::RightBrace: {
      Token token = eat(lookahead->tokenType);
      return JSONNode(NodeType::ObjectEnd, JSONData(token.value));
    }
    case TokenType::Colon: {
      Token token = eat(lookahead->tokenType);
      return JSONNode(NodeType::Colon, JSONData(token.value));
    }
    case TokenType::Delimiter: {
      Token token = eat(lookahead->tokenType);
      return JSONNode(NodeType::Delimiter, JSONData(token.value));
    }
    default: {
      std::stringstream ss;
      ss << "Parse Error! Token: " << lookahead->print();
      throw ss.str();
    }
  }
}

JSONNode JSONDeserializer::numericLiteral() {
  Token token = eat(TokenType::Number);

  return JSONNode(NodeType::Numeric, JSONData(token.value));
}

JSONNode JSONDeserializer::stringLiteral() {
  Token token = eat(TokenType::String);

  return JSONNode(NodeType::String, JSONData(slice(token.value, 1, 1)));
}

JSONNode JSONDeserializer::nullLiteral() {
  Token token = eat(TokenType::Null);

  return JSONNode(NodeType::Null, JSONData(token.value));
}

JSONNode JSONDeserializer::booleanLiteral() {
  Token token = eat(TokenType::Boolean);

  return JSONNode(NodeType::Boolean, JSONData(token.value));
}

JSONNode JSONDeserializer::array() {
  eat(TokenType::LeftBracket);

  JSONArray array;
  JSONNode nextNode = literal();
  NodeType expectedNodeType = nextNode.getNodeType();
  NodeType actualType = expectedNodeType;
  while (actualType != NodeType::ArrayEnd) {
    if (actualType == expectedNodeType) {
      array.push_back(nextNode);
    }
    nextNode = literal();
    actualType = nextNode.getNodeType();
  }

  return JSONNode(NodeType::Array, JSONData(array));
}

JSONDeserializer::~JSONDeserializer() { delete lookahead; }

JSONNode JSONDeserializer::object() {
  eat(TokenType::LeftBrace);

  JSONObject object;
  JSONNode nextNode = literal();

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

  return JSONNode(NodeType::Object, JSONData(object));
}

JSONDocument::JSONDocument() {
  rootNode = nullptr;
  isEmpty = true;
}

JSONDocument::JSONDocument(const JSONDocument& other) {
  isEmpty = other.isEmpty;
  if (other.rootNode) {
    rootNode = new JSONNode(*other.rootNode);
  } else {
    rootNode = nullptr;
  }
}

JSONDocument::~JSONDocument() { delete rootNode; }

JSONNode& JSONDocument::getRoot() const { return *rootNode; }

void JSONDocument::setRoot(const JSONNode& rootNode) {
  if (this->rootNode == nullptr) {
    this->rootNode = new JSONNode(rootNode);
  } else {
    *this->rootNode = rootNode;
  }

  if (rootNode.getNodeType() != NodeType::Unknown) {
    isEmpty = false;
  }
}

bool JSONDocument::empty() { return isEmpty; }

JSONDocument& JSONDocument::operator=(const JSONDocument& other) {
  if (this != &other) {
    if (other.isEmpty) {
      rootNode = nullptr;
      isEmpty = true;
      return *this;
    }

    rootNode = new JSONNode(*other.rootNode);
    isEmpty = other.isEmpty;
  }

  return *this;
}

JSONNode::JSONNode() : nodeType(NodeType::Unknown), data(new JSONData) {}

JSONNode::JSONNode(const NodeType type) : nodeType(type), data(nullptr) {}

JSONNode::JSONNode(const JSONNode& other) {
  this->nodeType = other.nodeType;
  if (other.data) {
    this->data = new JSONData(*other.data);
  } else {
    this->data = nullptr;
  }
}

JSONNode::JSONNode(const NodeType type, const JSONData& data) {
  this->nodeType = type;
  this->data = new JSONData(data);
}

JSONNode::~JSONNode() { delete data; }

JSONNode& JSONNode::operator=(const JSONNode& other) {
  if (this != &other) {
    nodeType = other.nodeType;

    if (!other.data) {
      data = nullptr;
    } else {
      if (!data) {
        data = new JSONData;
      }
      *data = *other.data;
    }
  }

  return *this;
}

NodeType JSONNode::getNodeType() const { return nodeType; }

void JSONNode::setData(const JSONData& data) {
  JSONData copy = JSONData(data);
  if (!this->data) {
    this->data = new JSONData;
  }

  *this->data = data;
}

JSONData& JSONNode::getData() {
  if (!data) {
    data = new JSONData;
  }

  return *data;
}

bool JSONNode::equals(const JSONNode& other) const {
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

JSONData::JSONData() {}

JSONData::JSONData(const std::string value) { this->value = value; }

JSONData::JSONData(const JSONObject& object) { this->object = object; }

JSONData::JSONData(const JSONArray& array) { this->array = array; }

JSONData::JSONData(const JSONData& other) {
  array = other.array;
  value = other.value;
  object = other.object;
}

std::string& JSONData::getValue() { return value; }

JSONNode& JSONData::operator[](std::string key) { return object[key]; }

JSONNode& JSONData::operator[](int index) { return array[index]; }

bool JSONData::equals(const JSONData& other) const {
  return this->object == other.object && this->array == other.array &&
         this->value == other.value;
}

JSONData& JSONData::operator=(const JSONData& other) {
  if (this != &other) {
    object = other.object;
    array = other.array;
    value = other.value;
  }

  return *this;
}

bool simpleDeserializer::operator==(const JSONNode& lhs, const JSONNode& rhs) {
  return lhs.equals(rhs);
}

bool simpleDeserializer::operator!=(const JSONNode& lhs, const JSONNode& rhs) {
  return !(lhs.equals(rhs));
}

bool simpleDeserializer::operator==(const JSONData& lhs, const JSONData& rhs) {
  return lhs.equals(rhs);
}

bool simpleDeserializer::operator!=(const JSONData& lhs, const JSONData& rhs) {
  return !(lhs.equals(rhs));
}

bool simpleDeserializer::operator==(const Token& lhs, const Token& rhs) {
  return lhs.equals(rhs);
}

bool simpleDeserializer::operator!=(const Token& lhs, const Token& rhs) {
  return !(lhs.equals(rhs));
}
