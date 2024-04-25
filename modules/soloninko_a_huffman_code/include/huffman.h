// Copyright 2024 Soloninko Andrey

#ifndef MODULES_SOLONINKO_A_HUFFMAN_CODE_INCLUDE_HUFFMAN_H_
#define MODULES_SOLONINKO_A_HUFFMAN_CODE_INCLUDE_HUFFMAN_H_

#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

struct Node {
  char ch;
  int freq;
  Node *left, *right;
};

Node *getNode(char ch, int freq, Node *left, Node *right) {
  Node *node = new Node();

  node->ch = ch;
  node->freq = freq;
  node->left = left;
  node->right = right;

  return node;
}
void encode(Node *root, std::string str,
            std::unordered_map<char, std::string> &huffmanCode) {
  if (root == nullptr)
    return;

  if (!root->left && !root->right) {
    huffmanCode[root->ch] = str;
  }

  encode(root->left, str + "0", huffmanCode);
  encode(root->right, str + "1", huffmanCode);
}

std::string decode(Node *root, int &index, std::string str,
                   std::string &dec_str) {
  if (root == nullptr) {
    return dec_str;
  }

  if (!root->left && !root->right) {
    dec_str += root->ch;
    return dec_str;
  }

  index++;

  if (str[index] == '0')
    decode(root->left, index, str, dec_str);
  else
    decode(root->right, index, str, dec_str);

  return dec_str;
}

void buildHuffmanTree(std::string text, std::string &dec_str) {
  std::unordered_map<char, int> freq;
  for (const char &ch : text) {
    freq[ch]++;
  }

  std::priority_queue<Node *, std::vector<Node *>, bool (*)(Node *, Node *)> pq(
      [](Node *l, Node *r) { return l->freq > r->freq; });

  for (const auto &pair : freq) {
    pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
  }

  while (pq.size() != 1) {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();

    int sum = left->freq + right->freq;
    pq.push(getNode('\0', sum, left, right));
  }

  Node *root = pq.top();

  std::unordered_map<char, std::string> huffmanCode;
  encode(root, "", huffmanCode);

  std::string str = "";
  for (const char &ch : text) {
    str += huffmanCode[ch];
  }

  int index = -1;
  while (index < static_cast<int>(str.size()) - 1) {
    dec_str = decode(root, index, str, dec_str);
  }

  while (!pq.empty()) {
    Node *t = pq.top();
    pq.pop();
    delete t;
  }
}

bool compare_str(std::string str1, std::string str2) {
  return str1.compare(str2) == 0;
}

#endif  // MODULES_SOLONINKO_A_HUFFMAN_CODE_INCLUDE_HUFFMAN_H_
