// Copyright 2024 Mukhin Ivan
#include "include/vector_calculator.h"

int main(int argc, const char** argv) {
    mukhin_i::Vector3DApp app(argc, argv);
    app.init_vectors();
    app.calculate();
    return 0;
}
