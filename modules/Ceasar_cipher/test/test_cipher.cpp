// Copyright 2021 Kudriavtsev Alexandr
#include <gtest/gtest.h>
#include <string>
#include <random>
#include <ctime>

#include "include/cipher.h"

TEST(CEASAR_CIPHER, no_exception_with_empty_string) {
    CeasarCipher CC;
    const std::string test = "";

    ASSERT_NO_THROW(CC.Decode(test));
    ASSERT_NO_THROW(CC.Encode(test));
}

TEST(CEASAR_CIPHER, nothings_happens_with_empty_string_enc) {
    CeasarCipher CC;
    std::string test, enc;

    ASSERT_NO_THROW(enc = CC.Encode(test));
    ASSERT_EQ(test, enc);
}

TEST(CEASAR_CIPHER, nothings_happens_with_empty_string_dec) {
    CeasarCipher CC;
    const std::string test;

    std::string dec;
    ASSERT_NO_THROW(dec = CC.Decode(test));
    ASSERT_EQ(test, dec);
}

TEST(CEASAR_CIPHER, decode_is_working_as_expected_1) {
    CeasarCipher CC;
    const std::string test = "BCD bcd", expDec = "ABC abc";

    std::string dec;
    ASSERT_NO_THROW(dec = CC.Decode(test));
    ASSERT_EQ(expDec, dec);
}

TEST(CEASAR_CIPHER, encode_is_working_as_expected_1) {
    CeasarCipher CC;
    const std::string test = "ABC abc", expEnc = "BCD bcd";

    std::string enc;
    ASSERT_NO_THROW(enc = CC.Encode(test));
    ASSERT_EQ(expEnc, enc);
}

TEST(CEASAR_CIPHER, decode_is_working_as_expected_with_big_key_mod1) {
    CeasarCipher CC;
    std::mt19937 gen;
    gen.seed(time(0) + 1);
    int key = (gen() % 100) * 26 + 1;
    const std::string test = "BCD bcd", expDec = "ABC abc";

    std::string dec;
    ASSERT_NO_THROW(dec = CC.Decode(test, key));
    ASSERT_EQ(expDec, dec);
}

TEST(CEASAR_CIPHER, encode_is_working_as_expected_with_big_key_mod1) {
    CeasarCipher CC;
    std::mt19937 gen;
    gen.seed(time(0) + 1);
    int key = (gen() % 100) * 26 + 1;
    const std::string test = "ABC abc", expEnc = "BCD bcd";

    std::string enc;
    ASSERT_NO_THROW(enc = CC.Encode(test, key));
    ASSERT_EQ(expEnc, enc);
}

TEST(CEASAR_CIPHER, decode_is_working_with_all_s_alphabet_with_big_key_m2) {
    CeasarCipher CC;
    std::mt19937 gen;
    gen.seed(time(0) + 1);
    int key = (gen() % 100) * 26 + 2;
    std::string test = "c d e f g h i j k l m n o p q r s t u v w x y z a b";
    std::string expDec = "a b c d e f g h i j k l m n o p q r s t u v w x y z";

    std::string dec;
    ASSERT_NO_THROW(dec = CC.Decode(test, key));
    ASSERT_EQ(expDec, dec);
}

TEST(CEASAR_CIPHER, encode_is_working_with_all_s_alphabet_with_big_key_m2) {
    CeasarCipher CC;
    std::mt19937 gen;
    gen.seed(time(0) + 1);
    int key = (gen() % 100) * 26 + 2;

    std::string test = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    std::string expEnc = "c d e f g h i j k l m n o p q r s t u v w x y z a b";
    std::string enc;

    ASSERT_NO_THROW(enc = CC.Encode(test, key));
    ASSERT_EQ(expEnc, enc);
}



TEST(CEASAR_CIPHER, decode_plus_encode_is_the_same_string_1) {
    CeasarCipher CC;
    const std::string test = "ABC";

    const std::string dec = CC.Decode(test, 1);
    const std::string encdec = CC.Encode(dec, 1);

    ASSERT_EQ(test, encdec);
}

TEST(CEASAR_CIPHER, decode_plus_encode_is_the_same_string_random_key) {
    CeasarCipher CC;
    std::mt19937 gen;
    gen.seed(time(0) + 1);
    const std::string test = "ABCabc";
    int key = gen() % 100;

    const std::string dec = CC.Decode(test, key);
    const std::string encdec = CC.Encode(dec, key);

    ASSERT_EQ(test, encdec);
}

// Tests for EDFH.
TEST(CEASAR_CIPHER, decode_plus_encode_is_the_same_now_big_string_random_key) {
    CeasarCipher CC;
    const std::string test = "I stood there, upright in front of the revolving";
    std::mt19937 gen;
    gen.seed(time(0) + 2);
    int key = gen() % 25 + 1;

    const std::string dec = CC.Decode(test, key);
    const std::string encdec = CC.Encode(dec, key);
    ASSERT_NE(test, dec);
    ASSERT_EQ(test, encdec);
}

TEST(CEASAR_CIPHER, decode_twice_with_random_key_equals_decode_with_double_k) {
    CeasarCipher CC;
    std::mt19937 gen;
    gen.seed(time(0) + 3);
    int key = gen() % 25 + 1;
    const std::string test = "door, scuffing the heels of my boots against ";

    const std::string dec = CC.Decode(test, key);
    const std::string decdec = CC.Decode(dec, key);
    const std::string dec2 = CC.Decode(test, 2 * key);
    ASSERT_NE(test, dec);
    ASSERT_EQ(decdec, dec2);
}

TEST(CEASAR_CIPHER, encode_twice_with_random_key_equal_decode_with_double_k) {
    CeasarCipher CC;
    std::mt19937 gen;
    gen.seed(time(0) + 4);
    int key = gen() % 25 + 1;
    const std::string tst = "the ground. Pulling slightly on the collar of my";

    const std::string enc = CC.Encode(tst, key);
    const std::string encenc = CC.Encode(enc, key);
    const std::string enc2 = CC.Encode(tst, 2 * key);
    ASSERT_NE(tst, enc);
    ASSERT_EQ(encenc, enc2);
}

TEST(CEASAR_CIPHER, decode_and_encode_with_0_key_is_the_same_string) {
    CeasarCipher CC;
    const std::string test = "trench coat, I dropped my chin and gazed at my ";

    const std::string dec = CC.Decode(test, 0);
    const std::string enc = CC.Encode(test, 0);
    ASSERT_EQ(test, dec);
    ASSERT_EQ(test, enc);
}

// Key from encoded and decoded string

TEST(CEASAR_CIPHER, key_from_the_same_string_is_zero) {
    CeasarCipher CC;
    const std::string test = "partial reflection in the curved glass. Aside ";

    ASSERT_EQ(0, CC.GetKey(test, test));
}

TEST(CEASAR_CIPHER, GetKey_is_working_with_random_key) {
    CeasarCipher CC;
    std::mt19937 gen;
    gen.seed(time(0) + 7);
    int key = gen() % 26;
    const std::string ts = "from short-cropped hair, I wore a modest-looking,";

    const std::string enc = CC.Encode(ts, key);
    const std::string dec = ts;

    ASSERT_EQ(key, CC.GetKey(enc, dec));
}

TEST(CEASAR_CIPHER, GetKey_throws_exception_with_different_sizes) {
    CeasarCipher CC;
    std::string st1 = "double-breasted leather raincoat and a pair of";
    std::string st2 = "double-breasted leather raincoat and a pair of ";

    ASSERT_ANY_THROW(CC.GetKey(st1, st2));
}

TEST(CEASAR_CIPHER, GetKey_throws_exception_when_not_CC) {
    CeasarCipher CC;
    std::string st1 = "special order, steel-reinforced boots, both of which  ";
    std::string st2 = "at first glance appear to be the most common of common";

    ASSERT_ANY_THROW(CC.GetKey(st1, st2));
}

TEST(CEASAR_CIPHER, GetKey_throws_exception_when_string_is_empty) {
    CeasarCipher CC;
    std::string st1;
    std::string st2;

    ASSERT_ANY_THROW(CC.GetKey(st1, st2));
}

TEST(CEASAR_CIPHER, GetKey_is_working_with_key_25) {
    CeasarCipher CC;
    int key = 25;
    const std::string ts = " of common apparel. Yet, they were in fact, much";

    const std::string enc = CC.Encode(ts, key);
    const std::string dec = ts;

    ASSERT_EQ(key, CC.GetKey(enc, dec));
}
