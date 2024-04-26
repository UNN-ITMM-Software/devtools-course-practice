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
	 HuffmanApp()
		: _logger(&std::cout) {}
	
	 void help()
	 {
		 _logger.log("	This is an application that allows you to \
			 find the optimal Huffman code for a given sequence \
			 of characters. This operation allows you to compress data.\n \
				For encoding, you must enter the data to be compressed in \
			 text format. The output will be a compressed string and \
			 a list of new character codes.");

	 }

 private:
	 Logger _logger;
};