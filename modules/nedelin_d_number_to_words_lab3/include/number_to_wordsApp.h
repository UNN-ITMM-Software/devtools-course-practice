// Copyright 2024 Nedelin Dmitry

#ifndef MODULES_NEDELIN_DMITRY_NUMBER_TO_WORDS_INCLUDE_APPLICATION_H_
#define MODULES_NEDELIN_DMITRY_NUMBER_TO_WORDS_INCLUDE_APPLICATION_H_

#include <string>
#include <vector>

class Application{
public:
    std::vector<std::string> runApp(int argc, const char** argv);

private:
    std::string processNumber(const std::string& input);
};

#endif  // MODULES_NEDELIN_DMITRY_NUMBER_TO_WORDS_INCLUDE_APPLICATION_H_
