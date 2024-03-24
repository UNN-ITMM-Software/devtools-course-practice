// Copyright 2024 Kashin Stepa

#include <gtest/gtest.h>
#include <iostream>
#include "include/GronsfeldCipher.h"


TEST(Kashin_Stepan_Gronsfeld_Cipher, InvalidInputConstructor) {
    EXPECT_THROW(
        GronsfeldCipher("sdfsd123sdsd"),
        TheStringContainsNonLatinCharacters);
    EXPECT_THROW(
        GronsfeldCipher("code,-code"),
        TheStringContainsNonLatinCharacters);
    EXPECT_THROW(
        GronsfeldCipher("ПРИВЕТ"),
        TheStringContainsNonLatinCharacters);
    EXPECT_THROW(
        GronsfeldCipher(""),
        TheStringDoesNotContainCharacters);
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InputConstructor) {
    EXPECT_NO_THROW(GronsfeldCipher());
    EXPECT_NO_THROW(GronsfeldCipher("CoDe"));
    EXPECT_NO_THROW(GronsfeldCipher("abcdefghijclmnop"));
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InvalidInputEncoder) {
    EXPECT_THROW(
        GronsfeldCipher("code").encoder(""),
        TheStringDoesNotContainCharacters);
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InputEncoder) {
    EXPECT_NO_THROW(GronsfeldCipher("code").encoder("hello, world!"));
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InvalidInputDecoder) {
    EXPECT_THROW(
        GronsfeldCipher("code").encoder(""),
        TheStringDoesNotContainCharacters);
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InputDecoder) {
    EXPECT_NO_THROW(GronsfeldCipher("code").encoder("hello, world!"));
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InvalidInputgetCrackKey) {
    EXPECT_THROW(
        GronsfeldCipher().getCrackKey("", 4),
        TheStringDoesNotContainCharacters);
    EXPECT_THROW(
        GronsfeldCipher().getCrackKey("code", 5),
        IncorrectKeyLength);
    EXPECT_THROW(
        GronsfeldCipher().getCrackKey("code", 0),
        IncorrectKeyLength);
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InputgetCrackKey) {
    EXPECT_NO_THROW(GronsfeldCipher().getCrackKey("code", 2));
}

TEST(Kashin_Stepan_Gronsfeld_Cipher,Other) {
    EXPECT_NO_THROW(GronsfeldCipher().getKey());
    EXPECT_NO_THROW(GronsfeldCipher().setKey("hi"));
}