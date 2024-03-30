// Copyright 2024 Kuznetsov Artem
#pragma once

#include <string>

#include "include/vigenere_cipher.h"

class VigenereApplication {
  enum class Option { ENCRYPT, DECRYPT };

  struct Arguments {
    std::string mKey{};
    std::string mStr{};
    Option mOption{};
  };

 private:
  std::string mMessage{};
  Arguments mArgs{};

 public:
  VigenereApplication() = default;
  std::string operator()(int argc, char* argv[]);

 private:
  bool validate(int argc, char* argv[]);
  void help(const char* appName, const char* msg = nullptr);
};
