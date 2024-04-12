// Copyright 2024 Tushentsova Karina

#ifndef MODULES_TUSHENTSOVA_K_PERMUT_GENERATOR_H_
#define MODULES_TUSHENTSOVA_K_PERMUT_GENERATOR_H_

#include <string>

class PermutGenerator {
public:
	PermutGenerator();
	PermutGenerator(int size);
	std::string PrintArray(int array[]);
	void CreateArray(int array[]);
	std::string GeneratorPermut(int array[]);


private:
	int size_;
	void swap(int* a, int i, int j);
	bool NextSet(int* array);
};

#endif  // MODULES_TUSHENTSOVA_K_PERMUT_GENERATOR_H_
