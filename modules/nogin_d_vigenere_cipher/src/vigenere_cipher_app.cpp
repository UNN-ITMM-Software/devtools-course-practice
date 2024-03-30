// Copyright 2024 Kuznetsov Artem

#include "include/vigenere_cipher_app.h"

#include <cstring>
#include <sstream>

std::string VigenereApplication::operator()(int argc, char* argv[]) {
  if (validate(argc, argv)) {
    if (mArgs.mOption == Option::ENCRYPT) {
      mMessage = vigenereCipher(mArgs.mStr, mArgs.mKey);
    } else {
      mMessage = vigenereDecipher(mArgs.mStr, mArgs.mKey);
    }

    if (mMessage.empty()) {
      help(argv[0], "invalid key");
    }
  }
  return mMessage;
}

bool VigenereApplication::validate(int argc, char* argv[]) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc == 2 && std::strcmp(argv[1], "--help") == 0) {
    help(argv[0]);
    return false;
  } else if (argc != 4) {
    help(argv[0], "incorrect number of arguments");
    return false;
  }

  for (int i = 1; i < argc; ++i) {
    if (std::strcmp(argv[i], "--help") == 0) {
      help(argv[0]);
      return false;
    }
  }

  if (std::strcmp(argv[1], "-e") == 0) {
    mArgs.mOption = Option::ENCRYPT;
  } else if (std::strcmp(argv[1], "-d") == 0) {
    mArgs.mOption = Option::DECRYPT;
  } else {
    std::stringstream msgError;
    msgError << "unknown argument '" << argv[1] << "'\n";
    help(argv[0], msgError.str().c_str());
    return false;
  }

  mArgs.mKey = argv[2];
  mArgs.mStr = argv[3];

  return true;
}

void VigenereApplication::help(const char* appName, const char* msg) {
  std::stringstream message;

  if (msg) message << "Error: " << msg << '\n';

  message << "Usage:\n";
  message << '\t' << appName << " [option] <key> <message>\n";
  message << "Options:\n";
  message << '\t' << "-e\t\t"
          << " = encryption will be performed\n";
  message << '\t' << "-d\t\t"
          << " = decryption will be performed\n";
  message << "\nRun '" << appName << " --help' for more information.\n";

  mMessage = message.str();
}
