// Copyright 2024 Nogin Denis

#include <gtest/gtest.h>

#include "include/vigenere_cipher.h"

TEST(Nogin_Denis_VigenereCipherTest, test_cipher_1) {
  std::string data("hello world!");
  std::string key("key");

  std::string cipher = vigenereCipher(data, key);

  EXPECT_EQ("rijvs uyvjn!", cipher);
}

TEST(Nogin_Denis_VigenereCipherTest, test_cipher_2) {
  std::string data("HeLlO WORld!");
  std::string key("KEy");

  std::string cipher = vigenereCipher(data, key);

  EXPECT_EQ("RiJvS UYVjn!", cipher);
}

TEST(Nogin_Denis_VigenereCipherTest, test_cipher_3) {
  std::string data("One, two, three, four!");
  std::string key("Five");

  std::string cipher = vigenereCipher(data, key);

  EXPECT_EQ("Tvz, xbw, olwmz, jtcm!", cipher);
}

TEST(Nogin_Denis_VigenereCipherTest, test_cipher_4) {
  std::string data("key");
  std::string key("hello");

  std::string cipher = vigenereCipher(data, key);

  EXPECT_EQ("rij", cipher);
}

TEST(Nogin_Denis_VigenereCipherTest, test_cipher_5) {
  std::string data("key");
  std::string key("hello");

  std::string cipher = vigenereCipher(data, key);

  EXPECT_EQ("rij", cipher);
}

TEST(Nogin_Denis_VigenereCipherTest, test_decipher_1) {
  std::string data("hello world!");
  std::string key("key");

  std::string cipher = vigenereCipher(data, key);
  std::string decipher = vigenereDecipher(cipher, key);

  EXPECT_EQ(data, decipher);
}

TEST(Nogin_Denis_VigenereCipherTest, test_decipher_2) {
  std::string data("HeLlO WORld!");
  std::string key("KEy");

  std::string cipher = vigenereCipher(data, key);
  std::string decipher = vigenereDecipher(cipher, key);

  EXPECT_EQ(data, decipher);
}

TEST(Nogin_Denis_VigenereCipherTest, test_decipher_3) {
  std::string data("rij");
  std::string key("hello");

  std::string decipher = vigenereDecipher(data, key);

  EXPECT_EQ("key", decipher);
}

TEST(Nogin_Denis_VigenereCipherTest, test_decipher_4) {
  std::string data("One, two, three, four!");
  std::string key("Five");

  std::string decipher = vigenereDecipher(data, key);

  EXPECT_EQ("Jfj, prg, ydmwj, bjmw!", decipher);
}

TEST(Nogin_Denis_VigenereCipherTest, test_invalid_key) {
  std::string data("One, two, three, four!");
  std::string key1("Five-1--4234--523-523--./$#@");
  std::string key2{};

  ASSERT_EQ(vigenereCipher(data, key1), std::string{});
  ASSERT_EQ(vigenereCipher(data, key2), std::string{});
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
