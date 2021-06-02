// Copyright 2021 Ostapovich Denis

#ifndef MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_
#define MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_

#include <algorithm>
#include <list>
#include <map>
#include <ostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

namespace simpleDeserializer {
class JSONNode;
class JSONData;
enum class TokenType;
struct Token;

typedef std::map<std::string, JSONNode> JSONObject;
typedef std::vector<JSONNode> JSONArray;
typedef std::pair<TokenType, std::string> specification;

bool operator==(const JSONData& lhs, const JSONData& rhs);
bool operator!=(const JSONData& lhs, const JSONData& rhs);
bool operator==(const JSONNode& lhs, const JSONNode& rhs);
bool operator!=(const JSONNode& lhs, const JSONNode& rhs);
bool operator==(const Token& lhs, const Token& rhs);
bool operator!=(const Token& lhs, const Token& rhs);

bool equalsIgnoreCase(std::string lhs, std::string rhs);

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
  Eof,
  Unknown
};

std::ostream& operator<<(std::ostream& out, const TokenType& type);

enum class NodeType {
  Unknown,
  Numeric,
  String,
  Object,
  Array,
  Boolean,
  Null,
  ArrayEnd,
  ObjectEnd,
  Delimiter,
  Colon
};

class JSONData {
 public:
  JSONData();
  explicit JSONData(const std::string value);
  explicit JSONData(const JSONObject& object);
  explicit JSONData(const JSONArray& array);
  JSONData(const JSONData& other);

  std::string& getValue();

  JSONNode& operator[](std::string key);
  JSONNode& operator[](int index);

  bool equals(const JSONData& other) const;

  JSONData& operator=(const JSONData& other);

 private:
  JSONObject object;
  JSONArray array;
  std::string value;
};

class JSONNode {
 public:
  JSONNode();
  explicit JSONNode(const NodeType type);
  JSONNode(const JSONNode& other);
  JSONNode(const NodeType type, const JSONData& data);
  JSONNode& operator=(const JSONNode& other);
  ~JSONNode();

  NodeType getNodeType() const;
  void setData(const JSONData& data);
  JSONData& getData();

  bool equals(const JSONNode& other) const;

  template <class type>
  type to(const type& defaultValue = type()) {
    if (nodeType == NodeType::Unknown) {
      return defaultValue;
    }

    std::string data = this->data->getValue();
    return type(data);
  }

 protected:
  NodeType nodeType;
  JSONData* data;
};

class JSONDocument {
 public:
  JSONDocument();
  JSONDocument(const JSONDocument& other);
  JSONDocument& operator=(const JSONDocument& other);
  ~JSONDocument();

  JSONNode& getRoot() const;
  void setRoot(const JSONNode& rootNode);
  bool empty();

  JSONNode& operator[](std::string key);
  JSONNode& operator[](int index);

 private:
  JSONNode* rootNode;
  bool isEmpty;
};

struct Token {
  TokenType tokenType;
  std::string value;

  explicit Token(const TokenType type, const std::string& value = "");
  Token(const Token& other);

  bool equals(const Token& other) const;

  std::string print();

  Token& operator=(const Token& other);
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
  std::list<specification> specifications{
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
  size_t cursor;
  std::string string;
  std::string match(const std::string& expression, const std::string& src);
};

class JSONDeserializer {
 public:
  JSONDeserializer();
  explicit JSONDeserializer(const std::string& jsonString);
  ~JSONDeserializer();

  JSONDocument parse();
  JSONDocument parse(const std::string& jsonString);

  Lexer getLexer();

 private:
  Lexer lexer;
  Token* lookahead;
  Token eat(const TokenType tokenType);
  JSONNode literal();
  JSONNode numericLiteral();
  JSONNode stringLiteral();
  JSONNode nullLiteral();
  JSONNode booleanLiteral();
  JSONNode array();
  JSONNode object();
};

template <>
inline bool JSONNode::to(const bool& defaultValue) {
  if (nodeType == NodeType::Unknown) {
    return defaultValue;
  }

  std::string data = this->data->getValue();

  if (equalsIgnoreCase(data, "true")) {
    return true;
  }

  return false;
}

template <>
inline int JSONNode::to<int>(const int& defaultValue) {
  if (nodeType == NodeType::Unknown) {
    return defaultValue;
  }

  return atoi(this->data->getValue().c_str());
}
}  // namespace simpleDeserializer

#endif  // MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_
