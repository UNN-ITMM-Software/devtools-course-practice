// Copyright 2024 Videneva Ekaterina
#include "include/euler_function_app.hpp"
#include "include/euler_function.h"
#include <iostream>
#include <vector>
#include <string>
#include <cinttypes>
#include <cstdlib>
#include <sstream>
#include <cassert>

void application_t::print_help() {
    std::cout << "-------------- Euler function application ---------------\n";
    std::cout << "This application is used for calculate euler function " <<
    "from number that passed through command line\n";
    std::cout << "Input argument must be in the following form:\n";
    std::cout<< "app [number_1] [number_2] [number_3] ... \n";
    std::cout<< "If no number is specified, this message will be print\n";
}

std::vector<int64_t> application_t::parse(int argc, const char* const* argv) {
    assert(argc > 1);
    std::vector<int64_t> result(argc - 1);
    int64_t tmp_res;

    for (int i = 1; i < argc; i++) {
        tmp_res = std::atol(argv[i]);
        if (tmp_res == 0 && argv[i] != std::string("0")) {
            std::stringstream err_message;
            err_message << "Not a number in " << i << " argument\n";
            throw std::runtime_error(err_message.str());
        }

        result[i - 1] = tmp_res;
    }

    return result;
}

int application_t::calc_and_print_result(std::vector<int64_t> num_to_calc) {
    std::cout << "Let euler function(num) = phi(num)\n";
    std::cout << "Printing result: \n";
    int64_t tmp_res = 0;

    try {
        for (size_t i = 0; i < num_to_calc.size(); i++) {
            tmp_res = euler_function(num_to_calc[i]);
            std::cout << "phi(" << num_to_calc[i] << ") = " << tmp_res << '\n';
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}

int application_t::run(int argc, const char* const* argv) {
    if (argc < 2) {
        print_help();
        return 0;
    }

    std::vector<int64_t> num_to_calc = parse(argc, argv);


    return calc_and_print_result(num_to_calc);
}
