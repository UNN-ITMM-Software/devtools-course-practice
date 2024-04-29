// Copyright 2024 Mukhin Ivan
#ifndef MODULES_MUKHIN_I_VECTORS_INCLUDE_VECTOR_CALCULATOR_H_
#define MODULES_MUKHIN_I_VECTORS_INCLUDE_VECTOR_CALCULATOR_H_

#include "include/vectors.h"
#include <string>

namespace mukhin_i {
class Vector3DApp {
 public:

    std::string args;
    Vector3D<double> v1;
    Vector3D<double> v2;
    std::string oper;

    Vector3DApp(int argc, const char** argv);

    std::string parse();
    void init_vectors(const std::string& res);
    void calculate();
};
}

#endif  // MODULES_MUKHIN_I_VECTORS_INCLUDE_VECTOR_CALCULATOR_H_