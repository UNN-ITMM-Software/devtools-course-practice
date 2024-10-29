// Copyright 2024 Ivanchenko Aleksei

#pragma once

#include <string>
#include <vector>

#include "DoubleLinkedList.h"

class DoubleLinkedListApp {
  DoubleLinkedList<std::string> list;
  std::vector<std::string> parse(int argc, const char** argv);
  void help(std::vector<std::string>& output);
  void reverse(std::vector<std::string>& output);
  void print(std::vector<std::string>& output);
  void push_back(std::vector<std::string>& output, std::string elem);
  void push_front(std::vector<std::string>& output, std::string elem);
  void insert(std::vector<std::string>& output, std::string elem, size_t index);
  void erase(std::vector<std::string>& output, size_t index);

 public:
  DoubleLinkedListApp() {
    list.push_back("never");
    list.push_back("gonna");
    list.push_back("give");
    list.push_back("you");
    list.push_back("up");
  }
  std::vector<std::string> runApp(int argc, const char** argv);
};
