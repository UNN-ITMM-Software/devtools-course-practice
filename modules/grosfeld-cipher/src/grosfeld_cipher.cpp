// Copyright 2021 Aleksandrychev Andrey

#include <vector>
#include <string>
#include <iostream>
#include "include/grosfeld_cipher.h"

int GronsfeldCipher::NOD(int n1, int n2)
{
	int res;
	if (n1 == n2) return n1;

	int dif = n1 - n2; 
	if (dif < 0) {
		dif = -dif;
		res = NOD(n1, dif);
	}
	else {
		res = NOD(n2, dif);
	}
	
	return res;
}

int GronsfeldCipher::GCD(std::vector<int> list)
{
	int GCD = list[0];

	for (int i = 1; i < list.size(); i++) {
		GCD = NOD(GCD, list[i]);
	}

	return GCD;
}

int GronsfeldCipher::fixOverflow(int curVal, int min, int max) {
	std::cout << curVal << ":" << min << ":" << max << std::endl;
	if (curVal < min) return max - (min - curVal);
	if (curVal > max) return min + (curVal - max);
	return curVal;
}

int GronsfeldCipher::KasiskeMethod(std::string sourceString) {
	if (sourceString.length() < 90) return -INT_MAX;
	
	int probValueStartIndex = 0;
	int probValueSize = 3;
	std::string probValue = sourceString.substr(probValueStartIndex, probValueStartIndex + probValueSize);
	
	int countProbValue = 1;

	int probValueNextIndex = 3;

	while (countProbValue < 3 && probValueStartIndex + probValueSize < sourceString.length() - 1) {
		int placeProbValue = sourceString.find(probValue, probValueNextIndex);
		if (placeProbValue == -1) {
			probValueStartIndex += 1;
			probValue = sourceString.substr(probValueStartIndex, probValueStartIndex + probValueSize);
			countProbValue = 1;
		}
		else {
			probValueNextIndex = placeProbValue;
			countProbValue += 1;
		}
	}

	if (probValueStartIndex + probValueSize >= sourceString.length() - 1) {
		return INT_MAX;
	}

	std::vector<int> deltas;
	probValueStartIndex = sourceString.find(probValue, 0);
	probValueNextIndex = sourceString.find(probValue, probValueStartIndex);
	while (probValueNextIndex >= 0) {
		deltas.push_back(probValueNextIndex - probValueStartIndex);
		probValueStartIndex = probValueNextIndex;
		probValueNextIndex = sourceString.find(probValue, probValueStartIndex);
	}

	return this->GCD(deltas);
}

GronsfeldCipher::GronsfeldCipher(const std::string sourceString_, const int key_) {
	this->sourceString = sourceString_;
	this->key = key_;
	this->keyString = std::to_string(key_);
	int lengthOfKey = this->keyString.length();
	for (int i = this->keyString.length(); i < this->sourceString.length(); i++) {
		this->keyString += this->keyString[i % lengthOfKey];
	}
}

std::string GronsfeldCipher::getSource() {
	return this->sourceString;
}

std::string GronsfeldCipher::getKeyString() {
	return this->keyString;
}

int GronsfeldCipher::getKey() {
	return this->key;
}

std::string GronsfeldCipher::getCipher() {
	if (this->cipherString == "") {
		std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

		for (int i = 0; i < this->keyString.length(); i++) {
			int curOffset = std::stoi(std::to_string(this->keyString[i]));
			int letterPlace = alphabet.find(this->keyString[i], 0);
			int newLetterIndex = this->fixOverflow(letterPlace + curOffset, 0, alphabet.length() - 1);

			this->cipherString += alphabet[newLetterIndex];
		}
	}

	return this->cipherString;
}

std::string GronsfeldCipher::decode(const std::string sourceString_, int sourceKey) {
	this->cipherString = sourceString_;
	this->key = sourceKey;
	this->keyString = std::to_string(sourceKey);
	int lengthOfKey = this->keyString.length();
	for (int i = this->keyString.length(); i < this->sourceString.length(); i++) {
		this->keyString += this->keyString[i % lengthOfKey];
	}

	std::cout << this->cipherString << std::endl;
	std::cout << this->keyString << std::endl;

	std::string trueString = "";

	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < this->cipherString.length(); i++) {
		int curOffset = std::stoi(std::to_string(this->keyString[i]));
		int letterPlace = alphabet.find(this->cipherString[i], 0);
		std::cout << i + 1 << ": " << trueString << std::endl;
		int trueLetterIndex = this->fixOverflow(letterPlace - curOffset, 0, alphabet.length() - 1);

		trueString += alphabet[trueLetterIndex];
	}

	this->sourceString = trueString;
	
	return trueString;
}

std::string GronsfeldCipher::hack(std::string cipherString)
{
	std::string trueString = "";

	int probkeyStringSize = this->KasiskeMethod(cipherString);
	if (probkeyStringSize == -INT_MAX) return "ERROR: So small string !!!";
	if (probkeyStringSize == INT_MAX) return "WARNING: Failed to decode.";


	
	return trueString;
}