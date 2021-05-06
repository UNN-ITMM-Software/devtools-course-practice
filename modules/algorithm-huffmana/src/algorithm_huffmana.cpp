// Copyright 2021 Ludina Daria

#include <string>
#include <vector>
#include <stack>

#include "include/algorithm_huffmana.h"

HuffmanTree::HuffmanTree(std::string str) {
  std::vector<int> hist = CreateHistogram(str);
  std::vector<HuffmanNode*> queue(256);
  for (int i = 0; i < 256; i++) {
    queue[i] = new HuffmanNode();
    queue[i]->value = i;
    queue[i]->freq = hist[i];
  }
  SortQueue(&queue, hist);
  while (queue.size() > 2) {
    HuffmanNode* node = new HuffmanNode();
    node->value = -1;
    node->right = queue.back();
    queue.pop_back();
    node->left = queue.back();
    queue.pop_back();
    node->freq = node->left->freq + node->right->freq;
    auto i = queue.begin();
    while (((*i)->freq > node->freq) && (i != queue.end() - 1))
      i++;
    queue.insert(i, node);
  }
    root = new HuffmanNode();
    root->value = -1;
    root->right = queue.back();
    queue.pop_back();
    root->left = queue.back();
    queue.pop_back();
    root->freq = root->left->freq + root->right->freq;
}

void HuffmanTree::SortQueue(std::vector<HuffmanNode*>* queue,
  const std::vector<int> & hist) {
  for (int j = 0; j < 255; j++) {
    int f = 0;
    for (int i = 0; i < 255 - j; i++) {
      if (hist[(*queue)[i]->value] < hist[(*queue)[i + 1]->value]) {
        HuffmanNode* buff = (*queue)[i];
        (*queue)[i] = (*queue)[i + 1];
        (*queue)[i + 1] = buff;
        f = 1;
      }
    }
    if (f == 0)
      break;
  }
}

std::vector <std::string> HuffmanTree::Encode(std::string str) {
  std::vector <std::string> rez;
  for (unsigned int i = 0; i < str.size(); i++) {
    rez.push_back(encodingTable[str[i]]);
  }
  return rez;
}

std::vector<int> HuffmanTree::CreateHistogram(std::string str) {
  std::vector<int> hisogram(256);

  for (std::string::iterator it = str.begin();
    it != str.end(); ++it) {
    hisogram[*it]++;
  }
  return hisogram;
}

std::string HuffmanTree::getSimbolCode(char value) {
  return encodingTable[value];
}

void HuffmanTree::CreateEncodingTable() {
  for (int i = 0; i < 256; i++) encodingTable.push_back("");
  CreateEncodingTable(root->left, "", "0");
  CreateEncodingTable(root->right, "", "1");
}

void HuffmanTree::CreateEncodingTable(HuffmanNode* node,
  std::string code, std::string direct) {
  if ((node->left) || (node->right)) {
    CreateEncodingTable(node->left, code + direct, std::string("0"));
    CreateEncodingTable(node->right, code + direct, std::string("1"));
  } else {
    encodingTable[node->value] = code + direct;
  }
}

HuffmanTree::~HuffmanTree() {
  std::stack<HuffmanNode*> st;
  st.push(root);
  while (!st.empty()) {
    HuffmanNode* curr = st.top();
    st.pop();
    if (curr) {
      if (curr->left)
        st.push(curr->left);
      if (curr->right)
        st.push(curr->right);
    }
    delete curr;
  }
}
