// Copyright 2021 Ostapovich Denis

#include <gtest/gtest.h>

#include <include/json-deserializer.h>

#include <string>

TEST(JsonDeserializer, Can_Create_Deserializer_Without_Parameters) {
    ASSERT_NO_THROW(JsonDeserializer j);
}

TEST(JsonDeserializer, Can_Create_Deserializer_With_Default_String) {
    JsonDeserializer j;

    ASSERT_TRUE(j.getString().empty());
}

TEST(JsonDeserializer, Parse_Throws_On_Empty_String) {
    JsonDeserializer des;

    ASSERT_ANY_THROW(des.parse(""));
}

TEST(JsonDeserializer, Parse_Returns_Struct) {
    JsonDeserializer des;

    ASSERT_NO_THROW(des.parse("    \"abcdef\""));
}
