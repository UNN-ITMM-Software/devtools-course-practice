// Copyright 2024 Kiselev Igor

#include "include/Color.h"

Color::Color(int r, int g, int b) {
    if (r > 255) R = 255;
    else 
        if (r < 0) R = 0;
    else
            R = r;
    if (g > 255) G = 255;
    else
        if (g < 0) G = 0;
    else
            G = g;
    if (b > 255) B = 255;
    else
        if (b < 0) B = 0;
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
    if (r > 255) R = 255;
    else
        if (r < 0) R = 0;
    else
            R = r;
}

void Color::setG(int g) {
    if (g > 255) G = 255;
    else
        if (g < 0) G = 0;
    else
            G = g;
}

void Color::setB(int b) {
    if (b > 255) B = 255;
    else 
        if (b < 0) B = 0;
    else
            B = b;
}
