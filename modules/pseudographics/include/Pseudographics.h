// Copyright 2021 Galkin Vladislav

#ifndef MODULES_PSEUDOGRAPHICS_INCLUDE_PSEUDOGRAPHICS_H_
#define MODULES_PSEUDOGRAPHICS_INCLUDE_PSEUDOGRAPHICS_H_

#pragma once
#include <iostream>
#include <string>

class Pseudographics {
 private:
    std::string vecUp, vecMid, vecDown;
 public:
    explicit Pseudographics(int num);
    ~Pseudographics();
    std::string get_graph() const;
    std::string get_Up_graph() const;
    std::string get_Mid_graph() const;
    std::string get_Down_graph() const;
};

#endif  // MODULES_PSEUDOGRAPHICS_INCLUDE_PSEUDOGRAPHICS_H_
