// Copyright 2024 Smirnov Leonid

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class CaesarCipher {
private:
	int offset;

public:
	CaesarCipher(int _offset);
	std::string CaesarCipherEncoder(const std::string& plaintext);
	std::string CaesarCipherDecoder(const std::string& ciphertext);
};
