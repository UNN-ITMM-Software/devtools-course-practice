// Copyright 2021 Ikromov Inom

#include <string>
#include "include/conways_game_of_life.h"

Conways_life::Conways_life(const int w, const int h) {
    if (w <= 0 || h <= 0) {
        throw std::string("Wrong input.");
    } else {
        sizeh_ = h;
        sizew_ = w;
        field_.reserve(w*h);
        check_.reserve(w*h);
        field_.resize(w*h);
        check_.resize(w*h);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                field_[i*sizew_ + j] = ".";
                check_[i*sizew_ + j] = false;
           }
        }
    }
}
void Conways_life::putStart(const int wi, const int hi) {
    if (wi < 0 || hi < 0 || wi >= sizew_ || hi >= sizeh_) {
        throw std::string("Wrong point.");
    } else {
        field_[hi*sizew_+wi] = "+";
    }
}
int Conways_life::getH() { return sizeh_; }
int Conways_life::getW() { return sizew_; }
std::string Conways_life::getPoint(const int wi, const int hi) {
    return field_[hi*sizew_ + wi];
}
void Conways_life::redraw() {
    for (int i = 0; i < sizeh_; i++) {
        for (int j = 0; j < sizew_; j++) {
            if (check_[i*sizew_ + j]) field_[i*sizew_ + j] = "+";
            else
                field_[i*sizew_ + j] = ".";

            check_[i*sizew_ + j] = false;
        }
    }
}
void Conways_life::checkNextStep() {
    for (int i = 0; i < sizew_; i++) {
        for (int j = 0; j < sizeh_; j++) {
            aliveNextStep(i, j);
        }
    }
}
bool Conways_life::aliveNextStep(const int wi, const int hi) {
    int alive_neigh;
    bool res = true;
    alive_neigh = countNeighbors(wi, hi);

    if (field_[hi*sizew_ + wi] == ".") {
        if (alive_neigh == 3)
            check_[hi*sizew_ + wi] = true;
    }
    if (field_[hi*sizew_ + wi] == "+") {
        if (alive_neigh == 2 || alive_neigh == 3) {
            check_[hi*sizew_ + wi] = true;
        } else {
            check_[hi*sizew_ + wi] = false;
            res = false;
        }
    }
    return res;
}
int Conways_life::countNeighbors(const int wi, const int hi) {
    int count = 0;
    if ((wi != 0) && (wi != sizew_ - 1) && (hi != 0) && (hi != sizeh_ - 1)) {
        if (field_[hi*sizew_ + wi + 1] == "+") count++;
        if (field_[hi*sizew_ + wi - 1] == "+") count++;
        if (field_[(hi + 1)*sizew_ + wi - 1] == "+") count++;
        if (field_[(hi + 1)*sizew_ + wi + 1] == "+") count++;
        if (field_[(hi + 1)*sizew_ + wi] == "+") count++;
        if (field_[(hi - 1)*sizew_ + wi - 1] == "+") count++;
        if (field_[(hi - 1)*sizew_ + wi + 1] == "+") count++;
        if (field_[(hi - 1)*sizew_ + wi] == "+") count++;
    } else {
        if (wi == 0 && hi == 0) {
            if (field_[1] == "+") count++;
            if (field_[sizew_-1] == "+") count++;
            if (field_[sizew_] == "+") count++;
            if (field_[sizew_ + 1] == "+") count++;
            if (field_[sizew_ + sizew_ - 1] == "+") count++;
            if (field_[(sizeh_ - 1)*sizew_] == "+") count++;
            if (field_[(sizeh_ - 1)*sizew_ + 1] == "+") count++;
            if (field_[(sizeh_ - 1)*sizew_ + sizew_ - 1] == "+") count++;
        } else if (wi == 0 && hi == sizeh_ - 1) {
            if (field_[(hi - 1)*sizew_] == "+") count++;
            if (field_[(hi - 1)*sizew_ + 1] == "+") count++;
            if (field_[(hi - 1)*sizew_ + sizew_ - 1] == "+") count++;
            if (field_[hi*sizew_ + 1] == "+") count++;
            if (field_[hi*sizew_ + sizew_ - 1] == "+") count++;
            if (field_[sizew_ - 1] == "+") count++;
            if (field_[0] == "+") count++;
            if (field_[1] == "+") count++;
        } else if (wi == sizew_ - 1 && hi == 0) {
            if (field_[(sizeh_ - 1)*sizew_ + wi - 1] == "+") count++;
            if (field_[(sizeh_ - 1)*sizew_ + wi] == "+") count++;
            if (field_[(sizeh_ - 1)*sizew_] == "+") count++;
            if (field_[wi - 1] == "+") count++;
            if (field_[0] == "+") count++;
            if (field_[sizew_ + wi - 1] == "+") count++;
            if (field_[sizew_ + wi] == "+") count++;
            if (field_[sizew_] == "+") count++;
        } else if (wi == sizew_ - 1 && hi == sizeh_ - 1) {
            if (field_[(hi - 1)*sizew_ + wi] == "+") count++;
            if (field_[(hi - 1)*sizew_ + wi - 1] == "+") count++;
            if (field_[(hi - 1)*sizew_] == "+") count++;
            if (field_[hi*sizew_ + wi - 1] == "+") count++;
            if (field_[hi*sizew_] == "+") count++;
            if (field_[wi - 1] == "+") count++;
            if (field_[wi] == "+") count++;
            if (field_[0] == "+") count++;
        } else if (wi == 0) {
            if (field_[(hi - 1)*sizew_] == "+") count++;
            if (field_[(hi + 1)*sizew_] == "+") count++;
            if (field_[(hi - 1)*sizew_ + 1] == "+") count++;
            if (field_[hi*sizew_ + 1] == "+") count++;
            if (field_[(hi + 1)*sizew_ + 1] == "+") count++;
            if (field_[(hi - 1)*sizew_ + sizew_ - 1] == "+") count++;
            if (field_[hi*sizew_ + sizew_ - 1] == "+") count++;
            if (field_[(hi + 1)*sizew_ + sizew_ -1] == "+") count++;
        } else if (hi == 0) {
            if (field_[wi - 1] == "+") count++;
            if (field_[wi + 1] == "+") count++;
            if (field_[sizew_ + wi - 1] == "+") count++;
            if (field_[sizew_ + wi] == "+") count++;
            if (field_[sizew_ + wi + 1] == "+") count++;
            if (field_[(sizeh_ - 1)*sizew_ + wi - 1] == "+") count++;
            if (field_[(sizeh_ - 1)*sizew_ + wi] == "+") count++;
            if (field_[(sizeh_ - 1)*sizew_ + wi + 1] == "+") count++;
        } else if (wi == sizew_ - 1) {
            if (field_[(hi - 1)*sizew_ + wi - 1] == "+") count++;
            if (field_[hi*sizew_ + wi - 1] == "+") count++;
            if (field_[(hi + 1)*sizew_ + wi] == "+") count++;
            if (field_[(hi - 1)*sizew_] == "+") count++;
            if (field_[hi*sizew_] == "+") count++;
            if (field_[(hi - 1)*sizew_] == "+") count++;
            if (field_[(hi - 1)*sizew_ + wi] == "+") count++;
            if (field_[(hi + 1)*sizew_ + wi] == "+") count++;
        } else if (hi == sizeh_ - 1) {
            if (field_[(hi - 1)*sizew_ + wi - 1] == "+") count++;
            if (field_[(hi - 1)*sizew_ + wi] == "+") count++;
            if (field_[(hi - 1)*sizew_ + wi + 1] == "+") count++;
            if (field_[wi - 1] == "+") count++;
            if (field_[wi] == "+") count++;
            if (field_[wi + 1] == "+") count++;
            if (field_[hi*sizew_ + wi - 1] == "+") count++;
            if (field_[hi*sizew_ + wi + 1] == "+") count++;
        }
    }

    return count;
}

bool Conways_life::isSystemAlive() {
    bool res = false;
    for (int i = 0; i < sizeh_; i++) {
        for (int j = 0; j < sizew_; j++) {
            if (check_[i*sizew_ + j])
                return true;
        }
    }
    return res;
}

void Conways_life::stepNextField() {
    checkNextStep();
    redraw();
    checkNextStep();
}
std::string Conways_life::Start(std::string str, int eps) {
    int steps = 0;
    std::string res = str;
    if (eps < 0) throw std::string("Wrong epsStep.");
    res = print(res);

    checkNextStep();

    while (isSystemAlive() && (steps < eps - 1)) {
        stepNextField();
        res = print(res);
        steps++;
    }

    stepNextField();
    res = print(res);

    return res;
}
std::string Conways_life::print(std::string str) {
    std::string res = str;
    for (int i = 0; i < sizeh_; i++) {
        for (int j = 0; j < sizew_; j++) {
            res += field_[i*sizew_ + j] + " ";
        }
        res += "\n";
    }
    for (int i = 0; i < 2 * sizew_; i++) {
        res += "=";
    }
    res += "\n";
    return res;
}