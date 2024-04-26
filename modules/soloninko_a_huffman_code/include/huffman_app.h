// Copyright 2024 Lesnikov Nikita

#pragma once

#include <queue>
#include <iostream>


class Logger {
 public:
	explicit Logger(std::ostream* buffer) {
		if (buffer == nullptr)
		{
			throw std::invalid_argument("Pointer cannot be null");
		}
		_buffer = buffer;
	}

	template <class T, class ...Args>
	void log(T first, Args ...args) {
		*_buffer << first;
	}

	void log() {
		*_buffer << "\n";
	}

 private:
	std::ostream* _buffer = nullptr;
};

class HuffmanApp {
 public:
	
};