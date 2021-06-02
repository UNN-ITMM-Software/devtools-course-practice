// Copyright 2021 Lukyanchenko Ivan

#include <string>

#ifndef MODULES_LARGEST_SUBSEQ_INCLUDE_LARGEST_SUBSEQ_APP_H_
#define MODULES_LARGEST_SUBSEQ_INCLUDE_LARGEST_SUBSEQ_APP_H_
class Lar_SubseqApp {
 public:
    Lar_SubseqApp();

    std::string operator()(int argc, const char** argv);

 private:
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     std::string message_;
};
#endif  // MODULES_LARGEST_SUBSEQ_INCLUDE_LARGEST_SUBSEQ_APP_H_
