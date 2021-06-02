// Copyright 2021 Kudriavtsev Alexandr

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/Euler.h"
#include "include/euler_application.h"

std::string EulerApplication::getHelp(const std::string& filename) const {
    return "This is an application that calculates Euler function " \
        "for given arguments. \n\n" \
        "Please provide arguments in the following format:\n$ " +
        filename + " <number1> <number2> ...  <numberN>\n\n" \
        "Where all arguments are non-negative integer numbers. \n" \
        "Example: " + filename + " 5 1 17.\n\n";
}

inline int64_t checkArgument(const char* argv) {
    int i = 0;
    if (argv[i] == '-') {
        ++i;
    }
    for (; argv[i] != '\0'; ++i) {
        if (argv[i] < '0' || argv[i] > '9') {
            throw std::runtime_error("ERROR: Wrong number format!\n");
        }
    }
    int64_t x = std::stoll(argv);
    return x;
}

std::string EulerApplication::operator()(int argc, const char** argv) const {
    if (argc == 1) {
        return getHelp(argv[0]);
    }
    std::ostringstream ss;
    for (int i = 1; i < argc; ++i) {
        try {
            int64_t x, res;
            x = checkArgument(argv[i]);
            res = phi(x);
            ss << res << " ";
        }
        catch (std::exception& exc) {
            return exc.what() + getHelp(argv[0]);
        }
    }
    return ss.str();
}
