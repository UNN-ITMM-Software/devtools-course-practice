// Copyright 2024 Soloninko Andrey

#include "include/huffman.h"

void Huffman::buildHuffmanTree(const std::string& text) {
    _clear();

    std::unordered_map<char, int> freq = _collectFrequency(text);

    _pq = std::priority_queue<Node*, std::vector<Node*>,
        bool (*)(Node*, Node*)>(
            [](Node* l, Node* r) { return l->freq > r->freq; });

    _buildHuffmanTree(freq);

    _collectCodes(_pq.top(), "");
}

std::string Huffman::encode(const std::string& text) {
    std::string str = "";
    for (const char& ch : text) {
        str += _huffmanCode[ch];
    }

    return str;
}

std::string Huffman::decode(const std::string& str) {
    std::string dec_str;

    int index = -1;
    while (index < static_cast<int>(str.size()) - 1) {
        dec_str = _decode(_pq.top(), index, str, dec_str);
    }

    return dec_str;
}

std::string Huffman::decode(const std::string& str,
    const std::unordered_map<std::string, char>& codes) {
    int prev = 0;

    std::string decoded;

    for (int i = 0; i < static_cast<int>(str.size()); i++) {
        std::string cur = str.substr(prev, i - prev + 1);

        auto it = codes.find(cur);
        if (it != codes.end()) {
            decoded += (*it).second;
            prev = i + 1;
        }
    }

    return decoded;
}

std::unordered_map<std::string, char> Huffman::
getHaffmanCodesStrChar() {
    std::unordered_map<std::string, char> huffmanCode;

    for (const auto& i : _huffmanCode) {
        huffmanCode[i.second] = i.first;
    }

    return huffmanCode;
}

std::unordered_map<char, std::string> Huffman::
getHaffmanCodesCharStr() {
    return _huffmanCode;
}


void Huffman::_clearTree(std::priority_queue<Node*,
    std::vector<Node*>, bool (*)(Node*, Node*)>& pq) {
    while (!pq.empty()) {
        Node* cur = pq.top();
        pq.pop();
        delete cur;
    }
}

Node* Huffman::_getNode(char ch, int freq, Node* left,
    Node* right) {
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

void Huffman::_collectCodes(Node* root, std::string str) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        _huffmanCode[root->ch] = str;
    }

    _collectCodes(root->left, str + "0");
    _collectCodes(root->right, str + "1");
}

std::string Huffman::_decode(Node* root, int& index, std::string str
    , std::string& dec_str) {
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

std::unordered_map<char, int> Huffman::
_collectFrequency(const std::string& text) {
    std::unordered_map<char, int> freq;

    for (const char& ch : text)
        freq[ch]++;

    return freq;
}

void Huffman::_buildHuffmanTree(
    const std::unordered_map<char, int>& freq) {
    for (const auto& pair : freq)
        _pq.push(_getNode(pair.first, pair.second,
            nullptr, nullptr));

    while (_pq.size() != 1) {
        Node* left = _pq.top();
        _pq.pop();
        Node* right = _pq.top();
        _pq.pop();
        int sum = left->freq + right->freq;
        _pq.push(_getNode('\0', sum, left, right));
    }
}

void Huffman::_clear() {
    _clearTree(_pq);
    _huffmanCode.clear();
}
