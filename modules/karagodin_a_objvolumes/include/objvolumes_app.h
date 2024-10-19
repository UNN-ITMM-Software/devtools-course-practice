// Copyright 2024 Vinokurov Ivan

#ifndef MODULES_KARAGODIN_A_OBJVOLUMES_INCLUDE_OBJVOLUMES_APP_H_
#define MODULES_KARAGODIN_A_OBJVOLUMES_INCLUDE_OBJVOLUMES_APP_H_

#include <string>
#include <vector>

class ObjVolumeApp {
 public:
  ObjVolumeApp();

  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string message_;
  typedef struct {
    std::string objType;
    std::vector<double> arg;
  } Arguments;
};

#endif  // MODULES_KARAGODIN_A_OBJVOLUMES_INCLUDE_OBJVOLUMES_APP_H_
