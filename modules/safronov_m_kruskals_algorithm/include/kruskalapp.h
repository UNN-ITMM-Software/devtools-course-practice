// Copyright 2024 Safronov Mikhail

#pragma once

#ifndef KRUSKAL_APP_H
#define KRUSKAL_APP_H

#include <string>

class KruskalApp {
public:
    std::string Parse(int argc, char *argv[]);
private:
    std::string Help(const std::string& app_name, const std::string& message = "");
    bool Validate(int argc, char* argv[]);
};

#endif // KRUSKAL_APP_H
