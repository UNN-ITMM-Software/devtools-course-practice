// Copyright 2021 Ostapovich Denis

#include <gtest/gtest.h>

#include <string>

#include "include/json-deserializer.h"

using simpleDeserializer::JSONArray;
using simpleDeserializer::JSONData;
using simpleDeserializer::JSONDeserializer;
using simpleDeserializer::JSONDocument;
using simpleDeserializer::JSONNode;
using simpleDeserializer::JSONObject;
using simpleDeserializer::NodeType;

TEST(JSONData, Can_Create_JsonData) { ASSERT_NO_THROW(JSONData data); }

TEST(JSONData, Can_Create_JsonData_With_String_Arg) {
  ASSERT_NO_THROW(JSONData data(""));
}

TEST(JSONData, Can_Create_JsonData_With_JSONObject_Arg) {
  ASSERT_NO_THROW(JSONData data(JSONObject));
}

TEST(JSONData, Can_Create_JsonData_With_JSONArray_Arg) {
  ASSERT_NO_THROW(JSONData data(JSONArray));
}

TEST(JSONData, Can_Create_With_Copy_Ctor) {
  JSONData data;

  ASSERT_NO_THROW(JSONData(data));
}

TEST(JSONData, Get_Value_Returns_Default_Value) {
  JSONData data;
  std::string defaultValue = "";

  ASSERT_EQ(defaultValue, data.getValue());
}

TEST(JSONData, Equals_Compares_Instances_Properly) {
  JSONData data("value");
  JSONData dataCopy("value");

  ASSERT_TRUE(data.equals(dataCopy));
}

TEST(JSONData, Subscript_Int_Operator_Returns_Valid_Value) {
  JSONNode node;
  JSONArray arr{node};
  JSONData data(arr);

  auto value = data[0];

  ASSERT_EQ(node, value);
}

TEST(JSONData, Subscript_String_Operator_Returns_Valid_Value) {
  std::string key = "key";
  JSONNode node;
  JSONObject obj{std::make_pair(key, node)};
  JSONData data(obj);

  auto value = data[key];

  ASSERT_EQ(node, value);
}

TEST(JSONData, Equality_Operator_Overloaded_Properly) {
  std::string value = "test";
  JSONData data(value);
  JSONData dataCopy(value);

  ASSERT_EQ(data, dataCopy);
}

TEST(JSONData, Inequality_Operator_Overloaded_Properly) {
  JSONData data("val1");
  JSONData otherData("val2");

  ASSERT_NE(data, otherData);
}

TEST(JSONData, Assignment_Operator_Overloaded_Properly) {
  JSONData data("testValue");
  JSONData assigned("other value");

  assigned = data;

  ASSERT_EQ(data, assigned);
}

TEST(JSONNode, Can_Create_JsonNode) { ASSERT_NO_THROW(JSONNode n); }

TEST(JSONNode, Can_Create_JsonNode_With_Type) {
  ASSERT_NO_THROW(JSONNode n(NodeType::Array));
}

TEST(JSONNode, Can_Create_JsonNode_With_Type_And_Data) {
  NodeType type = NodeType::ArrayEnd;
  JSONData data;

  ASSERT_NO_THROW(JSONNode n(type, data));
}

TEST(JSONNode, Can_Create_JsonNode_With_Copy_Ctor) {
  JSONNode node(NodeType::Object);

  ASSERT_NO_THROW(JSONNode n(node));
}

TEST(JSONNode, Equals_Returns_True_On_Equal_Objects) {
  JSONData data("value");
  JSONNode node(NodeType::String, data);
  JSONNode nodeCopy(NodeType::String, data);

  ASSERT_TRUE(node.equals(nodeCopy));
}

TEST(JSONNode, Equals_Returns_False_On_Unequal_Objects) {
  JSONData data("value");
  JSONNode node(NodeType::Array, data);
  JSONNode nodeCopy(NodeType::String, data);

  ASSERT_FALSE(node.equals(nodeCopy));
}

TEST(JSONNode, Assignment_Operator_Overloaded_Properly) {
  JSONNode node(NodeType::Boolean);
  JSONNode assigned(NodeType::Colon);

  assigned = node;

  ASSERT_EQ(node, assigned);
}

TEST(JSONNode, Assignment_Operator_Works_Properly_On_Node_With_Data) {
  JSONNode node(NodeType::Boolean, JSONData("data"));
  JSONNode assigned(NodeType::Colon);

  assigned = node;

  ASSERT_EQ(node, assigned);
}

TEST(JSONNode, Get_Node_Type_Returns_Valid_Default_Value) {
  JSONNode node;
  NodeType expectedNodeType = NodeType::Unknown;

  ASSERT_EQ(expectedNodeType, node.getNodeType());
}

TEST(JSONNode, Set_Data_Sets_Data_Properly) {
  JSONData data("data");
  JSONNode node(NodeType::Object);

  node.setData(data);

  ASSERT_EQ(data, node.getData());
}

TEST(JSONNode, Can_Get_Data) {
  JSONNode node(NodeType::Colon);

  ASSERT_NO_THROW(node.getData());
}

TEST(JSONNode, Get_Data_Returns_Valid_Default_Value) {
  JSONNode node;
  JSONData defaultData;

  JSONData data = node.getData();

  ASSERT_EQ(defaultData, data);
}

TEST(JSONNode, Equality_Operator_Overloaded_Properly) {
  JSONNode src(NodeType::Array);
  JSONNode dst(NodeType::Array);

  ASSERT_EQ(src, dst);
}

TEST(JSONNode, Inequality_Operator_Overloaded_Properly) {
  JSONNode src(NodeType::Array);
  JSONNode dst(NodeType::Array, JSONData("data"));

  ASSERT_NE(src, dst);
}

TEST(JSONDeserializer, Can_Create_Deserializer_Without_Parameters) {
  ASSERT_NO_THROW(JSONDeserializer j);
}

TEST(JSONDeserializer, Parse_Throws_On_Empty_String) {
  JSONDeserializer des;

  ASSERT_ANY_THROW(des.parse(""));
}

TEST(JSONDeserializer, Can_Get_Lexer) {
  JSONDeserializer des;

  ASSERT_NO_THROW(des.getLexer());
}

TEST(JSONDeserializer, Parse_Throws_On_Invalid_String) {
  JSONDeserializer des;

  ASSERT_ANY_THROW(des.parse("\\"));
}

TEST(JSONDeserializer, Parse_Throws_On_Invalid_Json_Object) {
  JSONDeserializer des;

  ASSERT_ANY_THROW(des.parse("{ \"field\" \"\"}"));
}

TEST(JSONDeserializer, Parse_Throws_On_Invalid_Object_Expression) {
  JSONDeserializer des;

  ASSERT_ANY_THROW(des.parse("{]}"));
}

TEST(JSONDeserializer, Parse_No_Throw_On_Empty_Json_Object) {
  JSONDeserializer des;

  ASSERT_NO_THROW(des.parse("{,}"));
}

TEST(JSONDeserializer, No_Throw_On_Parse_With_Not_Empty_String) {
  JSONDeserializer des;

  ASSERT_NO_THROW(des.parse("    \"abcdef\""));
}

TEST(JSONDeserializer, Parse_Returns_Not_Empty_Document_On_String_Literal) {
  const std::string testString = "    \"hello world\"     ";
  JSONDeserializer des;

  JSONDocument document = des.parse(testString);

  ASSERT_FALSE(document.empty());
}

TEST(JSONDeserializer, Parse_Returns_String_Literal) {
  JSONDeserializer des("    \"hello world\"     ");

  JSONDocument document = des.parse();
  NodeType nodeType = document.getRoot().getNodeType();

  ASSERT_EQ(NodeType::String, nodeType);
  ASSERT_EQ("hello world", document.getRoot().to<std::string>());
}

TEST(JSONDeserializer, Parse_Returns_Numeric_Literal) {
  JSONDeserializer des("    78964   ");

  JSONDocument document = des.parse();

  ASSERT_EQ(NodeType::Numeric, document.getRoot().getNodeType());
  ASSERT_EQ(78964, document.getRoot().to<int>());
}

TEST(JSONDeserializer, Parse_Returns_Null_Literal) {
  JSONDeserializer des("    null   ");

  JSONDocument document = des.parse();

  ASSERT_EQ(NodeType::Null, document.getRoot().getNodeType());
}

TEST(JSONDeserializer, Parse_Returns_Boolean_Literal) {
  JSONDeserializer des("    true   ");

  JSONDocument document = des.parse();

  ASSERT_EQ(NodeType::Boolean, document.getRoot().getNodeType());
  ASSERT_EQ(true, document.getRoot().to<bool>());
}

TEST(JSONDeserializer, Parse_Returns_Array) {
  JSONDeserializer des("[\"element\", \"element2\"]");
  std::string expectedValue = "element2";

  JSONDocument document = des.parse();
  JSONNode resultNode = document.getRoot();
  std::string resultValue = resultNode.getData()[1].to<std::string>();

  ASSERT_EQ(NodeType::Array, resultNode.getNodeType());
  ASSERT_EQ(expectedValue, resultValue);
}

TEST(JSONDeserializer, Parse_Returns_Object) {
  JSONDeserializer des(
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

  JSONDocument document = des.parse();
  JSONNode resultNode = document.getRoot();
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

TEST(JSONDocument, Can_Create_JsonDocument) {
  ASSERT_NO_THROW(JSONDocument doc);
}

TEST(JSONDocument, Can_Create_JsonDocument_With_Copy_Ctor) {
  JSONDocument doc;
  ASSERT_NO_THROW(JSONDocument docCopy(doc));
}

TEST(JSONDocument, Can_Set_Json_Node_On_Non_Empty_Document) {
  JSONDocument doc;
  doc.setRoot(JSONNode());

  ASSERT_NO_THROW(doc.setRoot(JSONNode()););
}

TEST(JSONDocument, Can_Assign_Non_Empty) {
  JSONDocument doc, other;
  other.setRoot(JSONNode(NodeType::Colon));

  ASSERT_NO_THROW(doc = other);
}

TEST(JSONDocument, Can_Create_JsonDocument_With_Copy_Ctor_From_Doc_With_Data) {
  JSONDocument doc;
  doc.setRoot(JSONNode());
  ASSERT_NO_THROW(JSONDocument docCopy(doc));
}

TEST(JSONDocument, Throws_If_No_Data) {
  JSONDocument doc;

  ASSERT_ANY_THROW(doc[0]);
  ASSERT_ANY_THROW(doc["data"]);
}

TEST(JSONDocument, Can_Assign) {
  JSONDocument doc, other;

  ASSERT_NO_THROW(other = doc);
}

TEST(JSONDocument, Can_Access_Data_By_Key) {
  JSONDocument doc;
  std::string key = "key";
  std::string value = "value";
  JSONData dta(value);
  JSONNode dataNode(NodeType::String, dta);
  JSONObject object{std::make_pair(key, dataNode)};
  JSONData data(object);
  JSONNode node(NodeType::Object, data);
  doc.setRoot(node);

  ASSERT_NO_THROW(doc["key"]);
}

TEST(JSONDocument, Can_Access_Data_By_Index) {
  JSONDocument doc;
  std::string value = "value";
  JSONData dta(value);
  JSONNode dataNode(NodeType::String, dta);
  JSONArray arr{dataNode};
  JSONData data(arr);
  JSONNode node(NodeType::Array, data);
  doc.setRoot(node);

  ASSERT_NO_THROW(doc[0]);
}
