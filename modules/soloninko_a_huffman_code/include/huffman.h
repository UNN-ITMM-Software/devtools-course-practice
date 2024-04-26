// Copyright 2024 Soloninko Andrey

#pragma once

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

class Huffman {
public:
    void buildHuffmanTree(const std::string& text) {
        _clear();

        std::unordered_map<char, int> freq = _collectFrequency(text);

        _pq = std::priority_queue<Node*, std::vector<Node*>, bool (*)(Node*, Node*)>(
            [](Node* l, Node* r) { return l->freq > r->freq; });

        _buildHuffmanTree(freq);

        _collectCodes(_pq.top(), "");
    }

    std::string encode(const std::string& text)
    {
        std::string str = "";
        for (const char& ch : text) {
            str += _huffmanCode[ch];
        }

        return str;
    }

    std::string decode(const std::string& str)
    {
        std::string dec_str;

        int index = -1;
        while (index < static_cast<int>(str.size()) - 1) {
            dec_str = _decode(_pq.top(), index, str, dec_str);
        }

        return dec_str;
    }

private:
    void _clearTree(std::priority_queue<Node*, std::vector<Node*>, bool (*)(Node*, Node*)>& pq)
    {
        while (!pq.empty()) {
            Node* cur = pq.top();
            pq.pop();
            delete cur;
        }
    }

    Node* _getNode(char ch, int freq, Node* left, Node* right) {
        Node* node = new Node();

        node->ch = ch;
        node->freq = freq;
        node->left = left;
        node->right = right;

        return node;
    }

    void _collectCodes(Node* root, std::string str) {
        if (root == nullptr)
            return;

        if (!root->left && !root->right) {
            _huffmanCode[root->ch] = str;
        }

        _collectCodes(root->left, str + "0");
        _collectCodes(root->right, str + "1");
    }

    std::string _decode(Node* root, int& index, std::string str
        , std::string& dec_str) {
        if (root == nullptr) 
            return dec_str;

        if (!root->left && !root->right) {
            dec_str += root->ch;
            return dec_str;
        }

        index++;

        if (str[index] == '0')
            _decode(root->left, index, str, dec_str);
        else
            _decode(root->right, index, str, dec_str);

        return dec_str;
    }

    std::unordered_map<char, int> _collectFrequency(const std::string& text)
    {
        std::unordered_map<char, int> freq;

        for (const char& ch : text)
            freq[ch]++;

        return freq;
    }

    void _buildHuffmanTree(const std::unordered_map<char, int>& freq) {
        for (const auto& pair : freq) 
            _pq.push(_getNode(pair.first, pair.second, nullptr, nullptr));

        while (_pq.size() != 1) {
            Node* left = _pq.top();
            _pq.pop();
            Node* right = _pq.top();
            _pq.pop();
            int sum = left->freq + right->freq;
            _pq.push(_getNode('\0', sum, left, right));
        }
    }

    void _clear() {
        _clearTree(_pq);
        _huffmanCode.clear();
    }

    std::priority_queue<Node*, std::vector<Node*>, bool (*)(Node*, Node*)> _pq;
    std::unordered_map<char, std::string> _huffmanCode;
};