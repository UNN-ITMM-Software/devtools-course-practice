// Copyright 2024 Soloninko Andrey

#pragma once

#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstring>

struct Node {
  char ch;
  int freq;
  Node *left, *right;
};

class Huffman {
 public:
    void buildHuffmanTree(const std::string& text);
    std::string encode(const std::string& text);
    std::string decode(const std::string& str);
    std::string decode(const std::string& str,
        const std::unordered_map<std::string, char>& codes);
    std::unordered_map<std::string, char> getHaffmanCodesStrChar();
    std::unordered_map<char, std::string> getHaffmanCodesCharStr();

 private:
    void _clearTree(std::priority_queue<Node*,
        std::vector<Node*>, bool (*)(Node*, Node*)>& pq);
    Node* _getNode(char ch, int freq, Node* left, Node* right);
    void _collectCodes(Node* root, std::string str);
    std::string _decode(Node* root, int& index, std::string str
        , std::string& dec_str);
    std::unordered_map<char, int> _collectFrequency(const std::string& text);
    void _buildHuffmanTree(const std::unordered_map<char, int>& freq);
    void _clear();

    std::priority_queue<Node*, std::vector<Node*>,
        bool (*)(Node*, Node*)> _pq;
    std::unordered_map<char, std::string> _huffmanCode;
};
