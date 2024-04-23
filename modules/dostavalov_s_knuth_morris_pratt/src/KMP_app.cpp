// Copyright 2024 Kudinov Nikita

#include "include/KMP_app.h"

#include <cstring>

bool KMPApplication::validate(int argc, char* argv[]) {
  if (argc <= 2) {
    this->help(argv[0]);
    return false;
  }

  if (std::strcmp(argv[1], "-h") == 0) {
    this->help(argv[0]);
    return false;
  }

  if (std::strcmp(argv[1], "--help") == 0) {
    this->help(argv[0]);
    return false;
  }

  return true;
}

void KMPApplication::help(const char* appName) {
  this->outputMessage = "Usage: "
    + std::string(appName)
    + " <TEXT> <PATTERN>\n";
}

std::string KMPApplication::operator()(int argc, char* argv[]) {
  this->outputMessage = "";

  if (validate(argc, argv)) {
    auto text = std::string(argv[1]);
    auto pattern = std::string(argv[2]);
    std::vector<int> patternIndexes = KnuthMorrisPratt::findPattern(
      text,
      pattern);

    for (const auto& patternIndex : patternIndexes) {
      this->outputMessage += text + "\n";
      this->outputMessage += std::string(patternIndex, ' ')
        + std::string(pattern.size(), '^') + "\n";
    }
  }

  return this->outputMessage;
}
