// Copyright 2024 Yurin Andrey

#ifndef MODULES_KASHIN_S_LAB2_INCLUDE_GRONSFELDCIPHERAPP_H_
#define MODULES_KASHIN_S_LAB2_INCLUDE_GRONSFELDCIPHERAPP_H_

#include <string>
#include <vector>

#include "GronsfeldCipher.h"

class GronsfeldCipherApp {
 private:
  const int requiredArgc{4};
  const std::vector<std::string> commands{"d", "e", "c"};
  GronsfeldCipher cipher = GronsfeldCipher();

  std::string _msg;

  bool Validate(int argc, char* argv[]);
  void Help(const char* application);

 public:
  std::string GronsfeldCipherCryptography(int argc, char* argv[]);
};

#endif  // MODULES_KASHIN_S_LAB2_INCLUDE_GRONSFELDCIPHERAPP_H_
