// Copyright 2024 Mironov Ilya

#include <iostream>

#include "include/polygon_price_app.h"

int main(int argc, char** argv) {
    PolygonPriceApp ppapp;
    std::cout << ppapp(argc, argv) << '\n';
    return 0;
}
