//
// Created by Стёпа Кашин on 24.03.2024.
//

#include <gtest/gtest.h>
#include <iostream>
#include "include/GronsfeldCipher.h"


TEST(Kashin_Stepan_Gronsfeld_Cipher, InvalidInputConstructor) {
    EXPECT_THROW(GronsfeldCipher("sdfsd123sdsd"));
    EXPECT_THROW(GronsfeldCipher("code,-code"));
    EXPECT_THROW(GronsfeldCipher("ПРИВЕТ"));
    EXPECT_THROW(GronsfeldCipher(""));
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InputConstructor) {
    EXPECT_NO_THROW(GronsfeldCipher());
    EXPECT_NO_THROW(GronsfeldCipher("CoDe"));
    EXPECT_NO_THROW(GronsfeldCipher("abcdefghijclmnop"));
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InvalidInputEncoder) {
    EXPECT_THROW(GronsfeldCipher("code").encoder(""));
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InputEncoder) {
    EXPECT_NO_THROW(GronsfeldCipher("code").encoder("hello, world!"));
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InvalidInputDecoder) {
    EXPECT_THROW(GronsfeldCipher("code").encoder(""));
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InputDecoder) {
    EXPECT_NO_THROW(GronsfeldCipher("code").encoder("hello, world!"));
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InvalidInputgetCrackKey) {
    EXPECT_THROW(GronsfeldCipher().getCrackKey("",4));
    EXPECT_THROW(GronsfeldCipher().getCrackKey("code",5));
    EXPECT_THROW(GronsfeldCipher().getCrackKey("code",0));
}

TEST(Kashin_Stepan_Gronsfeld_Cipher, InputgetCrackKey) {
    EXPECT_NO_THROW(GronsfeldCipher().getCrackKey("code",0));
}
