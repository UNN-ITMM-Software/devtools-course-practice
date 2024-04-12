// Copyright 2024 Tushentsova Karina

#include "include/permut_generator.h"
#include <string>

PermutGenerator::PermutGenerator() {}

PermutGenerator::PermutGenerator(int size) {
	size_ = size;
}

PermutGenerator::PermutGenerator(int size, char value) {
	size_ = size;
	value_ = value;
}

int PermutGenerator::GetLength() {
	return size_;
}

std::string PermutGenerator::CreateArray() {
	std::string result = "";
	for (int i = 0; i < size_; i++) {
		result += value_;
	}
	return result;
}
