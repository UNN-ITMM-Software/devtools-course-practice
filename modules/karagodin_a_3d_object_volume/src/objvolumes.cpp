// Copyright 2024 Karagodin Andrey

#include "include/objvolumes.h"

Sphere::Sphere(double r) : radius(r) {}
double Sphere::volume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
}

Cube::Cube(double s) : side(s) {}
double Cube::volume() const {
    return std::pow(side, 3);
}

Cylinder::Cylinder(double r, double h) : radius(r), height(h) {}
double Cylinder::volume() const {
    return M_PI * std::pow(radius, 2) * height;
}
