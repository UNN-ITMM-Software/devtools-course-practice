// Copyright 2024 Videneva Ekaterina
#pragma once
#include <vector>
#include <cinttypes>

class application_t {
 public:
    static void print_help();
    static std::vector<int64_t> parse(int argc, const char* const* argv);
    static int calc_and_print_result(std::vector<int64_t> num_to_calc);

    application_t() = default;

    int run(int argc, const char* const * argv);

    ~application_t() = default;
};
