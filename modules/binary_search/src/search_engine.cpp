// Copyright 2021 Zoreev Mikhail

#include "include/search_engine.h"

#include <string>
#include <vector>

std::string SearchEngine::operator()(int argc, const char* argv[],
                                     int* retcode) const {
    if (retcode != nullptr) {
        *retcode = 1;
    }
    if (argc < 3)
        return help(argv[0]);
    double desired_value;
    std::string desired_value_string;
    try {
        desired_value_string = std::string(argv[1]);
        desired_value = std::stod(desired_value_string);
    } catch(std::invalid_argument& e) {
        return "[ERROR] " + desired_value_string + ": invalid argument";
    } catch (std::out_of_range& e) {
        return "[ERROR] " + desired_value_string + " out of range.";
    }

    std::vector<double> values;
    for (int i = 2; i < argc; i++) {
        std::string value_string;
        try {
            value_string = std::string(argv[i]);
            double value = std::stod(value_string);
            values.push_back(value);
        } catch(std::invalid_argument& e) {
            return "[ERROR] " + value_string + ": invalid argument";
        } catch (std::out_of_range& e) {
            return "[ERROR] " + value_string + " out of range.";
        }
    }
    if (!std::is_sorted(values.begin(), values.end())) {
        return "[ERROR] row is not sorted";
    }
    int result;
    result = BinarySearch::Search<double>(desired_value, values, 0,
                                          static_cast<int>(
                                                  values.size()) - 1);
    if (retcode != nullptr) {
        *retcode = 0;
    }
    std::ostringstream str;
    str << "Index: " << result;
    return str.str();
}

std::string SearchEngine::help(const std::string& filename) const {
    return "Usage: " + filename + " DESIRED VALUES...\n" \
           "Example: " + filename + " 5 3 2 4 5\n" \
           "Will search \"5\" element in \"1 2 4 5\" row";
}
