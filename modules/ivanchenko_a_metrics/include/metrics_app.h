// Copyright 2024 Derun Andrey

#ifndef MODULES_IVANCHENKO_A_METRICS_INCLUDE_METRICS_APP_H_
#define MODULES_IVANCHENKO_A_METRICS_INCLUDE_METRICS_APP_H_

#include <string>
#include <vector>

class MetricsApp {
 public:
  MetricsApp();

  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string message_;
  typedef struct {
    std::vector<float> v1;
    std::vector<float> v2;
    std::string op;
  } Arguments;
};

#endif  // MODULES_IVANCHENKO_A_METRICS_INCLUDE_METRICS_APP_H_
