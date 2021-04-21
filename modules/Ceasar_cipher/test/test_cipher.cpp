// Copyright 2021 Kudriavtsev Alexandr
#include <gtest/gtest.h>

#include "include/cipher.h"

TEST(CEASAR_CIPHER, no_exception_with_empty_string) {
    Crypthography::CeasarCipher CC;
    const std::string test = "";
    ASSERT_NO_THROW(CC.Decode(test));
    ASSERT_NO_THROW(CC.Encode(test));
}

TEST(CEASAR_CIPHER, nothings_happens_with_empty_string_enc) {
    Crypthography::CeasarCipher CC;
    std::string test, enc;
    ASSERT_NO_THROW(enc = CC.Encode(test));
    ASSERT_EQ(test, enc);
}

TEST(CEASAR_CIPHER, nothings_happens_with_empty_string_dec) {
    Crypthography::CeasarCipher CC;
    const std::string test;
    std::string dec;
    ASSERT_NO_THROW(dec = CC.Decode(test));
    ASSERT_EQ(test, dec);
}

TEST(CEASAR_CIPHER, decode_is_working_as_expected_1) {
    Crypthography::CeasarCipher CC;
    const std::string test = "BCD bcd", expDec = "ABC abc";
    std::string dec;
    ASSERT_NO_THROW(dec = CC.Decode(test));
    ASSERT_EQ(expDec, dec);
}

TEST(CEASAR_CIPHER, encode_is_working_as_expected_1) {
    Crypthography::CeasarCipher CC;
    const std::string test = "ABC abc", expEnc = "BCD bcd";
    std::string enc;
    ASSERT_NO_THROW(enc = CC.Encode(test));
    ASSERT_EQ(expEnc, enc);
}

TEST(CEASAR_CIPHER, decode_is_working_as_expected_with_big_key_mod1) {
    Crypthography::CeasarCipher CC;
    int key = (rand() % 100) * 26 + 1;
    const std::string test = "BCD bcd", expDec = "ABC abc";
    std::string dec;
    ASSERT_NO_THROW(dec = CC.Decode(test, key));
    ASSERT_EQ(expDec, dec);
}

TEST(CEASAR_CIPHER, encode_is_working_as_expected_with_big_key_mod1) {
    Crypthography::CeasarCipher CC;
    int key = (rand() % 100) * 26 + 1;
    const std::string test = "ABC abc", expEnc = "BCD bcd";
    std::string enc;
    ASSERT_NO_THROW(enc = CC.Encode(test, key));
    ASSERT_EQ(expEnc, enc);
}

TEST(CEASAR_CIPHER, decode_is_working_as_expected_with_all_small_alphabet_with_big_key_mod2) {
    Crypthography::CeasarCipher CC;
    int key = (rand() % 100) * 26 + 2;
    const std::string test = "c d e f g h i j k l m n o p q r s t u v w x y z a b"; 
    const std::string expDec = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    std::string dec;
    ASSERT_NO_THROW(dec = CC.Decode(test, key));
    ASSERT_EQ(expDec, dec);
}

TEST(CEASAR_CIPHER, encode_is_working_as_expected_with_all_small_alphabet_with_big_key_mod2) {
    Crypthography::CeasarCipher CC;
    int key = (rand() % 100) * 26 + 2;
    const std::string test = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    const std::string expEnc = "c d e f g h i j k l m n o p q r s t u v w x y z a b";
    std::string enc;
    ASSERT_NO_THROW(enc = CC.Encode(test, key));
    ASSERT_EQ(expEnc, enc);
}



TEST(CEASAR_CIPHER, decode_plus_encode_is_the_same_string_1) {
    Crypthography::CeasarCipher CC;
    const std::string test = "ABC";
    const std::string dec = CC.Decode(test, 1);
    const std::string encdec = CC.Encode(dec, 1);
    ASSERT_EQ(test, encdec);
}

TEST(CEASAR_CIPHER, decode_plus_encode_is_the_same_string_random_key) {
    Crypthography::CeasarCipher CC;
    const std::string test = "ABCabc";
    int key = rand() % 100;
    const std::string dec = CC.Decode(test, key);
    const std::string encdec = CC.Encode(dec, key);
    ASSERT_EQ(test, encdec);
}

// Smart tests for EDFH. (Carnelia ch1)
TEST(CEASAR_CIPHER, decode_plus_encode_is_the_same_now_big_string_random_key) {
    Crypthography::CeasarCipher CC;
    const std::string test = "I stood there, upright in front of the revolving door, scuffing the heels of my boots against the ground.";
    int key = rand() % 100;
    const std::string dec = CC.Decode(test, key);
    const std::string encdec = CC.Encode(dec, key);
    ASSERT_EQ(test, encdec);
}

TEST(CEASAR_CIPHER, decode_twice_with_random_key_equals_decode_with_double_key) {
    Crypthography::CeasarCipher CC;
    int key = rand() % 100;
    const std::string test = "Pulling slightly on the collar of my trench coat, I dropped my chinand gazed at my partial reflection in the curved glass.";
    const std::string dec = CC.Decode(test, key);
    const std::string decdec = CC.Decode(dec, key);
    const std::string dec2 = CC.Encode(test, 2 * key);
    ASSERT_EQ(decdec, dec2);
}

TEST(CEASAR_CIPHER, encode_twice_with_random_key_equals_decode_with_double_key) {
    Crypthography::CeasarCipher CC;
    int key = rand() % 100;
    const std::string test = "Aside from my short-cropped hair, I wore a modest-looking, double-breasted leather raincoat and a pair of special order, steel-reinforced boots,";
    const std::string enc = CC.Encode(test, key);
    const std::string encenc = CC.Encode(enc, key);
    const std::string enc2 = CC.Encode(test, 2 * key);
    ASSERT_EQ(encenc, enc2);
}

TEST(CEASAR_CIPHER, decode_and_encode_with_0_key_is_the_same_string) {
    Crypthography::CeasarCipher CC;
    const std::string test = "both of which at first glance appear to be the most common of common apparel. Yet, they were in fact, much more than the naked eye could detect.";
    const std::string dec = CC.Decode(test, 0);
    const std::string encdec = CC.Encode(test, 0);
    ASSERT_EQ(test, dec);
}