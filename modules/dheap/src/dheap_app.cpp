// Copyright 2021 Taktaev Artem

#include "include/dheap_app.h"

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/dheap.h"

std::string DheapApp::operator()(int argc, const char* argv[],
                                 int* retcode) const {
    if (retcode != nullptr)
        *retcode = 1;
    if (argc < 2)
        return help(argv[0]);
    int base = std::stoi(argv[1]);
    std::vector<int> weights;
    weights.reserve(argc - 2);
    for (int i = 2; i < argc; i++) {
        std::string arg = argv[i];
        try {
            double weight = std::stoi(arg);
            weights.push_back(weight);
        } catch (std::invalid_argument& e) {
            return "[ERROR] " + arg + ": invalid argument. " +
                   std::string(e.what());
        } catch (std::out_of_range& e) {
            return "[ERROR] " + arg + ": out of range. " +
                   std::string(e.what());
        }
    }
    std::ostringstream str;
    try {
        Dheap test_heap(base, weights);
        std::vector<int> hilled_weights = test_heap.getWeights();
        str << hilled_weights[0];
        for (size_t i = 1; i < hilled_weights.size(); i++)
            str << ' ' << hilled_weights[i];
    } catch (std::runtime_error& e) {
        return "[ERROR] Base must be greater than 1 " +
               std::string(e.what());
    }
    if (retcode)
        *retcode = 0;
    return str.str();
}

std::string DheapApp::help(const std::string& filename) const {
    return "Usage: " + filename + " BASE WEIGHTS \nExample: " + filename +
           " 4 11 9 9 6 8 3 4 12 7";
}
