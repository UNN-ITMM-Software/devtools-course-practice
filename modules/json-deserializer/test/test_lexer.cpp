// Copyright 2021 Ostapovich Denis

#include <gtest/gtest.h>
#include <include/json-deserializer.h>

#include <string>
#include <vector>

using simpleDeserializer::Lexer;
using simpleDeserializer::Token;
using simpleDeserializer::TokenType;

TEST(TokenType, No_Throw_On_Ostream) {
  ASSERT_NO_THROW(std::cout << TokenType::Array);
  ASSERT_NO_THROW(std::cout << TokenType::Number);
  ASSERT_NO_THROW(std::cout << TokenType::String);
  ASSERT_NO_THROW(std::cout << TokenType::Object);
  ASSERT_NO_THROW(std::cout << TokenType::Boolean);
  ASSERT_NO_THROW(std::cout << TokenType::Null);
  ASSERT_NO_THROW(std::cout << TokenType::Whitespace);
  ASSERT_NO_THROW(std::cout << TokenType::Colon);
  ASSERT_NO_THROW(std::cout << TokenType::LeftBrace);
  ASSERT_NO_THROW(std::cout << TokenType::RightBrace);
  ASSERT_NO_THROW(std::cout << TokenType::LeftBracket);
  ASSERT_NO_THROW(std::cout << TokenType::RightBracket);
  ASSERT_NO_THROW(std::cout << TokenType::Eof);
  ASSERT_NO_THROW(std::cout << TokenType::Unknown);
}

TEST(Token, Can_Create_Token_With_Args) {
  ASSERT_NO_THROW(Token t(TokenType::Number, ""));
}

TEST(Token, Can_Create_Token_With_Copy_Ctor) {
  Token token(TokenType::Array);
  ASSERT_NO_THROW(Token t(token));
}

TEST(Token, Ctor_Creates_Token_Of_Valid_Type) {
  TokenType tokenType = TokenType::String;

  Token token(tokenType, "");

  ASSERT_EQ(tokenType, token.tokenType);
}

TEST(Token, Ctor_One_Arg_Creates_Token_Of_Valid_Type) {
  TokenType tokenType = TokenType::Object;

  Token token(tokenType);

  ASSERT_EQ(tokenType, token.tokenType);
}

TEST(Token, Copy_Ctor_Creates_Valid_Copy) {
  std::string tokenValue = "1234";
  Token token(TokenType::Number, tokenValue);

  Token tokenCopy(token);

  ASSERT_EQ(token, tokenCopy);
}

TEST(Token, Ctor_Creates_Token_With_Valid_Value) {
  std::string tokenValue = "1234";

  Token token(TokenType::Number, tokenValue);

  ASSERT_EQ(tokenValue, token.value);
}

TEST(Token, Assignment_Operator_Overloaded_Properly) {
  Token src(TokenType::LeftBrace, "ff");
  Token assigned(TokenType::Eof, "");

  assigned = src;

  ASSERT_EQ(src, assigned);
}

TEST(Token, Equals_Compares_Instances_Properly) {
  TokenType type = TokenType::Boolean;
  std::string value = "same value";
  Token token(type, value);
  Token tokenCopy(type, value);

  ASSERT_TRUE(token.equals(tokenCopy));
}

TEST(Token, Equality_Operator_Overloaded_Properly) {
  Token src(TokenType::Number, "test");
  Token srcCopy(TokenType::Number, "test");

  ASSERT_EQ(src, srcCopy);
}

TEST(Token, Inequality_Operator_Overloaded_Properly) {
  Token src(TokenType::Number, "test");
  Token srcCopy(TokenType::Number, "test2");

  ASSERT_NE(src, srcCopy);
}

TEST(Token, No_Throw_On_Ostream) {
  Token token(TokenType::Delimiter, ",");

  ASSERT_NO_THROW(std::cout << token.print());
}

TEST(Token, Copy_Ctor_Clones_Token_Properly) {
  std::string tokenValue = "4213";
  Token src(TokenType::Number, tokenValue);
  Token dst(src);

  ASSERT_EQ(src, dst);
}

TEST(Lexer, Can_Create_Lexer_With_Default_Ctor) { ASSERT_NO_THROW(Lexer l); }

TEST(Lexer, Can_Create_Lexer_With_Parameterized_Ctor) {
  ASSERT_NO_THROW(Lexer l("valid json"));
}

TEST(Lexer, Can_Create_Lexer_With_Default_String_Value) {
  Lexer lexer;

  ASSERT_TRUE(lexer.getString().empty());
}

TEST(Lexer, Can_Create_Lexer_With_Default_Cursor_Value) {
  Lexer lexer;
  size_t defaultCursorPosition = 0;

  ASSERT_EQ(defaultCursorPosition, lexer.getCursor());
}

TEST(Lexer, Can_Create_Lexer_With_Valid_String) {
  const std::string json = "aabbcc";

  ASSERT_NO_THROW(Lexer lexer(json));
}

TEST(Lexer, Cant_Create_Lexer_With_Empty_String) {
  ASSERT_ANY_THROW(Lexer j(""));
}

TEST(Lexer, Lexer_Ctor_Returns_Valid_String) {
  const std::string src = "aabbcc";
  Lexer lexer(src);

  std::string result = lexer.getString();

  ASSERT_EQ(result, src);
}

TEST(Lexer, Lexer_Ctor_Returns_Valid_Cursor) {
  const std::string src = "aabbcc";
  Lexer lexer(src);
  size_t defaultCursorPosition = 0;

  size_t cursor = lexer.getCursor();

  ASSERT_EQ(defaultCursorPosition, cursor);
}

TEST(Lexer, Has_Tokens_Returns_True_If_Not_EOF) {
  const std::string src = "aabbcc";
  Lexer lexer(src);

  bool hasTokens = lexer.hasTokens();

  ASSERT_TRUE(hasTokens);
}

TEST(Lexer, Can_Get_Next_Token_Throws_If_No_Known_Token_Found) {
  const std::string json = "c";
  Lexer lexer(json);

  ASSERT_ANY_THROW(lexer.getNextToken());
}

TEST(Lexer, Can_Get_Next_Token_Returns_Token_Of_Valid_Type_On_Number) {
  const std::string numberString = "4321";
  Lexer lexer(numberString);

  Token next = lexer.getNextToken();

  ASSERT_EQ(TokenType::Number, next.tokenType);
}

TEST(Lexer,
     Get_Next_Token_Returns_Token_With_Valid_Value_On_Number_With_Whitespaces) {
  const std::string numberString = "\r\n\t  5213   ";
  const std::string cleanNumberString = "5213";

  Lexer lexer(numberString);

  Token next = lexer.getNextToken();

  ASSERT_EQ(cleanNumberString, next.value);
}

TEST(Lexer, Get_Next_Token_Returns_Token_Of_Valid_Type_On_String) {
  const std::string string = "\"hello\"";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(TokenType::String, next.tokenType);
}

TEST(Lexer, Get_Next_Token_Returns_Token_With_Valid_Value_On_String) {
  const std::string string = "\"world\"";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(string, next.value);
}

TEST(Lexer,
     Get_Next_Token_Returns_Token_With_Valid_Value_On_String_With_Whitespaces) {
  const std::string string = "\t\n\r   \" world \"  ";
  const std::string cleanString = "\" world \"";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(cleanString, next.value);
}

TEST(Lexer, Get_Next_Token_Returns_Token_Of_Valid_Type_On_Null) {
  const std::string string = "null";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(TokenType::Null, next.tokenType);
}

TEST(Lexer, Get_Next_Token_Returns_Token_With_Valid_Value_On_Null) {
  const std::string string = "null";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(string, next.value);
}

TEST(Lexer, Get_Next_Token_Returns_Token_Of_Valid_Type_On_Boolean) {
  const std::string string = "true";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(TokenType::Boolean, next.tokenType);
}

TEST(Lexer, Get_Next_Token_Returns_Token_With_Valid_Value_On_Boolean) {
  const std::string string = "false";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(string, next.value);
}

TEST(Lexer, Get_Next_Token_Returns_Token_Of_Valid_Type_On_Colon) {
  const std::string string = ":";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(TokenType::Colon, next.tokenType);
}

TEST(Lexer, Get_Next_Token_Returns_Token_With_Valid_Value_On_Colon) {
  const std::string string = ":";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(string, next.value);
}

TEST(Lexer, Get_Next_Token_Returns_Token_Of_Valid_Type_On_Comma) {
  const std::string string = ",";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(TokenType::Delimiter, next.tokenType);
}

TEST(Lexer, Get_Next_Token_Returns_Token_With_Valid_Value_On_Comma) {
  const std::string string = ",";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(string, next.value);
}

TEST(Lexer, Get_Next_Token_Returns_Token_Of_Valid_Type_On_LeftBrace) {
  const std::string string = "{";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(TokenType::LeftBrace, next.tokenType);
}

TEST(Lexer, Get_Next_Token_Returns_Token_With_Valid_Value_On_LeftBrace) {
  const std::string string = "{";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(string, next.value);
}

TEST(Lexer, Get_Next_Token_Returns_Token_Of_Valid_Type_On_RightBrace) {
  const std::string string = "}";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(TokenType::RightBrace, next.tokenType);
}

TEST(Lexer, Get_Next_Token_Returns_Token_With_Valid_Value_On_RightBrace) {
  const std::string string = "}";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(string, next.value);
}

TEST(Lexer, Get_Next_Token_Returns_Token_Of_Valid_Type_On_LeftBracket) {
  const std::string string = "[";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(TokenType::LeftBracket, next.tokenType);
}

TEST(Lexer, Get_Next_Token_Returns_Token_With_Valid_Value_On_LeftBracket) {
  const std::string string = "[";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(string, next.value);
}

TEST(Lexer, Get_Next_Token_Returns_Token_Of_Valid_Type_On_RightBracket) {
  const std::string string = "]";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(TokenType::RightBracket, next.tokenType);
}

TEST(Lexer, Get_Next_Token_Returns_Token_With_Valid_Value_On_RightBracket) {
  const std::string string = "]";
  Lexer lexer(string);

  Token next = lexer.getNextToken();

  ASSERT_EQ(string, next.value);
}

TEST(Lexer, GetTokens_Returns_Valid_Tokens) {
  const std::string json =
      "{ \"name\" : \"John\" , \"age\" : 22, "
      "\"Cars\" : [\"BMW\", \"Lexus\"],\"address\" : {} }";
  const std::vector<Token> expectedTokens{
      Token(TokenType::LeftBrace, "{"),
      Token(TokenType::String, "\"name\""),
      Token(TokenType::Colon, ":"),
      Token(TokenType::String, "\"John\""),
      Token(TokenType::Delimiter, ","),
      Token(TokenType::String, "\"age\""),
      Token(TokenType::Colon, ":"),
      Token(TokenType::Number, "22"),
      Token(TokenType::Delimiter, ","),
      Token(TokenType::String, "\"Cars\""),
      Token(TokenType::Colon, ":"),
      Token(TokenType::LeftBracket, "["),
      Token(TokenType::String, "\"BMW\""),
      Token(TokenType::Delimiter, ","),
      Token(TokenType::String, "\"Lexus\""),
      Token(TokenType::RightBracket, "]"),
      Token(TokenType::Delimiter, ","),
      Token(TokenType::String, "\"address\""),
      Token(TokenType::Colon, ":"),
      Token(TokenType::LeftBrace, "{"),
      Token(TokenType::RightBrace, "}"),
      Token(TokenType::RightBrace, "}")};

  Lexer lexer(json);
  auto tokens = lexer.getTokens();

  ASSERT_EQ(expectedTokens, tokens);
}
