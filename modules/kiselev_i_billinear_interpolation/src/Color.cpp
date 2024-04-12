// Copyright 2min24 Kiselev Igor

#include "include/Color.h"

Color::Color(int r, int g, int b) {
    if (r > max) R = max;
    else if (r < min) R = min;
    else
            R = r;
    if (g > max) G = max;
    else if (g < min) G = min;
    else
            G = g;
    if (b > max) B = max;
    else if (b < min) B = min;
    else
            B = b;
}

Color::Color(const Color& c) {
    R = c.getR();
    G = c.getG();
    B = c.getB();
}

char Color::getR() const {
    return R;
}

char Color::getG() const {
    return G;
}

char Color::getB() const {
    return B;
}

void Color::setR(int r) {
    if (r > max) R = max;
    else if (r < min) R = min;
    else
            R = r;
}

void Color::setG(int g) {
    if (g > max) G = max;
    else if (g < min) G = min;
    else
            G = g;
}

void Color::setB(int b) {
    if (b > max) B = max;
    else if (b < min) B = min;
    else
            B = b;
}
