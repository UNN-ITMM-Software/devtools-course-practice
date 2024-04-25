// Copyright 2024 Smirnov Leonid

#include <gtest/gtest.h>
#include "include/caesar_cipher.h"

TEST(Smirnov_Leonid_Caesar_Cipher, OffsetOutOfRange) {
    // Проверка возникновения исключения для неккоректного значения сдвига:
    EXPECT_THROW(CaesarCipher cipher(0), std::invalid_argument);
    EXPECT_THROW(CaesarCipher cipher(-3), std::invalid_argument);
    EXPECT_THROW(CaesarCipher cipher(26), std::invalid_argument);
    EXPECT_THROW(CaesarCipher cipher(36), std::invalid_argument);
}

TEST(CaesarCipherTest, OffsetInRange) {
    // Проверка невозникновения исключения для граничных значений сдвига:
    EXPECT_NO_THROW(CaesarCipher cipher(1));
    EXPECT_NO_THROW(CaesarCipher cipher(25));
}

TEST(CaesarCipherTest, EmptyInputForEncoderMethod) {
    // Проверка возникновения исключения на пустую строку для кодировки:
    CaesarCipher cipher(3);
    EXPECT_THROW(cipher.CaesarCipherEncoder(""), std::invalid_argument);
}

TEST(CaesarCipherTest, EmptyInputForDecoderMethod) {
    // Проверка возникновения исключения на пустую строку для расшифровки:
    CaesarCipher cipher(3);
    EXPECT_THROW(cipher.CaesarCipherDecoder(""), std::invalid_argument);
}

TEST(CaesarCipherTest, EncodeUppercaseLetters) {
    // Проверка корректности шифрования для строки заглавных букв:
    CaesarCipher cipher(3);
    EXPECT_EQ(cipher.CaesarCipherEncoder("ABC"), "DEF");
    EXPECT_EQ(cipher.CaesarCipherEncoder("XYZ"), "ABC");
    EXPECT_EQ(cipher.CaesarCipherEncoder("HELLO"), "KHOOR");
}

TEST(CaesarCipherTest, EncodeLowercaseLetters) {
    // Проверка корректности шифрования для строки строчных букв:
    CaesarCipher cipher(3);
    EXPECT_EQ(cipher.CaesarCipherEncoder("abc"), "def");
    EXPECT_EQ(cipher.CaesarCipherEncoder("xyz"), "abc");
    EXPECT_EQ(cipher.CaesarCipherEncoder("hello"), "khoor");
}

TEST(CaesarCipherTest, NonAlphabeticCharacters) {
    // Проверка на неизменчивость неалфавитных символов:
    CaesarCipher cipher(3);
    EXPECT_EQ(cipher.CaesarCipherEncoder("123"), "123");
    EXPECT_EQ(cipher.CaesarCipherEncoder("!*?"), "!*?");
}

TEST(CaesarCipherTest, DecodeUppercaseLetters) {
    // Проверка корректности дешифрования для строки заглавных букв:
    CaesarCipher cipher(3);
    EXPECT_EQ(cipher.CaesarCipherDecoder("DEF"), "ABC");
    EXPECT_EQ(cipher.CaesarCipherDecoder("ABC"), "XYZ");
    EXPECT_EQ(cipher.CaesarCipherDecoder("KHOOR"), "HELLO");
}

TEST(CaesarCipherTest, DecodeLowercaseLetters) {
    // Проверка корректности дешифрования для строки строчных букв:
    CaesarCipher cipher(3);
    EXPECT_EQ(cipher.CaesarCipherDecoder("def"), "abc");
    EXPECT_EQ(cipher.CaesarCipherDecoder("abc"), "xyz");
    EXPECT_EQ(cipher.CaesarCipherDecoder("khoor"), "hello");
}

TEST(CaesarCipherTest, NonAlphabeticCharactersDecoder) {
    // Проверка на неизменчивость неалфавитных символов при дешифровании:
    CaesarCipher cipher(3);
    EXPECT_EQ(cipher.CaesarCipherDecoder("123"), "123");
    EXPECT_EQ(cipher.CaesarCipherDecoder("!*?"), "!*?");
}

TEST(CaesarCipherTest, SpacesInString) {
    // Проверка, что пробелы не влияют на шифрование и дешифрование
    CaesarCipher cipher(3);
    EXPECT_EQ(cipher.CaesarCipherEncoder("A B C"), "D E F");
    EXPECT_EQ(cipher.CaesarCipherDecoder("D E F"), "A B C");
}

TEST(CaesarCipherTest, LargeStrings) {
    // Проверка на шифрование и дешифрование для больших строк
    CaesarCipher cipher(5);
    std::string plaintext(1000, 'L');
    std::string encrypted = cipher.CaesarCipherEncoder(plaintext);
    EXPECT_EQ(cipher.CaesarCipherDecoder(encrypted), plaintext);
}

TEST(CaesarCipherTest, NonEnglishCharacters) {
    // Проверка на отсутствие шифрования русских букв
    CaesarCipher cipher(1);
    EXPECT_EQ(cipher.CaesarCipherEncoder("абв"), "абв");
    EXPECT_EQ(cipher.CaesarCipherDecoder("где"), "где");
}

TEST(CaesarCipherTest, WordsWithDifferentRegister) {
    // Проверка на шифрование строк, с различными регистрами
    CaesarCipher cipher(1);
    EXPECT_EQ(cipher.CaesarCipherEncoder("AbC"), "BcD");
    EXPECT_EQ(cipher.CaesarCipherEncoder("HeLLo"), "IfMMp");
    EXPECT_EQ(cipher.CaesarCipherEncoder("XyZ"), "YzA");
}
