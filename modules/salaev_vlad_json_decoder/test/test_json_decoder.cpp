// Copyright 2024 Salaev Vladislav

#include <gtest/gtest.h>
#include <include/json_decoder.h>

TEST(Salaev_Vlad_JsonDecoderTest, CanStringDecode) {
    std::string json = R"({"StringTest": "success"})";
    size_t index = 0;
    JsonValue result = parseJson(json, index);
    EXPECT_EQ(result.objectValues["StringTest"].type, JsonType::String);
    EXPECT_EQ(result.objectValues["StringTest"].stringValue, "success");
}

TEST(Salaev_Vlad_JsonDecoderTest, CanIntDecode) {
    std::string json = R"({"IntTest": 1})";
    size_t index = 0;
    JsonValue result = parseJson(json, index);
    EXPECT_EQ(result.objectValues["IntTest"].type, JsonType::Number);
    EXPECT_EQ(result.objectValues["IntTest"].numberValue, 1);
}

TEST(Salaev_Vlad_JsonDecoderTest, CanFloatDecode) {
    std::string json = R"({"FloatTest": 1.1})";
    size_t index = 0;
    JsonValue result = parseJson(json, index);
    EXPECT_EQ(result.objectValues["FloatTest"].type, JsonType::Number);
    EXPECT_DOUBLE_EQ(result.objectValues["FloatTest"].numberValue, 1.1);
}

TEST(Salaev_Vlad_JsonDecoderTest, CanNullDecode) {
    std::string json = R"({"NullTest": null})";
    size_t index = 0;
    JsonValue result = parseJson(json, index);
    EXPECT_EQ(result.objectValues["NullTest"].type, JsonType::Null);
}

TEST(Salaev_Vlad_JsonDecoderTest, CanBooleanDecode) {
    std::string json = R"({"TrueTest": true, "FalseTest": false})";
    size_t index = 0;
    JsonValue result = parseJson(json, index);
    EXPECT_EQ(result.objectValues["TrueTest"].type, JsonType::Boolean);
    EXPECT_TRUE(result.objectValues["TrueTest"].booleanValue);
    EXPECT_EQ(result.objectValues["FalseTest"].type, JsonType::Boolean);
    EXPECT_FALSE(result.objectValues["FalseTest"].booleanValue);
}

TEST(Salaev_Vlad_JsonDecoderTest, CanArrayDecode) {
    std::string json = R"({"ArrayTest": ["string", 1, null, false]})";
    size_t index = 0;
    JsonValue result = parseJson(json, index);
    EXPECT_EQ(result.objectValues["ArrayTest"].type, JsonType::Array);
    EXPECT_EQ(result.objectValues["ArrayTest"].arrayValues[0].type,
        JsonType::String);
    EXPECT_EQ(result.objectValues["ArrayTest"].arrayValues[0].stringValue,
        "string");
    EXPECT_EQ(result.objectValues["ArrayTest"].arrayValues[1].type,
        JsonType::Number);
    EXPECT_EQ(result.objectValues["ArrayTest"].arrayValues[1].numberValue,
        1);
    EXPECT_EQ(result.objectValues["ArrayTest"].arrayValues[2].type,
        JsonType::Null);
    EXPECT_EQ(result.objectValues["ArrayTest"].arrayValues[3].type,
        JsonType::Boolean);
    EXPECT_FALSE(result.objectValues["ArrayTest"].arrayValues[3].booleanValue);
}

TEST(Salaev_Vlad_JsonDecoderTest, CanNestedArrayDecode) {
    std::string json = R"({"ArrayTest": ["string", ["array"]]})";
    size_t index = 0;
    JsonValue result = parseJson(json, index);
    EXPECT_EQ(result.objectValues["ArrayTest"].type, JsonType::Array);
    EXPECT_EQ(result.objectValues["ArrayTest"].arrayValues[0].type,
        JsonType::String);
    EXPECT_EQ(result.objectValues["ArrayTest"].arrayValues[0].stringValue,
        "string");
    EXPECT_EQ(result.objectValues["ArrayTest"].arrayValues[1].type,
        JsonType::Array);
    EXPECT_EQ(result.objectValues["ArrayTest"].arrayValues[1].arrayValues[
        0].stringValue, "array");
}

TEST(Salaev_Vlad_JsonDecoderTest, CanObjectDecode) {
    std::string json = R"({"ObjectTest": {"int": 1}})";
    size_t index = 0;
    JsonValue result = parseJson(json, index);
    EXPECT_EQ(result.objectValues["ObjectTest"].type, JsonType::Object);
    EXPECT_EQ(result.objectValues["ObjectTest"].objectValues["int"].type,
        JsonType::Number);
    EXPECT_EQ(result.objectValues["ObjectTest"].objectValues["int"].numberValue,
        1);
}

TEST(Salaev_Vlad_JsonDecoderTest, CanNestedObjectDecode) {
    std::string json = R"({"ObjectTest": {"object": {"int": 1}}})";
    size_t index = 0;
    JsonValue result = parseJson(json, index);
    EXPECT_EQ(result.objectValues["ObjectTest"].type, JsonType::Object);
    EXPECT_EQ(result.objectValues["ObjectTest"].objectValues["object"].type,
        JsonType::Object);
    EXPECT_EQ(result.objectValues["ObjectTest"].objectValues[
        "object"].objectValues["int"].type, JsonType::Number);
    EXPECT_EQ(result.objectValues["ObjectTest"].objectValues[
        "object"].objectValues["int"].numberValue, 1);
}

TEST(Salaev_Vlad_JsonDecoderTest, WrongJsonInput) {
    std::string json = R"({'test': "unsuccess"})";
    size_t index = 0;
    EXPECT_THROW(parseJson(json, index), std::runtime_error);
}

TEST(Salaev_Vlad_JsonDecoderTest, SupportEscapedCharacters) {
    std::string json = R"({"Coordinate \"X\"": 24.0124010872935, "Coordinate \"Y\"":49.7740722529036})";
    size_t index = 0;
    JsonValue js = parseJson(json, index);
    auto key = js.objectValues.begin();
    EXPECT_EQ(key->first, "Coordinate \"X\"");
    ++key;
    EXPECT_EQ(key->first, "Coordinate \"Y\"");
}

TEST(Salaev_Vlad_JsonDecoderTest, ParseAllDataTypes) {
    std::string json = R"({"str": "string", "num": 1, "bool": true, "null": null, "array": [], "object": {}})";
    size_t index = 0;
    JsonValue result = parseJson(json, index);
    EXPECT_EQ(result.objectValues["str"].type, JsonType::String);
    EXPECT_EQ(result.objectValues["num"].type, JsonType::Number);
    EXPECT_EQ(result.objectValues["bool"].type, JsonType::Boolean);
    EXPECT_EQ(result.objectValues["null"].type, JsonType::Null);
    EXPECT_EQ(result.objectValues["array"].type, JsonType::Array);
    EXPECT_EQ(result.objectValues["object"].type, JsonType::Object);
}
