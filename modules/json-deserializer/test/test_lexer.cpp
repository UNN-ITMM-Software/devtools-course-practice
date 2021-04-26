#include <gtest/gtest.h>

#include <include/json-deserializer.h>

#include <string>

TEST(Token, Can_Create_Token_With_Args) {
    ASSERT_NO_THROW(Token t(TokenType::Number, ""));
}

TEST(Token, Ctor_Creates_Token_Of_Valid_Type) {
    TokenType tokenType = TokenType::String;

    Token token(tokenType, "");

    ASSERT_EQ(tokenType, token.type);
}

TEST(Token, Ctor_Creates_Token_With_Valid_Value) {
    std::string tokenValue = "1234";

    Token token(TokenType::Number, tokenValue);

    ASSERT_EQ(tokenValue, token.value);
}

TEST(Lexer, Can_Create_Lexer_With_Default_String_Value) {
    Lexer lexer;

    ASSERT_TRUE(lexer.getString().empty());
}

TEST(Lexer, Can_Create_Lexer_With_Default_Cursor_Value) {
    Lexer lexer;

    ASSERT_EQ(0, lexer.getCursor());
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

    size_t cursor = lexer.getCursor();

    ASSERT_EQ(0, cursor);
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

TEST(Lexer,
    Can_Get_Next_Token_Returns_Token_Of_Valid_Type_On_Number) {
    const std::string numberString = "4321";
    Lexer lexer(numberString);

    Token next = lexer.getNextToken();

    ASSERT_EQ(TokenType::Number, next.type);
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

    ASSERT_EQ(TokenType::String, next.type);
}

TEST(Lexer,
    Get_Next_Token_Returns_Token_With_Valid_Value_On_String) {
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

    ASSERT_EQ(TokenType::Null, next.type);
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

    ASSERT_EQ(TokenType::Boolean, next.type);
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

    ASSERT_EQ(TokenType::Colon, next.type);
}

TEST(Lexer, Get_Next_Token_Returns_Token_With_Valid_Value_On_Colon) {
    const std::string string = ":";
    Lexer lexer(string);

    Token next = lexer.getNextToken();

    ASSERT_EQ(string, next.value);
}

TEST(Lexer, Get_Next_Token_Returns_Token_Of_Valid_Type_On_Ñomma) {
    const std::string string = ",";
    Lexer lexer(string);

    Token next = lexer.getNextToken();

    ASSERT_EQ(TokenType::Delimiter, next.type);
}

TEST(Lexer, Get_Next_Token_Returns_Token_With_Valid_Value_On_Ñomma) {
    const std::string string = ",";
    Lexer lexer(string);

    Token next = lexer.getNextToken();

    ASSERT_EQ(string, next.value);
}
