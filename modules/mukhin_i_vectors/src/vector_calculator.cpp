#include "include/vector_calculator.h"
#include "include/vectors.h"
#include <vector>
#include <cstdint>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

mukhin_i::Vector3DApp::Vector3DApp(int argc, const char** argv) {
    for (int i = 1; i < argc; i++) {
        args.append(argv[i]);
    }
    std::string res = parse();
    init_vectors(res);
    calculate();
}

std::string mukhin_i::Vector3DApp::parse() {
    std::stack<char> st;
    std::vector<double> numbers;
    std::string res;
    std::string tmp;
    for (uint64_t i = 0; i < args.size(); i++) {
        if (args[i] == '{') {
            st.push('}');
        }
        else if (args[i] == '}') {
            st.pop();
            res += ' ';
        }
        else if (args[i] == '+' ||
                 args[i] == '-' ||
                 args[i] == 'm' ||
                 args[i] == 'n' ||
                 args[i] == '@') {
            oper = args[i];
        }
        else {
            res += args[i];
        }
    }
    if (!st.empty()) {
        throw std::invalid_argument("Wrong place of {} in command line arguments.");
    }
    return res;
}

void mukhin_i::Vector3DApp::init_vectors(const std::string& res) {
    std::stack<char> st;
    std::vector<double> numbers;
    std::string tmp;
    for (uint64_t i = 0; i < res.size(); i++) {
        if (res[i] == ',' || res[i] == ' ') {
            try {
                numbers.push_back(std::stod(tmp));
                tmp.clear();
            } catch(std::invalid_argument &e) {
                throw std::invalid_argument("Can't convert to double.");
            }
        }
        else {
            tmp += res[i];
        }
    }
    if (numbers.size() == 6) {
        v1 = Vector3D<double>({numbers[0], numbers[1], numbers[2]});
        v2 = Vector3D<double>({numbers[3], numbers[4], numbers[5]});
    }
    else if(numbers.size() == 3) {
        v1 = Vector3D<double>({numbers[0], numbers[1], numbers[2]});
    }
    else {
        throw std::invalid_argument("Too many numbers.");
    }
}

void mukhin_i::Vector3DApp::calculate() {
    if (oper == "+") {
        std::cout << "Result is: " << v1 + v2 << std::endl;
    }
    else if (oper == "-") {
        std::cout << "Result is: " << v1 - v2 << std::endl;
    }
    else if (oper == "m") {
        std::cout << "Result is: " << v1 * v2 << std::endl;
    }
    else if (oper == "n") {
        std::cout << "Result is: " << v1.norm() << std::endl;
    }
    else if (oper == "@") {
        std::cout << "Result is: " << dot(v1, v2) << std::endl;
    }
}
