// Copyright 2024 Soloninko Andrey

#include <gtest/gtest.h>
#include "include/huffman.h"

std::string encodeDecode(const std::string& text) {
  Huffman huffman;
  huffman.buildHuffmanTree(text);
  return huffman.decode(huffman.encode(text));
}

TEST(Soloninko_Huffman, Test_1) {
  Huffman huffman;
  std::string s1 = "amebus";
  ASSERT_NO_THROW(huffman.buildHuffmanTree(s1));
}

TEST(Soloninko_Huffman, Test_2) {
  std::string s1 = "Amogus amebus abobus";
  std::string dec_s1 = encodeDecode(s1);
  ASSERT_TRUE(s1 == dec_s1);
}

TEST(Soloninko_Huffman, Test_3) {
  std::string s1 = "Aa";
  std::string dec_s1 = encodeDecode(s1);
  ASSERT_TRUE(s1 == dec_s1);
}

TEST(Soloninko_Huffman, Test_4) {
  std::string s1 = "erthrtth rthyjyjth sadgdfghth rtjhtyjh rteghtjty";
  std::string dec_s1 = encodeDecode(s1);
  ASSERT_TRUE(s1 == dec_s1);
}

TEST(Soloninko_Huffman, Test_5) {
  std::string s1 = "amebus";
  std::string dec_s1 = encodeDecode(s1);
  ASSERT_TRUE(s1 == dec_s1);
}

TEST(Soloninko_Huffman, Test_6) {
  std::string s1 = "@@@Qwer11yuiop&%";
  std::string dec_s1 = encodeDecode(s1);
  ASSERT_TRUE(s1 == dec_s1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
