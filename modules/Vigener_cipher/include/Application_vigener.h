// Copyright 2021 Chernyh Daria

#ifndef MODULES_VIGENER_CIPHER_INCLUDE_APPLICATION_VIGENER_H_
#define MODULES_VIGENER_CIPHER_INCLUDE_APPLICATION_VIGENER_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::string key;
        std::string str_input;
        char operation;
    } Arguments;
};

#endif  // MODULES_VIGENER_CIPHER_INCLUDE_APPLICATION_VIGENER_H_
