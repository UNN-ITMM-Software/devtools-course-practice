// Copyright 2024 Soloninko Andrey

#ifndef MODULES_SOLONINKO_A_HUFFMAN_CODE_INCLUDE_HUFFMAN_H_
#define MODULES_SOLONINKO_A_HUFFMAN_CODE_INCLUDE_HUFFMAN_H_

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

std::string dec_str("");

struct Node
{
	char ch;
	int freq;
	Node* left, * right;
};

Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

struct comp
{
	bool operator()(Node* l, Node* r)
	{
		return l->freq > r->freq;
	}
};

void encode(Node* root, std::string str,
	std::unordered_map<char, std::string>& huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

void decode(Node* root, int& index, std::string str)
{
	if (root == nullptr) {
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		dec_str += root->ch;
		return;
	}

	index++;

	if (str[index] == '0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

// Builds Huffman Tree and decode given input text
void buildHuffmanTree(std::string text)
{
	std::unordered_map<char, int> freq;
	for (char ch : text) {
		freq[ch]++;
	}

	std::priority_queue<Node*, std::vector<Node*>, comp> pq;

	for (auto pair : freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	while (pq.size() != 1)
	{
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top();	pq.pop();

		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	Node* root = pq.top();

	std::unordered_map<char, std::string> huffmanCode;
	encode(root, "", huffmanCode);

	std::cout << "Huffman Codes are :\n" << '\n';
	for (auto pair : huffmanCode) {
		std::cout << pair.first << " " << pair.second << '\n';
	}

	std::cout << "\nOriginal string was :\n" << text << '\n';

	std::string str = "";
	for (char ch : text) {
		str += huffmanCode[ch];
	}

	std::cout << "\nEncoded string is :\n" << str << '\n';

	int index = -1;
	std::cout << "\nDecoded string is: \n";
	while (index < (int)str.size() - 1) {
		decode(root, index, str);
	}
    std::cout << dec_str;
}

bool compare_str(std::string str1, std::string str2) {
    if(str1.compare(str2) == 0) {
        return true;
    } else {
        return false;
    }
}

#endif  // MODULES_SOLONINKO_A_HUFFMAN_CODE_INCLUDE_HUFFMAN_H_
