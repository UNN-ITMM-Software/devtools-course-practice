// Copyright 2024 Karagodin Andrey

#include "include/objvolumes.h"

Sphere::Sphere(double r) : radius(r) {
    if (radius <= 0) {
        throw std::invalid_argument
        ("Radius cannot be equal or less than zero.");
    }
}
double Sphere::volume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
}

Cube::Cube(double s) : side(s) {
    if (side <= 0) {
        throw std::invalid_argument
        ("Sides cannot be equal or less than zero.");
    }
}
double Cube::volume() const {
    return std::pow(side, 3);
}

Cylinder::Cylinder(double r, double h) : radius(r), height(h) {
    if (radius <= 0 || height <= 0) {
        throw std::invalid_argument
        ("Radius or Height cannot be equal or less than zero.");
    }
}
double Cylinder::volume() const {
    return M_PI * std::pow(radius, 2) * height;
}
