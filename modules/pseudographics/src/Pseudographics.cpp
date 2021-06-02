// Copyright 2021 Galkin-Vladislav

#include "include/Pseudographics.h"
#include <string>

Pseudographics::Pseudographics(int num) {
    std::string s_num = std::to_string(num);
    if (s_num[0] == '-') {
        vecUp = "error#";
        vecMid = "invalid value#";
        vecDown = "error#";
    } else {
        while (s_num.length() != 0) {
            char c = s_num[0];
            s_num.erase(0, 1);
            switch (c) {
            case'0': {
                vecUp += "._.";
                vecMid += "|.|";
                vecDown += "|_|";
                break;
            }
            case'1': {
                vecUp += "...";
                vecMid += "..|";
                vecDown += "..|";
                break;
            }
            case'2': {
                vecUp += "._.";
                vecMid += "._|";
                vecDown += "|_.";
                break;
            }
            case'3': {
                vecUp += "._.";
                vecMid += "._|";
                vecDown += "._|";
                break;
            }
            case'4': {
                vecUp += "...";
                vecMid += "|_|";
                vecDown += "..|";
                break;
            }
            case'5': {
                vecUp += "._.";
                vecMid += "|_.";
                vecDown += "._|";
                break;
            }
            case'6': {
                vecUp += "._.";
                vecMid += "|_.";
                vecDown += "|_|";
                break;
            }
            case'7': {
                vecUp += "._.";
                vecMid += "..|";
                vecDown += "..|";
                break;
            }
            case'8': {
                vecUp += "._.";
                vecMid += "|_|";
                vecDown += "|_|";
                break;
            }
            case'9': {
                vecUp += "._.";
                vecMid += "|_|";
                vecDown += "..|";
                break;
            }
            }
            if (s_num.length() != 0) {
                vecUp += ' ';
                vecMid += ' ';
                vecDown += ' ';
            } else {
                vecUp += '#';
                vecMid += '#';
                vecDown += '#';
            }
        }
    }
}

Pseudographics::~Pseudographics() {
    vecUp.clear();
    vecMid.clear();
    vecDown.clear();
}

std::string Pseudographics::get_graph() const {
    std::string vecRes;
    vecRes = vecUp;
    vecRes += vecMid;
    vecRes += vecDown;
    return vecRes;
}

std::string Pseudographics::get_Up_graph() const {
    return vecUp;
}

std::string Pseudographics::get_Mid_graph() const {
    return vecMid;
}

std::string Pseudographics::get_Down_graph() const {
    return vecDown;
}
