// Copyright 2024 Salaev Vladislav

#ifndef MODULES_SKOTIN_A_HASHMAP_INCLUDE_HASHMAP_APP_H_
#define MODULES_SKOTIN_A_HASHMAP_INCLUDE_HASHMAP_APP_H_

#include <iostream>
#include <string>

#include "include/hashmap.h"

class Application {
 public:
  void run(int argc, char** argv);

 private:
  HashMap<std::string, std::string> hashMap;
  std::string processCommand(const std::string& command, const std::string& key,
                             const std::string& value);
  void logMessage(const std::string& message);
  std::string help() const;
};

#endif  // MODULES_SKOTIN_A_HASHMAP_INCLUDE_HASHMAP_APP_H_
