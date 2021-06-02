// Copyright 2021 Bulychev Vladislav

#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

#include "include/tree_app.h"
#include "include/btree.h"

std::string TreeApp::help(const std::string& filename) const {
    return "This is application for tree class\n" \
        "Actions:\n" \
        "add <value> - add value to the tree\n" \
        "find <value> - find the value in the tree\n";
}

std::string TreeApp::operator()(int argc, const char** argv) {
    if (argc == 1) {
        return help(*argv);
    }
    tnode* t_;
    t_ = nullptr;
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
            int sos = str.size();
            for (int j = 0; j < sos; j += 2) {
                if (str[j] == "add") {
                    int n = atoi(str[j + 1].c_str());
                    t_ = addtree(t_, n);
                } else if (str[j] == "find") {
                    int n = atoi(str[j + 1].c_str());
                    tnode* r = find(t_, n);
                    if (r == nullptr) {
                        stream << "(" << n << " is not found) ";
                    } else {
                        stream << "(" << r->value << " is found) ";
                    }
                } else {
                    throw std::runtime_error("ERROR: " +
                        str[j] + " is invalid argument\n\n");
                }
            }
            return stream.str();
        }
    }
    catch (std::exception& e) {
        return e.what() + help(argv[0]);
    }
}
