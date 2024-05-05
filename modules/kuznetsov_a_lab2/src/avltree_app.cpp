// Copyright 2024 Nogin Denis

#include "include/avltree_app.h"

#include <cstring>
#include <sstream>

std::string AvlTreeApplication::operator()(int argc, char *argv[]) {
  if (validate(argc, argv)) {
    for (int i = 3; i < argc; ++i) {
      tree.insert(std::stoi(argv[i]));
      std::cout << argv[i] << " ";
    }

    std::stringstream ss;

    if (argument == Option::FIND) {
      if (tree.find(std::stoi(argv[2]))) {
        ss << "true";
      } else {
        ss << "false";
      }
    } else {
      if (argument == Option::REMOVE) {
        tree.remove(std::stoi(argv[2]));
      } else {
        tree.insert(std::stoi(argv[2]));
      }
      std::vector<int> treeVector = tree.getTreeAsVector();
      for (auto &elem : treeVector) {
        ss << elem << " ";
      }
    }
    hullMessage = ss.str();
  }

  return hullMessage;
}

bool AvlTreeApplication::validate(int argc, char *argv[]) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc == 2 && std::strcmp(argv[1], "--help") == 0) {
    help(argv[0]);
    return false;
  } else if (argc <= 3) {
    help(argv[0], "tree is empty");
    return false;
  } else if (argc > 3) {
    for (int i = 3; i < argc; ++i) {
      try {
        std::stoi(argv[i]);
      } catch (const std::invalid_argument &e) {
        help(argv[0], "invalid argument, arguments must be numbers");
        return false;
      } catch (const std::out_of_range &e) {
        help(argv[0], "argument out of range");
        return false;
      }
    }
  }

  if (std::strcmp(argv[1], "-i") == 0) {
    argument = Option::INSERT;
  } else if (std::strcmp(argv[1], "-r") == 0) {
    argument = Option::REMOVE;
  } else if (std::strcmp(argv[1], "-f") == 0) {
    argument = Option::FIND;
  } else {
    std::stringstream msgError;
    msgError << "unknown argument '" << argv[1] << "'\n";
    help(argv[0], msgError.str().c_str());
    return false;
  }

  return true;
}

void AvlTreeApplication::help(const char *appName, const char *msg) {
  std::stringstream message;

  if (msg)
    message << "Error: " << msg << '\n';

  message
      << "This is an application for demonstrating AVL Tree operations.\n\n";
  message << "Application\t" << appName
          << " [option] <value> <treeElem1> <treeElem2> ...\n";
  message << "Available options:\n";
  message << " -i (insert) <value>: Insert a value into the AVL Tree.\n";
  message << " -r (remove) <value>: Remove a value from the AVL Tree.\n";
  message << " -f (find) <value>: Check if a value exists in the AVL Tree.\n\n";
  message << "Run '" << appName << " --help' for more information.\n\n";

  hullMessage = message.str();
}
