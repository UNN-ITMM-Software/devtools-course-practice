// Copyright 2021 Ostapovich Denis

#ifndef MODULES_JSON_DESERIALIZER_INCLUDE_APPLICATION_H_
#define MODULES_JSON_DESERIALIZER_INCLUDE_APPLICATION_H_

#include <string>

namespace jsonDeserializer {

enum class OperationMode { Array, Object };

class Application {
 public:
  Application();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string helpMessage;
  typedef struct {
    std::string jsonString;
    std::string field;
  } Arguments;
};
}  // namespace jsonDeserializer

#endif  // MODULES_JSON_DESERIALIZER_INCLUDE_APPLICATION_H_
