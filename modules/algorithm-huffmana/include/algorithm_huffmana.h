// Copyright 2021 Ludina Daria

#ifndef MODULES_ALGORITHM_HUFFMANA_INCLUDE_ALGORITHM_HUFFMANA_H_
#define MODULES_ALGORITHM_HUFFMANA_INCLUDE_ALGORITHM_HUFFMANA_H_

#include <string>
#include <vector>

struct HuffmanNode {
  HuffmanNode* left;
  HuffmanNode* right;
  unsigned char value;
  int freq;
};

class HuffmanTree {
  HuffmanNode* root;
  std::vector<std::string> encodingTable;

 public:
  explicit HuffmanTree(std::string str = "");
  void CreateEncodingTable();
  std::string getSimbolCode(char val);
  std::vector<std::string> Encode(std::string str);
  std::vector<int> CreateHistogram(std::string str);
  ~HuffmanTree();

 private:
  void CreateEncodingTable(HuffmanNode* node, std::string code,
     std::string direct);
  void SortQueue(std::vector<HuffmanNode*> *queue,
     const std::vector<int> & hist);
};

#endif  // MODULES_ALGORITHM_HUFFMANA_INCLUDE_ALGORITHM_HUFFMANA_H_
