// Copyright 2021 Kirillov Konstantin

#include <string>

#ifndef MODULES_GENERAL_SUBSEQ_INCLUDE_GENERALSUBSEQAPP_H_
#define MODULES_GENERAL_SUBSEQ_INCLUDE_GENERALSUBSEQAPP_H_
class GeneralSubseqApp {
 public:
    GeneralSubseqApp();

    std::string operator()(int argc, const char** argv);

 private:
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc,
      const char** argv);
     std::string message_;
};
#endif  // MODULES_GENERAL_SUBSEQ_INCLUDE_GENERALSUBSEQAPP_H_
