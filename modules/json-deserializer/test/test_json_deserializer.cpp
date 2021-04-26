// Copyright 2021 Ostapovich Denis

#include <gtest/gtest.h>

#include <include/json-deserializer.h>

#include <string>

TEST(Json, Can_Create_Json_Struct) {
    ASSERT_NO_THROW(Json j);
}

TEST(Json, Can_Copy_Json_Struct) {
    Json src;

    ASSERT_NO_THROW(Json dst(src));
}

TEST(JsonDeserializer, Can_Create_Deserializer_Without_Parameters) {
    ASSERT_NO_THROW(JsonDeserializer j);
}

TEST(JsonDeserializer, Can_Create_Deserializer_With_Default_String) {
    JsonDeserializer j;

    ASSERT_TRUE(j.getString().empty());
}

TEST(JsonDeserializer, From_Json_Throws_On_Empty_String) {
    JsonDeserializer des;

    ASSERT_ANY_THROW(des.fromString(""));
}

TEST(JsonDeserializer, From_Json_Returns_Struct) {
    JsonDeserializer des;

    ASSERT_NO_THROW(des.fromString("abcdef"));
}
