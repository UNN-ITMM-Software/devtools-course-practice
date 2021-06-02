// Copyright 2021 Gapon Andrey

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/NumConvCalcApplication.h"
#include "include/NumConvCalc.h"

std::string NumConvCalcApplication::help(const std::string& filename) const {
  return "This is an application of BIN/OCT/HEX converter.\n\n"
    "Please provide arguments in this format:\n$ " +
    filename + " BIN(OCT or HEX) <value>\n\n"
    "Where <value> is the value which you want to convert.\n\n"
    "Example1: " + filename + " BIN 1000\n" \
    "Example2: " + filename + " OCT 10\n" \
    "Example3: " + filename + " HEX AB\n";
}

std::string NumConvCalcApplication::operator()(int argc,
  const char* argv[]) const {
    if (argc <= 1) {
        return help(argv[0]);
    }
    try {
        if (argc == 2) {
            throw std::runtime_error("ERROR: invalid argument\n\n");
        } else {
            int size = argc - 1;
            std::vector<std::string> str;
            for (int i = 0; i < size; i++) {
                std::stringstream convert(argv[i + 1]);
                std::string num;
                convert >> num;
                str.push_back(num);
            }
            std::ostringstream stream;
            if (str[0] == "BIN") {
                if (str[1].find_first_not_of("01") != std::string::npos)
                    throw std::runtime_error("ERROR: " +
                        str[1] + " is invalid argument\n\n");
                NumberConverter val(str[1], BIN);
                stream << "BIN to OCT: " << val.GetNumberInOct() << "\n";
                stream << "BIN to HEX: " << val.GetNumberInHex() << "\n";
            } else if (str[0] == "OCT") {
                 if (str[1].find_first_not_of("01234567") != std::string::npos)
                    throw std::runtime_error("ERROR: " +
                        str[1] + " is invalid argument\n\n");
                NumberConverter val(str[1], OCT);
                stream << "OCT to BIN: " << val.GetNumberInBin() << "\n";
                stream << "OCT to HEX: " << val.GetNumberInHex() << "\n";
            } else if (str[0] == "HEX") {
                if (str[1].find_first_not_of("0123456789ABCDEF")
                    != std::string::npos)
                    throw std::runtime_error("ERROR: " +
                        str[1] + " is invalid argument\n\n");
                NumberConverter val(str[1], HEX);
                stream << "HEX to BIN: " << val.GetNumberInBin() << "\n";
                stream << "HEX to OCT: " << val.GetNumberInOct() << "\n";
            } else {
                throw std::runtime_error("ERROR: " +
                    str[0] + " is invalid argument\n\n");
            }
            return stream.str();
        }
    } catch (const std::exception& e) {
    return e.what() + help(argv[0]);
  }
}
