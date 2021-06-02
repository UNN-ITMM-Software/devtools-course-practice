// Copyright 2021 Kudriavtsev Alexandr

#ifndef MODULES_EULER_FUNC_INCLUDE_EULER_APPLICATION_H_
#define MODULES_EULER_FUNC_INCLUDE_EULER_APPLICATION_H_

#include <string>

class EulerApplication {
 public:
    std::string operator()(int argc, const char** argv) const;

 private:
    std::string getHelp(const std::string& filename) const;
};

#endif  // MODULES_EULER_FUNC_INCLUDE_EULER_APPLICATION_H_
