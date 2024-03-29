// Copyright 2024 Vanushkin Dmitry

#include <gtest/gtest.h>
#include "include/base64_converter.h"

TEST(Vanuskin_Dmitry_Base64DecoderTests, DecodeEmptyMessage) {
    auto encodedMessage = "";
    auto expectResult = "";

    ASSERT_EQ(Base64Decoder(encodedMessage).Decode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64DecoderTests, DecodeSingleCharAMessage) {
    auto encodedMessage = "QQ==";
    auto expectResult = "A";

    ASSERT_EQ(Base64Decoder(encodedMessage).Decode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64DecoderTests, DecodeSplashCharMessage) {
    auto encodedMessage = "XA==";
    auto expectResult = "\\";

    ASSERT_EQ(Base64Decoder(encodedMessage).Decode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64DecoderTests, DecodeNewLineCharMessage) {
    auto encodedMessage = "Cg==";
    auto expectResult = "\n";

    ASSERT_EQ(Base64Decoder(encodedMessage).Decode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64DecoderTests, DecodeHeMessage) {
    auto encodedMessage = "SGU=";
    auto expectResult = "He";

    ASSERT_EQ(Base64Decoder(encodedMessage).Decode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64DecoderTests, DecodeHellMessage) {
    auto encodedMessage = "SGVsbA==";
    auto expectResult = "Hell";

    ASSERT_EQ(Base64Decoder(encodedMessage).Decode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64DecoderTests, DecodeHelloWorldMessage) {
    auto encodedMessage = "SGVsbG8gd29ybGQh";
    auto expectResult = "Hello world!";

    ASSERT_EQ(Base64Decoder(encodedMessage).Decode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64DecoderTests, DecodeLowLevelBytes) {
    auto encodedMessage = "f359f3sIBQ0AAX8=";
    auto expectResult = std::string(
            {127, 126, 125, 127, 123, 8, 5, 13, 0, 1, 127});

    ASSERT_EQ(Base64Decoder(encodedMessage).Decode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64DecoderTests, DecodeEncodedFirstTestCodeAsMessage) {
    auto encodedMessage = "VEVTVChWYW51c2tpbl9EbWl0cnlfQmFzZTY0RW5jb"
                          "2RlclRlc3RzLCBFbmNvZGVFbXB0eU1lc3NhZ2UpIHsKICAg"
                          "IGF1dG8gbWVzc2FnZSA9ICIiOwogICAgYXV0byBleHBlY3RS"
                          "ZXN1bHQgPSAiIjsKCiAgICBBU1NFUlRfRVEoQmFzZTY0RW5jb"
                          "2RlcihtZXNzYWdlKS5FbmNvZGUoKSw"
                          "gZXhwZWN0UmVzdWx0KTsKfQ==";
    auto expectResult = R"(TEST(Vanuskin_Dmitry_Base64EncoderTests, EncodeEmptyMessage) {
    auto message = "";
    auto expectResult = "";

    ASSERT_EQ(Base64Encoder(message).Encode(), expectResult);
})";

    ASSERT_EQ(Base64Decoder(encodedMessage).Decode(), expectResult);
}

TEST(Vanuskin_Dmitry_Base64DecoderTests,
     DecodeMessageWithMoreThan2TimesSpecificSymbols) {
    auto encodedMessage = "===";

    auto decoder = Base64Decoder(encodedMessage);

    ASSERT_ANY_THROW(decoder.Decode());
}

TEST(Vanuskin_Dmitry_Base64DecoderTests,
     DecodeMessageWith4TimesSpecificSymbols) {
    auto encodedMessage = "3PL=AM=Q=L=B";

    auto decoder = Base64Decoder(encodedMessage);

    ASSERT_ANY_THROW(decoder.Decode());
}

TEST(Vanuskin_Dmitry_Base64DecoderTests,
     DecodeMessageWith3TimesSpecificSymbols) {
    auto encodedMessage = "31===";

    auto decoder = Base64Decoder(encodedMessage);

    ASSERT_ANY_THROW(decoder.Decode());
}

TEST(Vanuskin_Dmitry_Base64DecoderTests,
     DecodeMessageWithInvalidSpecificSymbolsPositions) {
    auto encodedMessage = "A=B=";

    auto decoder = Base64Decoder(encodedMessage);

    ASSERT_ANY_THROW(decoder.Decode());
}

TEST(Vanuskin_Dmitry_Base64DecoderTests,
     DecodeMessageWithInvalidSymbols) {
    auto encodedMessage = "AB;CDEFG";

    auto decoder = Base64Decoder(encodedMessage);

    ASSERT_ANY_THROW(decoder.Decode());
}

TEST(Vanuskin_Dmitry_Base64DecoderTests,
     DecodeMessageWithNotEnoughSpecificSymbols) {
    auto encodedMessage = "QQ=";

    auto decoder = Base64Decoder(encodedMessage);

    ASSERT_ANY_THROW(decoder.Decode());
}

TEST(Vanuskin_Dmitry_Base64DecoderTests,
     DecodeMessageWithOnlySpeciicSymbols) {
    auto encodedMessage = "====";

    auto decoder = Base64Decoder(encodedMessage);

    ASSERT_ANY_THROW(decoder.Decode());
}
