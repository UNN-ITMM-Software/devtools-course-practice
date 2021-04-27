// Copyright 2021 Aleksandrychev Andrey

#include <gtest/gtest.h>
#include <string>
#include "include/grosfeld_cipher.h"

TEST(Aleksandrychev_Andrey_Gronsfeld_Cipher, constructor) {
    ASSERT_NO_THROW(GronsfeldCipher("gronsfeld", 2015));
}

TEST(Aleksandrychev_Andrey_Gronsfeld_Cipher, getSourceFunction) {
    GronsfeldCipher gc = GronsfeldCipher("gronsfeld", 2015);
    std::string sourceString = "gronsfeld";

    ASSERT_EQ(sourceString, gc.getSource());
}

TEST(Aleksandrychev_Andrey_Gronsfeld_Cipher, getKeyFunction) {
    GronsfeldCipher gc = GronsfeldCipher("gronsfeld", 2015);
    int sourceKey = 2015;

    ASSERT_EQ(sourceKey, gc.getKey());
}

TEST(Aleksandrychev_Andrey_Gronsfeld_Cipher, getKeyStringFunction) {
    GronsfeldCipher gc = GronsfeldCipher("gronsfeld", 2015);
    std::string sourceKeyString = "201520152";

    ASSERT_EQ(sourceKeyString, gc.getKeyString());
}

TEST(Aleksandrychev_Andrey_Gronsfeld_Cipher, setKey) {
    GronsfeldCipher gc = GronsfeldCipher("gronsfeld", 2015);
    int newKey = 2014;
    gc.setKey(newKey);

    ASSERT_EQ(newKey, gc.getKey());
}

TEST(Aleksandrychev_Andrey_Gronsfeld_Cipher, setSourceString) {
    GronsfeldCipher gc = GronsfeldCipher("gronsfeld", 2015);
    std::string newSourceString = "gronsfeld2";
    gc.setSourceString(newSourceString);

    ASSERT_EQ(newSourceString, gc.getSource());
}

TEST(Aleksandrychev_Andrey_Gronsfeld_Cipher, decode) {
    std::string codeString = "irpsuffqf";
    int key = 2015;
    GronsfeldCipher gc = GronsfeldCipher("gronsfeld", key);

    ASSERT_EQ("gronsfeld", gc.decode("irpsuffqf", key));
}

TEST(Aleksandrychev_Andrey_Gronsfeld_Cipher, getCipher) {
    GronsfeldCipher gc = GronsfeldCipher("gronsfeld", 2015);
    std::string codeString = "irpsuffqf";

    ASSERT_EQ(codeString, gc.getCipher());
}
