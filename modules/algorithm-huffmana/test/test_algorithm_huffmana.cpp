// Copyright 2021 Ludina Daria

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/algorithm_huffmana.h"

TEST(Algorithm_Huffmana, Can_Create_Histoghram_1) {
  std::string text = "AAASREESR";
  std::vector<int> expected = { 3, 2, 2, 2};

  std::vector<int> v = HuffmanTree().CreateHistogram(text);
  std::vector<int> res = { v['A'], v['S'], v['R'], v['E'] };

  ASSERT_EQ(expected, res);
}

TEST(Algorithm_Huffmana, Can_Create_Histoghram_2) {
  std::string text = "AAARAARRREREESRR";
  std::vector<int> expected = { 5, 1, 7, 3};

  std::vector<int> v = HuffmanTree().CreateHistogram(text);
  std::vector<int> res = { v['A'], v['S'], v['R'], v['E']};

  ASSERT_EQ(expected, res);
}

TEST(Algorithm_Huffmana, Can_Create_Encoding_Table_1) {
  std::string text = "AAASAAAAREEAAAAAAAAAAASR";
  std::string expect = "1";

  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  ASSERT_EQ(expect, Tree.getSimbolCode('A'));
}

TEST(Algorithm_Huffmana, Can_Create_Encoding_Table_2) {
  std::string text = "AASRRR";
  std::string expect = "1";

  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  ASSERT_EQ(expect, Tree.getSimbolCode('R'));
}

TEST(Algorithm_Huffmana, Huffman_Coding_Test_1) {
  std::string text = "AAASRERASR";
  std::vector<std::string> vec = { "1", "1", "1",
    "001", "01", "0001", "01", "1", "001", "01"};

  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  ASSERT_EQ(vec, Tree.Encode(text));
}

TEST(Algorithm_Huffmana, Huffman_Coding_Test_2) {
  std::string text = "AAASRERTWTASR";
  std::vector<std::string> vec = { "01", "01", "01",
    "000", "10", "111", "10", "001", "1101", "001",
    "01", "000", "10" };

  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  ASSERT_EQ(vec, Tree.Encode(text));
}
