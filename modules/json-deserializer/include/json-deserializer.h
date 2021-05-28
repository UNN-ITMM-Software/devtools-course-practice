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

namespace simpleds {
class JsonNode;
class JsonData;
enum class TokenType;
struct Token;

typedef std::map<std::string, JsonNode> JSONObject;
typedef std::vector<JsonNode> JSONArray;
typedef std::pair<TokenType, std::string> specification;

bool operator==(const JsonData& lhs, const JsonData& rhs);
bool operator!=(const JsonData& lhs, const JsonData& rhs);
bool operator==(const JsonNode& lhs, const JsonNode& rhs);
bool operator!=(const JsonNode& lhs, const JsonNode& rhs);
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

class JsonData {
 public:
  JsonData();
  explicit JsonData(const std::string value);
  explicit JsonData(const JSONObject& object);
  explicit JsonData(const JSONArray& array);
  JsonData(const JsonData& other);

  std::string& getValue();

  JsonNode& operator[](std::string key);
  JsonNode& operator[](int index);

  bool equals(const JsonData& other) const;

  JsonData& operator=(const JsonData& other);

 private:
  JSONObject object;
  JSONArray array;
  std::string value;
};

class JsonNode {
 public:
  JsonNode();
  explicit JsonNode(const NodeType type);
  JsonNode(const JsonNode& other);
  JsonNode(const NodeType type, const JsonData& data);
  JsonNode& operator=(const JsonNode& other);
  ~JsonNode();

  NodeType getNodeType() const;
  void setData(const JsonData& data);
  JsonData& getData();

  bool equals(const JsonNode& other) const;

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
  JsonData* data;
};

class JsonDocument {
 public:
  JsonDocument();
  JsonDocument(const JsonDocument& other);
  JsonDocument& operator=(const JsonDocument& other);
  ~JsonDocument();

  JsonNode& getRoot() const;
  void setRoot(const JsonNode& rootNode);
  bool empty();

  JsonNode& operator[](std::string key);
  JsonNode& operator[](int index);

 private:
  JsonNode* rootNode;
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

class JsonDeserializer {
 public:
  JsonDeserializer();
  explicit JsonDeserializer(const std::string& jsonString);
  ~JsonDeserializer();

  JsonDocument parse();
  JsonDocument parse(const std::string& jsonString);

  Lexer getLexer();

 private:
  Lexer lexer;
  Token* lookahead;
  Token eat(const TokenType tokenType);
  JsonNode literal();
  JsonNode numericLiteral();
  JsonNode stringLiteral();
  JsonNode nullLiteral();
  JsonNode booleanLiteral();
  JsonNode array();
  JsonNode object();
};

template <>
inline bool JsonNode::to(const bool& defaultValue) {
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
inline int JsonNode::to<int>(const int& defaultValue) {
  if (nodeType == NodeType::Unknown) {
    return defaultValue;
  }

  return atoi(this->data->getValue().c_str());
}
}  // namespace simpleds

#endif  // MODULES_JSON_DESERIALIZER_INCLUDE_JSON_DESERIALIZER_H_
