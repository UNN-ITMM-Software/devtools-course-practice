// Copyright 2024 Yurin Andrey

#include "include/GronsfeldCipherApp.h"

#include <sstream>

bool GronsfeldCipherApp::Validate(int argc, char **argv) {
  if (argc != requiredArgc) {
    Help(argv[0]);
    return false;
  }

  if (std::find(commands.begin(), commands.end(), std::string(argv[2])) ==
      commands.end()) {
    Help(argv[0]);
    return false;
  }

  if (std::strcmp(argv[2], "c") != 0) {
    for (const char *p = argv[1]; *p != '\0'; ++p) {
      if (!std::isalpha(*p)) {
        Help(argv[0]);
        return false;
      }
    }
  } else {
    for (const char *p = argv[1]; *p != '\0'; ++p) {
      if (!std::isdigit(*p)) {
        Help(argv[0]);
        return false;
      }
    }
  }

  return true;
}

void GronsfeldCipherApp::Help(const char *application) {
  std::ostringstream helpMessage;
  helpMessage << "Usage: " << application << " <charset> <mode> <string>"
              << std::endl;
  helpMessage << "Arguments:" << std::endl;
  helpMessage << "  <charset>   - The set of characters to use for the cipher."
              << std::endl;
  helpMessage << "  <mode>      - The mode of operation, one of: e, d, c."
              << std::endl;
  helpMessage << "  <string>    - The string to encrypt or decrypt."
              << std::endl;
  helpMessage << std::endl;
  helpMessage << "Example: " << application
              << " abcdefghijklmnopqrstuvwxyz encrypt helloworld" << std::endl;

  _msg = helpMessage.str();
}

std::string GronsfeldCipherApp::GronsfeldCipherCryptography(int argc,
                                                            char **argv) {
  if (!Validate(argc, argv)) {
    return _msg;
  }

  std::string key = argv[1];
  std::string mode = argv[2];
  std::string text = argv[3];

  if (mode == commands[0]) {
    cipher.setKey(key);
    return cipher.encoder(text);
  } else if (mode == commands[1]) {
    cipher.setKey(key);
    return cipher.decoder(text);
  } else {
    return cipher.getCrackKey(text, std::stoi(key));
  }
}
