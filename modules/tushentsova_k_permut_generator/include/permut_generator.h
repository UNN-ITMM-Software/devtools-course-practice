// Copyright 2024 Tushentsova Karina

#ifndef MODULES_TUSHENTSOVA_K_PERMUT_GENERATOR_H_
#define MODULES_TUSHENTSOVA_K_PERMUT_GENERATOR_H_

#include <string>

class PermutGenerator {
public:
	PermutGenerator();
	PermutGenerator(int size);
	PermutGenerator(int size, char value);
	int GetLength();
	std::string CreateArray();

private:
	int size_;
	char value_;
};

#endif  // MODULES_TUSHENTSOVA_K_PERMUT_GENERATOR_H_
