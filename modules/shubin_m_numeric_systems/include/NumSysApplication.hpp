// Copyright 2024 Martynov Aleksandr

#ifndef MODULES_SHUBIN_M_NUMERIC_SYSTEMS_INCLUDE_NUMSYSAPPLICATION_HPP_
#define MODULES_SHUBIN_M_NUMERIC_SYSTEMS_INCLUDE_NUMSYSAPPLICATION_HPP_
#include <cstring>
#include <string>
#include <sstream>

class NumSysApplication {
 public:
    NumSysApplication() = default;
    ~NumSysApplication() = default;
    std::string Parse(int argc, char *argv[]);

 private:
    std::string message_;
    void Help(const char* application, const char* message = nullptr);
    bool Validate(int argc, char *argv[]);
};

#endif  // MODULES_SHUBIN_M_NUMERIC_SYSTEMS_INCLUDE_NUMSYSAPPLICATION_HPP_
