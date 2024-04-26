// Copyright 2024 Shmelev Ivan

#include "include/tower_of_hanoi_app.h"

#include <cstring>
#include <exception>
#include <sstream>

bool TowerOfHanoiApplication::Validate(int argc, char *argv[]) {
    int required_argc = 2;
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (std::strcmp(argv[1], "--help") == 0) {
        Help(argv[0]);
        return false;
    } else if (std::stoi(argv[1]) < 1) {
        Help(argv[0], "Count of rings has to be more than zero");
        return false;
    } else if (argc != required_argc) {
        Help(argv[0], "Incorrect number of arguments.");
        return false;
    } else {
        try {
            tower = TowerOfHanoi();
        } catch(const std::exception& e) {
            Help(argv[0], "Invalid arguments.");
            return false;
        }
    }
    return true;
}

void TowerOfHanoiApplication::Help(const char *application,
                                         const char *errMsg) {
    std::stringstream message;

    if (errMsg) {
        message << "Error: " << errMsg << '\n';
    }

    message << "Usage:\n";
    message << '\t' << application << " <number_of_rings>\n";
    message << "Where:\n";
    message << '\t' << " <number_of_rings> is number of rings for the tower\n";
    msg = message.str();
}

std::string TowerOfHanoiApplication::TowerOfHanoiCount
(int argc, char *argv[]) {
    if (Validate(argc, argv)) {
        try {
            std::vector<std::vector<int>> steps =
                    tower.CalculateSteps(std::stoi(argv[1]));
            return tower.GetStepsAsString(steps);
        }
        catch(const std::exception& e) {
            return "Error: Invalid input.";
        }
    }
    return msg;
}
