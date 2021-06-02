// Copyright 2021 Schekotilova Julia

#include <string>
#include <sstream>
#include <vector>

#include "include/algorithm_huffmana.h"
#include "include/algorithm_huffmana_app.h"

AlgorithmHuffmanaApp::AlgorithmHuffmanaApp() : message_("") {}

void AlgorithmHuffmanaApp::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This app encodes words using the Huffman algorithm.\n\n" +
    "Please enter words separated by spaces\n\n" +
    "  $ " + appname + " <word1> <word2> ... <wordN>\n\n";
}

bool AlgorithmHuffmanaApp::validateNumberOfArguments(int argc,
  const char** argv) {
  if (argc == 1) {
    help(argv[0], "ERROR: empty argument.\n\n");
    return false;
  }
  return true;
}

std::string AlgorithmHuffmanaApp::convert(std::vector<std::string>
  _part_of_result) {
  std::string _result = "";
  for (unsigned int j = 0; j < _part_of_result.size(); j++)
    _result = _result + _part_of_result[j];
  return _result;
}

std::string AlgorithmHuffmanaApp:: operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv))
    return message_;
  int number_arg = argc;
  std::vector<std::string> interim_result;
  std::string do_one_string = "";
  std::string result = "";
  for (int i = 1; i < number_arg; i++) {
    do_one_string = do_one_string + argv[i];
  }
  HuffmanTree Tree(do_one_string);
  Tree.CreateEncodingTable();
  interim_result = Tree.Encode(do_one_string);
  result = convert(interim_result);
  return result;
}
