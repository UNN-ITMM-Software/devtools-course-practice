// Copyright 2024 Lesnikov Nikita

#pragma once

#include "huffman.h"

#include <queue>
#include <iostream>
#include <sstream>


class HuffmanApp {
 public:
	 std::string operator()(int argc, char** argv) {
		 const char* validateStr = _validate(argc, argv);
		 if (validateStr) {
			 return validateStr;
		 }

		 if (argc == 1) {
			 return _help(argv[0]);
		 }
		 else if (argc == 2) {
			 return encode(argc, argv);
		 }

		 return decode(argc, argv);
	 }

	 std::string encode(int argc, char** argv) {
		 std::string data = argv[1];
		 std::stringstream message;

		 Huffman huffman;

		 huffman.buildHuffmanTree(data);
		 std::string encoded = huffman.encode(data);
		 std::unordered_map<char, std::string> codes = huffman.getHaffmanCodesCharStr();

		 message << encoded << " ";

		 for (const auto& i : codes) {
			 message << i.first << " " << i.second << " ";
		 }

		 return message.str();
	 }

	 std::string decode(int argc, char** argv) {
		 Huffman huffman;

		 return huffman.decode(argv[1], _getCodes(argc, argv));
	 }

 private:
	 std::unordered_map<std::string, char> _getCodes(int argc, char** argv) {
		 std::unordered_map<std::string, char> codes;

		 for (int i = 2; i < argc - 1; i += 2)
		 {
			 codes[argv[i + 1]] = argv[i][0];
		 }

		 return codes;
	 }

	 char* _validate(int argc, char** argv) {
		 if (!_validateNumArgs(argc)) {
			 return "Incorrect number of arguments!";
		 }
		 if (argc > 2 && !_validateEncoded(argv[1])) {
			 return "Invalid string for decoding!";
		 }
		 if (!_validateCodes(argc, argv))
		 {
			 return "Invalid codes!";
		 }
		 return nullptr;
	 }

	 bool _validateNumArgs(int num) {
		 return num == 1 || num % 2 == 0;
	 }
	 bool _validateEncoded(const char* str) {
		 for (int i = 0; i < strlen(str); i++) {
			 if (str[i] != '1' && str[i] != '0')
			 {
				 return false;
			 }
		 }
		 return true;
	 }

	 bool _validateCodes(int argc, char** argv) {
		 for (int i = 2; i < argc - 1; i += 2)
		 {
			 if (strlen(argv[i]) > 1) {
				 return false;
			 }
			 if (!_validateEncoded(argv[i+1]))
			 {
				 return false;
			 }
		 }
		 return true;
	 }

	 std::string _help(const char* appName)
	 {
		 std::stringstream message;
		 message << "This is an application that allows you to \
find the optimal Huffman code for a given sequence \
of characters. This operation allows you to compress data.\n \
For encoding, you must enter the data to be compressed in \
text format.\n";
		 message << appName << " abc\n";
		 message << "The output will be a compressed string and \
a list of new character codes.\n \
To decode, you must enter a string and a list of \
character codes in the format:\n";
		message << appName << " 10101001 a 10101 b 110 ....";
		return message.str();
	 }
};