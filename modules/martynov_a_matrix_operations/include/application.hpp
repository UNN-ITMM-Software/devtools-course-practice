// Copyright 2024 Martynov Aleksandr

#ifndef MODULES_MARTYNOV_A_MATRIX_OPERATIONS_INCLUDE_APPLICATION_HPP_
#define MODULES_MARTYNOV_A_MATRIX_OPERATIONS_INCLUDE_APPLICATION_HPP_

#include <cstring>
#include <string>
#include <sstream>

class MatOpsApplication {
 public:
    MatOpsApplication() = default;
    ~MatOpsApplication() = default;
    std::string Parse(int argc, char *argv[]);

 private:
    std::string message_;
    void Help(const char* application, const char* message = nullptr);
    bool Validate(int argc, char *argv[]);
};

#endif  // MODULES_MARTYNOV_A_MATRIX_OPERATIONS_INCLUDE_APPLICATION_HPP_
