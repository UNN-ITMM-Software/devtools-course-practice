// Copyright 2024 Mukhin Ivan
#include "include/vector_calculator.h"
#include <exception>
#include <vector>
#include <cstdint>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include "include/vectors.h"

mukhin_i::Vector3DApp::Vector3DApp(int argc, const char** argv) {
    for (int i = 1; i < argc; i++) {
        args.append(argv[i]);
    }
}

std::string mukhin_i::Vector3DApp::parse() {
    std::stack<char> st;
    std::vector<double> numbers;
    std::string tmp;
    for (uint64_t i = 0; i < args.size(); i++) {
        if (args[i] == '{') {
            st.push('}');
        } else if (args[i] == '}') {
            if (st.empty()) {
                st.push('}');
                res += ' ';
            } else {
                st.pop();
                res += ' ';
            }
        } else if (args[i] == '+' ||
                   args[i] == '-' ||
                   args[i] == 'm' ||
                   args[i] == 'n' ||
                   args[i] == '@') {
            oper = args[i];
        } else {
            res += args[i];
        }
    }
    if (!st.empty()) {
        throw std::invalid_argument("Wrong place of {}"
                                    "in command line arguments.");
    }
    return res;
}

void mukhin_i::Vector3DApp::init_vectors() {
    std::stack<char> st;
    std::vector<double> numbers;
    std::string tmp;
    for (uint64_t i = 0; i < res.size(); i++) {
        if (res[i] == ',' || res[i] == ' ') {
            try {
                numbers.push_back(std::stod(tmp));
                tmp.clear();
            } catch(const std::exception &e) {
                throw e;
            }
        } else {
            tmp += res[i];
        }
    }
    if (numbers.size() == 6) {
        v1 = Vector3D<double>({numbers[0], numbers[1], numbers[2]});
        v2 = Vector3D<double>({numbers[3], numbers[4], numbers[5]});
    } else if (numbers.size() == 3) {
        v1 = Vector3D<double>({numbers[0], numbers[1], numbers[2]});
    } else {
        throw std::invalid_argument("Too many numbers.");
    }
}

void mukhin_i::Vector3DApp::calculate() {
    if (oper == "+") {
        std::cout << "Result is: " << v1 + v2 << std::endl;
    } else if (oper == "-") {
        std::cout << "Result is: " << v1 - v2 << std::endl;
    } else if (oper == "m") {
        std::cout << "Result is: " << v1 * v2 << std::endl;
    } else if (oper == "n") {
        std::cout << "Result is: " << v1.norm() << std::endl;
    } else if (oper == "@") {
        std::cout << "Result is: " << dot(v1, v2) << std::endl;
    } else {
        throw std::invalid_argument("Invalid operation.");
    }
}
