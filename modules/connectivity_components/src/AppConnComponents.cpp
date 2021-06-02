// Copyright 2021 Tkachev Alexey

#include <vector>
#include <string>

#include "include/app_connectivity_components.h"

AppConnComponents::AppConnComponents(): graph(0) {}

std::string AppConnComponents::help() {
    return std::string("\n\n\tPlease, use commands via the instruction below:\n"
       "first argument is the app name.\n "
       "After you can control whatever you want via:\n"
       "create N      - creates graph with size N\n"
       "set DATA X Y  - DATA is 0 or 1, X and Y are coords in matrix\n"
       "get X Y       - get DATA from X, Y cell of matrix\n"
       "size          - get size of the matrix\n"
       "append        - increases the size of the matrix by 1\n"
       "getcountcomps - get count components of connectivity.\n"
       "\tThank you for using!\n"
       "\tPlease, repeat your command using the instruction above.\n");
}

std::string AppConnComponents::operator()(int argc, const char** argv) {
    if (argc < 2) {
        return help();
    }
    for (int current_arg = 1; current_arg < argc; current_arg++) {
        std::string current_argv =
                static_cast<std::string>(argv[current_arg]);
        try {
            if (current_argv == "create") {
                current_arg++;
                this->graph = Graph(std::stoi(argv[current_arg]));
            } else {
                if (current_argv == "get") {
                    current_arg++;
                    unsigned int x = std::stoi(argv[current_arg]);
                    current_arg++;
                    unsigned int y = std::stoi(argv[current_arg]);
                    this->response =
                            std::to_string(this->graph.getElement(x, y));
                } else {
                    if (current_argv == "set") {
                        current_arg++;
                        unsigned int data = std::stoi(argv[current_arg]);
                        current_arg++;
                        unsigned int x = std::stoi(argv[current_arg]);
                        current_arg++;
                        unsigned int y = std::stoi(argv[current_arg]);
                        this->graph.setElement(data, x, y);
                    } else {
                        if (current_argv == "append") {
                            this->graph.append();
                        } else {
                            if (current_argv == "size") {
                                this->response =
                                        std::to_string(this->graph.getSize());
                            } else {
                                if (current_argv == "getcountcomps") {
                                    this->response =
                                            std::to_string(
                                    this->graph.getCountConnComps());
                                } else {
                                    this->response = "invalid arguments";
                                }
                            }
                        }
                    }
                }
            }
        } catch (...) {
            this->response = "invalid arguments";
        }
    }

    return this->response;
}
