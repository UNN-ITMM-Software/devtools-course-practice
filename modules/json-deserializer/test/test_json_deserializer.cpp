// Copyright 2021 Ostapovich Denis

#include <gtest/gtest.h>

#include <string>

#include "include/json-deserializer.h"

using simpleds::JSONArray;
using simpleds::JsonData;
using simpleds::JsonDeserializer;
using simpleds::JsonDocument;
using simpleds::JsonNode;
using simpleds::JSONObject;
using simpleds::NodeType;

TEST(JsonData, Can_Create_JsonData) { ASSERT_NO_THROW(JsonData data); }

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

TEST(JsonData, Equals_Compares_Instances_Properly) {
  JsonData data("value");
  JsonData dataCopy("value");

  ASSERT_TRUE(data.equals(dataCopy));
}

TEST(JsonData, Subscript_Int_Operator_Returns_Valid_Value) {
  JsonNode node;
  JSONArray arr{node};
  JsonData data(arr);

  auto value = data[0];

  ASSERT_EQ(node, value);
}

TEST(JsonData, Subscript_String_Operator_Returns_Valid_Value) {
  std::string key = "key";
  JsonNode node;
  JSONObject obj{std::make_pair(key, node)};
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

TEST(JsonNode, Can_Create_JsonNode) { ASSERT_NO_THROW(JsonNode n); }

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

TEST(JsonNode, Equals_Returns_True_On_Equal_Objects) {
  JsonData data("value");
  JsonNode node(NodeType::String, data);
  JsonNode nodeCopy(NodeType::String, data);

  ASSERT_TRUE(node.equals(nodeCopy));
}

TEST(JsonNode, Equals_Returns_False_On_Unequal_Objects) {
  JsonData data("value");
  JsonNode node(NodeType::Array, data);
  JsonNode nodeCopy(NodeType::String, data);

  ASSERT_FALSE(node.equals(nodeCopy));
}

TEST(JsonNode, Assignment_Operator_Overloaded_Properly) {
  JsonNode node(NodeType::Boolean);
  JsonNode assigned(NodeType::Colon);

  assigned = node;

  ASSERT_EQ(node, assigned);
}

TEST(JsonNode, Assignment_Operator_Works_Properly_On_Node_With_Data) {
  JsonNode node(NodeType::Boolean, JsonData("data"));
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

TEST(JsonDeserializer, Can_Get_Lexer) {
  JsonDeserializer des;

  ASSERT_NO_THROW(des.getLexer());
}

TEST(JsonDeserializer, Parse_Throws_On_Invalid_String) {
  JsonDeserializer des;

  ASSERT_ANY_THROW(des.parse("\\"));
}

TEST(JsonDeserializer, Parse_Throws_On_Invalid_Json_Object) {
  JsonDeserializer des;

  ASSERT_ANY_THROW(des.parse("{ \"field\" \"\"}"));
}

TEST(JsonDeserializer, Parse_Throws_On_Invalid_Object_Expression) {
  JsonDeserializer des;

  ASSERT_ANY_THROW(des.parse("{]}"));
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
  JsonDeserializer des(
      "{   "
      "\"stringField\" : \"string\","
      "\"intField\" : 3421,"
      "\"booleanField\" : true,"
      "\"arrayField\" : [1,2]"
      "\"objectField\" : {"
      "\"anotherIntField\" : 1111,"
      "\"anotherStringField\" : \"stringTwo\""
      "}"
      "}");

  std::string expectedString = "string";
  int expectedInt = 3421;
  bool expectedBoolean = true;
  auto expectedFirstArrayValue = 1;
  auto expectedSecondArrayValue = 2;
  auto expectedNestedIntValue = 1111;
  auto expectedNestedStrValue = "stringTwo";

  JsonDocument document = des.parse();
  JsonNode resultNode = document.getRoot();
  auto data = resultNode.getData();
  auto stringResult = data["stringField"].to<std::string>();
  auto resultInt = data["intField"].to<int>();
  auto resultBoolean = data["booleanField"].to<bool>();
  auto jsonArray = data["arrayField"].getData();
  auto jsonObject = data["objectField"].getData();

  ASSERT_EQ(NodeType::Object, resultNode.getNodeType());
  ASSERT_EQ(expectedString, stringResult);
  ASSERT_EQ(expectedInt, resultInt);
  ASSERT_EQ(expectedBoolean, resultBoolean);
  ASSERT_EQ(expectedFirstArrayValue, jsonArray[0].to<int>());
  ASSERT_EQ(expectedSecondArrayValue, jsonArray[1].to<int>());
  ASSERT_EQ(expectedNestedIntValue, jsonObject["anotherIntField"].to<int>());
  ASSERT_EQ(expectedNestedStrValue,
            jsonObject["anotherStringField"].to<std::string>());
}

TEST(JsonDocument, Can_Create_JsonDocument) {
  ASSERT_NO_THROW(JsonDocument doc);
}

TEST(JsonDocument, Can_Create_JsonDocument_With_Copy_Ctor) {
  JsonDocument doc;
  ASSERT_NO_THROW(JsonDocument docCopy(doc));
}

TEST(JsonDocument, Can_Set_Json_Node_On_Non_Empty_Document) {
  JsonDocument doc;
  doc.setRoot(JsonNode());

  ASSERT_NO_THROW(doc.setRoot(JsonNode()););
}

TEST(JsonDocument, Can_Assign_Non_Empty) {
  JsonDocument doc, other;
  other.setRoot(JsonNode(NodeType::Colon));

  ASSERT_NO_THROW(doc = other);
}

TEST(JsonDocument, Can_Create_JsonDocument_With_Copy_Ctor_From_Doc_With_Data) {
  JsonDocument doc;
  doc.setRoot(JsonNode());
  ASSERT_NO_THROW(JsonDocument docCopy(doc));
}

TEST(JsonDocument, Throws_If_No_Data) {
  JsonDocument doc;

  ASSERT_ANY_THROW(doc[0]);
  ASSERT_ANY_THROW(doc["data"]);
}

TEST(JsonDocument, Can_Assign) {
  JsonDocument doc, other;

  ASSERT_NO_THROW(other = doc);
}

TEST(JsonDocument, Can_Access_Data_By_Key) {
  JsonDocument doc;
  std::string key = "key";
  std::string value = "value";
  JsonData dta(value);
  JsonNode dataNode(NodeType::String, dta);
  JSONObject object{std::make_pair(key, dataNode)};
  JsonData data(object);
  JsonNode node(NodeType::Object, data);
  doc.setRoot(node);

  ASSERT_NO_THROW(doc["key"]);
}

TEST(JsonDocument, Can_Access_Data_By_Index) {
  JsonDocument doc;
  std::string value = "value";
  JsonData dta(value);
  JsonNode dataNode(NodeType::String, dta);
  JSONArray arr{dataNode};
  JsonData data(arr);
  JsonNode node(NodeType::Array, data);
  doc.setRoot(node);

  ASSERT_NO_THROW(doc[0]);
}
