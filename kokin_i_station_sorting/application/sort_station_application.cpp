// Copyright 2024 Zhatkin Vyacheslav

#include <iostream>

#include "include/sort_station_app.h"

int main(int argc, char* argv[]) {
    auto output = SortStationApp()(argc, argv);

    std::cout << output << '\n';

    return 0;
}
