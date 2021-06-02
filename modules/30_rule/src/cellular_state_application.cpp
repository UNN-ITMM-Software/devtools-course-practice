// Copyright 2021 Gogov Vladislav

#include "include/cellular_state_application.h"

#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/30_rule.h"

inline int checkArgument(const char* argv) {
    int result = std::stoi(argv);
    if (result <= 0)
        throw std::runtime_error("ERROR " + std::string(argv) +
                                 " invalid arguments\n");
    return result;
}

std::string CellularStateApplication::operator()(int argc,
                                                 const char* argv[]) const {
    if (argc == 1) {
        return help(argv[0]);
    } else if (argc != 4) {
        return "ERROR: Should be 4 arguments.\n" + help(argv[0]);
    }

    int count_iteration, rows;
    try {
        count_iteration = checkArgument(argv[1]);
        rows = checkArgument(argv[2]);
    } catch (std::exception& e) {
        return e.what() + help(argv[0]);
    }

    int cols = static_cast<int>(std::strlen(argv[3]));
    std::vector<CellState> states(cols);
    for (int i = 0; i < cols; i++) {
        if (argv[3][i] != 'A' && argv[3][i] != 'D')
            return "ERROR: Incorrect state.\n" + help(argv[0]);
        states[i] = argv[3][i] == 'A' ? CellState::ALIVE : CellState::DEAD;
    }
    CellularAuto automat(rows, cols, states);

    automat.iterate(count_iteration);

    const std::vector<std::vector<CellState>>& automat_states =
        automat.get_state();

    std::ostringstream stream;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            stream << (automat_states[i][j] == CellState::ALIVE ? "A" : "D");
        }
        stream << std::endl;
    }
    return stream.str();
}

std::string CellularStateApplication::help(const std::string& filename) const {
    return "This is a celluar state application.\n\n" \
           "Please provide arguments in the following format:\n$ " +
           filename + " <count_iterations> <rows> <state>\n\n" \
           "Where all arguments are positive integer numbers, " \
           "and <state> is string of characters 'A'(ALIVE), 'D'(DEAD).\n" \
           "Example: " + filename + " 2 5 DDDADDD.\n\n";
}
