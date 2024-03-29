// Copyright 2024 Smirnov Leonid

#include "caesar_cipher.h"

CaesarCipher::CaesarCipher(int _offset)
{
	if (_offset < 1 || _offset > 25) {
		throw std::invalid_argument("Сдвиг должен быть в диапазоне от 1 до 25!");
	}
	this->offset = _offset;
}

std::string CaesarCipher::CaesarCipherEncoder(const std::string& plaintext)
{
	if (plaintext.empty()) {
		throw std::invalid_argument("Ошибка: Входная строка пустая!");
	}
	std::string result;

	for (char c : plaintext) {
		if (isalpha(c)) {
			if (isupper(c)) {
				result += static_cast<char>((c - 'A' + offset) % 26 + 'A');
			}
			else if(islower(c)) {
				result += static_cast<char>((c - 'a' + offset) % 26 + 'a');
			}
			else {
				result += c;
			}
		}
	}

	return result;
}

std::string CaesarCipher::CaesarCipherDecoder(const std::string& ciphertext)
{
	if (ciphertext.empty()) {
		throw std::invalid_argument("Ошибка: Входная строка пустая!");
	}
	std::string result;

	for (char c : ciphertext) {
		if (isalpha(c)) {
			if (isupper(c)) {
				result += static_cast<char>((c - 'A' - offset + 26) % 26 + 'A');
			}
			else if (islower(c)) {
				result += static_cast<char>((c - 'a' - offset + 26) % 26 + 'a');
			}
			else {
				result += c;
			}

		}
	}

	return result;
}
