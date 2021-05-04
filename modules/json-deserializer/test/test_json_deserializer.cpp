// Copyright 2021 Ostapovich Denis

#include <gtest/gtest.h>

#include <include/json-deserializer.h>

#include <string>

TEST(JsonDeserializer, Can_Create_Deserializer_Without_Parameters) {
    ASSERT_NO_THROW(JsonDeserializer j);
}

TEST(JsonDeserializer, Parse_Throws_On_Empty_String) {
    JsonDeserializer des;

    ASSERT_ANY_THROW(des.parse(""));
}

TEST(JsonDeserializer, No_Throw_On_Parse_With_Not_Empty_String) {
    JsonDeserializer des;

    ASSERT_NO_THROW(des.parse("    \"abcdef\""));
}

TEST(JsonDeserializer, Parse_Returns_Not_Empty_Document_On_String_Literal) {
    const std::string testString = "    \"hello world\"     ";
    JsonDeserializer des;

    JsonDocument document = des.parse(testString);

    ASSERT_FALSE(document.empty());
}

TEST(JsonDeserializer, Parse_Returns_String_Literal) {
    JsonDeserializer des("    \"hello world\"     ");

    JsonDocument document = des.parse();
    NodeType nodeType = document.getRoot().getNodeType();

    ASSERT_EQ(NodeType::StringLiteral, nodeType);
}

TEST(JsonDeserializer, Parse_Returns_Numeric_Literal) {
    JsonDeserializer des("    78964   ");

    JsonDocument document = des.parse();

    ASSERT_EQ(NodeType::NumericLiteral, document.getRoot().getNodeType());
}

TEST(JsonDeserializer, Parse_Returns_Null_Literal) {
    JsonDeserializer des("    null   ");

    JsonDocument document = des.parse();

    ASSERT_EQ(NodeType::Null, document.getRoot().getNodeType());
}

TEST(JsonDeserializer, Parse_Returns_Boolean_Literal) {
    JsonDeserializer des("    false   ");

    JsonDocument document = des.parse();
    JsonNode* node = &document.getRoot();
    JsonValue* value = dynamic_cast<JsonValue*>(node);

    ASSERT_EQ(NodeType::BooleanLiteral, document.getRoot().getNodeType());
    ASSERT_TRUE(value);
}
