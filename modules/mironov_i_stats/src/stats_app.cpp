// Copyright 2024 Kachalov Mikhail

#include "include/stats_app.h"
#include "include/stats.h"

#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

StatisticsApp::StatisticsApp() {}

std::string StatisticsApp::operator()(int argc, char* argv[]) const {
    if (argc < 3) {
        return "Error: Insufficient arguments. "
               "Provide data as space-separated floats and a moment order (k).";
    }

    std::vector<std::string> args(argv + 1, argv + argc);
    std::vector<float> data;
    size_t k;

    try {
        k = std::stoll(argv[argc - 1]);
        if (k == 0) {
            throw std::invalid_argument(
                "Moment order (k) must be a positive integer.");
        }
        data = ParseData(argc - 1, argv, 1);

        float mean = stats::mean(data);
        float variance = stats::var(data);
        float variance_base = stats::var_base(data);
        float moment_value = stats::moment(data, k, mean);

        std::ostringstream oss;
        oss << "Mean: " << mean << "\n"
            << "Variance (direct): " << variance << "\n"
            << "Variance (via moment): " << variance_base << "\n"
            << "Moment (k = " << k << "): " << moment_value;
        return oss.str();
    } catch (const std::invalid_argument&) {
        return "Error: Invalid data format.";
    } catch (const std::out_of_range&) {
        return "Error: Value out of range.";
    } catch (const std::exception& e) {
        return std::string("Error: ") + e.what() + "\n";
    }
}

std::vector<float> StatisticsApp::ParseData(
    int argc, char* argv[], int startIndex) const {
    std::vector<float> data;

    for (int i = startIndex; i < argc; ++i) {
        try {
            data.push_back(std::stof(argv[i]));
        } catch (const std::invalid_argument&) {
            throw std::invalid_argument("Error: Invalid data format.");
        } catch (const std::out_of_range&) {
            throw std::out_of_range("Error: Value out of range.");
        }
    }

    return data;
}
