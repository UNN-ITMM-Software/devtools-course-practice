// Copyright 2021 Ostapovich Denis

#include <gtest/gtest.h>

#include <string>

#include "include/json-deserializer.h"

using simplejs::JsonData;
using simplejs::JSONArray;
using simplejs::JSONObject;
using simplejs::JsonNode;
using simplejs::NodeType;
using simplejs::JsonDeserializer;
using simplejs::JsonDocument;

TEST(JsonData, Can_Create_JsonData) {
    ASSERT_NO_THROW(JsonData data);
}

TEST(JsonData, Can_Create_JsonData_With_String_Arg) {
    ASSERT_NO_THROW(JsonData data(""));
}

TEST(JsonData, Can_Create_JsonData_With_JSONObject_Arg) {
    ASSERT_NO_THROW(JsonData data(JSONObject));
}

TEST(JsonData, Can_Create_JsonData_With_JSONArray_Arg) {
    ASSERT_NO_THROW(JsonData data(JSONArray));
}

TEST(JsonData, Can_Create_With_Copy_Ctor) {
    JsonData data;

    ASSERT_NO_THROW(JsonData(data));
}

TEST(JsonData, Get_Value_Returns_Default_Value) {
    JsonData data;
    std::string defaultValue = "";

    ASSERT_EQ(defaultValue, data.getValue());
}

TEST(JsonData, Subscript_Int_Operator_Returns_Valid_Value) {
    JsonNode node;
    JSONArray arr{ node };
    JsonData data(arr);

    auto value = data[0];

    ASSERT_EQ(node, value);
}

TEST(JsonData, Subscript_String_Operator_Returns_Valid_Value) {
    std::string key = "key";
    JsonNode node;
    JSONObject obj{ std::make_pair(key, node) };
    JsonData data(obj);

    auto value = data[key];

    ASSERT_EQ(node, value);
}

TEST(JsonData, Equality_Operator_Overloaded_Properly) {
    std::string value = "test";
    JsonData data(value);
    JsonData dataCopy(value);

    ASSERT_EQ(data, dataCopy);
}

TEST(JsonData, Inequality_Operator_Overloaded_Properly) {
    JsonData data("val1");
    JsonData otherData("val2");

    ASSERT_NE(data, otherData);
}

TEST(JsonData, Assignment_Operator_Overloaded_Properly) {
    JsonData data("testValue");
    JsonData assigned("other value");

    assigned = data;

    ASSERT_EQ(data, assigned);
}

TEST(JsonNode, Can_Create_JsonNode) {
    ASSERT_NO_THROW(JsonNode n);
}

TEST(JsonNode, Can_Create_JsonNode_With_Type) {
    ASSERT_NO_THROW(JsonNode n(NodeType::Array));
}

TEST(JsonNode, Can_Create_JsonNode_With_Type_And_Data) {
    NodeType type = NodeType::ArrayEnd;
    JsonData data;

    ASSERT_NO_THROW(JsonNode n(type, data));
}

TEST(JsonNode, Can_Create_JsonNode_With_Copy_Ctor) {
    JsonNode node(NodeType::Object);

    ASSERT_NO_THROW(JsonNode n(node));
}

TEST(JsonNode, Assignment_Operator_Overloaded_Properly) {
    JsonNode node(NodeType::Boolean);
    JsonNode assigned(NodeType::Colon);

    assigned = node;

    ASSERT_EQ(node, assigned);
}

TEST(JsonNode, Get_Node_Type_Returns_Valid_Default_Value) {
    JsonNode node;
    NodeType expectedNodeType = NodeType::Unknown;

    ASSERT_EQ(expectedNodeType, node.getNodeType());
}

TEST(JsonNode, Set_Data_Sets_Data_Properly) {
    JsonData data("data");
    JsonNode node;

    node.setData(data);

    ASSERT_EQ(data, node.getData());
}

TEST(JsonNode, Get_Data_Returns_Valid_Default_Value) {
    JsonNode node;
    JsonData defaultData;

    JsonData data = node.getData();

    ASSERT_EQ(defaultData, data);
}

TEST(JsonNode, Equality_Operator_Overloaded_Properly) {
    JsonNode src(NodeType::Array);
    JsonNode dst(NodeType::Array);

    ASSERT_EQ(src, dst);
}

TEST(JsonNode, Inequality_Operator_Overloaded_Properly) {
    JsonNode src(NodeType::Array);
    JsonNode dst(NodeType::Array, JsonData("data"));

    ASSERT_NE(src, dst);
}

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
