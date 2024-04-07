// Copyright 2024 Soloninko Andrey

#include <gtest/gtest.h>
#include "include/huffman.h"

TEST(Soloninko_Huffman, Test_1) {
  std::string s1 = "amebus";
  buildHuffmanTree(s1);
  ASSERT_NO_THROW(buildHuffmanTree(s1));
  dec_str="";
}

TEST(Soloninko_Huffman, Test_2) {
  std::string s1 = "Amogus amebus abobus";
  buildHuffmanTree(s1);
  ASSERT_TRUE(compare_str(s1, dec_str));
  dec_str="";
}

TEST(Soloninko_Huffman, Test_3) {
  std::string s1 = "Aa";
  buildHuffmanTree(s1);
  ASSERT_TRUE(compare_str(s1, dec_str));
  dec_str="";
}

TEST(Soloninko_Huffman, Test_4) {
  std::string s1 = "erthrtth rthyjyjth sadgdfghth rtjhtyjh rteghtjty";
  buildHuffmanTree(s1);
  ASSERT_TRUE(compare_str(s1, dec_str));
  dec_str="";
}

TEST(Soloninko_Huffman, Test_5) {
  std::string s1 = "amebus";
  buildHuffmanTree(s1);
  ASSERT_TRUE(compare_str(s1, dec_str));
  dec_str="";
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}