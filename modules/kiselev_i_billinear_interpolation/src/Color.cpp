// Copyright 2min24 Kiselev Igor

#include "include/Color.h"

Color::Color() : R(0), G(0), B(0) {}

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

int Color::getR() const {
    return R;
}

int Color::getG() const {
    return G;
}

int Color::getB() const {
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

void Color::setColor(int r, int g, int b) {
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
