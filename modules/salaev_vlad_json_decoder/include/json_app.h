// Copyright 2024 Skotin Alexander

#ifndef MODULES_SALAEV_VLAD_JSON_DECODER_INCLUDE_JSON_APP_H_
#define MODULES_SALAEV_VLAD_JSON_DECODER_INCLUDE_JSON_APP_H_

#include <string>
#include "include/json_decoder.h"

class JsonApp {
 public:
    JsonApp() = default;
    void run(int argc, char** argv);
 private:
    void printJsonValue(const JsonValue& value, std::string indent = "");
};


#endif  // MODULES_SALAEV_VLAD_JSON_DECODER_INCLUDE_JSON_APP_H_
