// Copyright 2021 Ostapovich Denis

#include <gtest/gtest.h>

#include <string>

#include "include/json-deserializer.h"

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

    ASSERT_EQ(NodeType::String, nodeType);
    ASSERT_EQ("hello world", document.getRoot().to<std::string>());
}

TEST(JsonDeserializer, Parse_Returns_Numeric_Literal) {
    JsonDeserializer des("    78964   ");

    JsonDocument document = des.parse();

    ASSERT_EQ(NodeType::Numeric, document.getRoot().getNodeType());
    ASSERT_EQ(78964, document.getRoot().to<int>());
}

TEST(JsonDeserializer, Parse_Returns_Null_Literal) {
    JsonDeserializer des("    null   ");

    JsonDocument document = des.parse();

    ASSERT_EQ(NodeType::Null, document.getRoot().getNodeType());
}

TEST(JsonDeserializer, Parse_Returns_Boolean_Literal) {
    JsonDeserializer des("    true   ");

    JsonDocument document = des.parse();

    ASSERT_EQ(NodeType::Boolean, document.getRoot().getNodeType());
    ASSERT_EQ(true, document.getRoot().to<bool>());
}

TEST(JsonDeserializer, Parse_Returns_Array) {
    JsonDeserializer des("[\"element\", \"element2\"]");
    std::string expectedValue = "element2";

    JsonDocument document = des.parse();
    JsonNode resultNode = document.getRoot();
    std::string resultValue = resultNode.getData()[1].to<std::string>();

    ASSERT_EQ(NodeType::Array, resultNode.getNodeType());
    ASSERT_EQ(expectedValue, resultValue);
}

TEST(JsonDeserializer, Parse_Returns_Object) {
    JsonDeserializer des("{   \"field\" :   "
        "\"value\", \"intField\" : \"1234\"   }");
    std::string expectedValue = "value";

    JsonDocument document = des.parse();
    JsonNode resultNode = document.getRoot();
    std::string resultValue = resultNode.getData()["field"]
        .to<std::string>();

    ASSERT_EQ(NodeType::Object, resultNode.getNodeType());
    ASSERT_EQ(expectedValue, resultValue);
}
