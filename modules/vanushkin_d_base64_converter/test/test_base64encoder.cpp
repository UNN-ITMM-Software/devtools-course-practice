// Copyright 2024 Vanushkin Dmitry

#include <gtest/gtest.h>
#include "include/base64_converter.h"

TEST(Vanuskin_Dmitry_Base64EncoderTests, EncodeEmptyMessage) {
    auto message = "";
    auto expectResult = "";

    ASSERT_EQ(Base64Encoder(message).Encode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64EncoderTests, EncodeSingleCharAMessage) {
    auto message = "A";
    auto expectResult = "QQ==";

    ASSERT_EQ(Base64Encoder(message).Encode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64EncoderTests, EncodeSingleSpecialCharMessage) {
    auto message = "\\";
    auto expectResult = "XA==";

    ASSERT_EQ(Base64Encoder(message).Encode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64EncoderTests, EncodeSingleNewLineCharMessage) {
    auto message = "\n";
    auto expectResult = "Cg==";

    ASSERT_EQ(Base64Encoder(message).Encode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64EncoderTests, EncodeSpaceCharMessage) {
    auto message = " ";
    auto expectResult = "IA==";

    ASSERT_EQ(Base64Encoder(message).Encode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64EncoderTests, EncodeHelloWorldMessage) {
    auto message = "Hello world!";
    auto expectResult = "SGVsbG8gd29ybGQh";

    ASSERT_EQ(Base64Encoder(message).Encode(), expectResult);
}


TEST(Vanuskin_Dmitry_Base64EncoderTests, EncodeFirstTestCodeAsMessage) {
    auto message = R"(TEST(Vanuskin_Dmitry_Base64EncoderTests, EncodeEmptyMessage) {
    auto message = "";
    auto expectResult = "";

    ASSERT_EQ(Base64Encoder(message).Encode(), expectResult);
})";
    auto expectResult = "VEVTVChWYW51c2tpbl9EbWl0cnlfQmFzZT"
                        "Y0RW5jb2RlclRlc3RzLCBFbmNvZGVFbXB0eU1lc"
                        "3NhZ2UpIHsKICAgIGF1dG8gbWVzc2FnZSA9ICIiOw"
                        "ogICAgYXV0byBleHBlY3RSZXN1bHQgPSAiIjsKCiAgICB"
                        "BU1NFUlRfRVEoQmFzZTY0RW5jb2RlcihtZXNzYWdl"
                        "KS5FbmNvZGUoKSwgZXhwZWN0UmVzdWx0KTsKfQ==";

    ASSERT_EQ(Base64Encoder(message).Encode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64EncoderTests, EncodeCornerCharsFromAscii) {
    auto message = std::string({127, 126, 125, 127, 123, 8, 5, 13, 0, 1, 127});
    auto expectResult = "f359f3sIBQ0AAX8=";

    ASSERT_EQ(Base64Encoder(message).Encode(), expectResult);
}
