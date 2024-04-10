// Copyright 2024 Kriseev Mikhail

#include "include/vector_3d.h"
#include <cmath>

Vector3d::Vector3d(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector3d::getX() const { return this->x; }

double Vector3d::getY() const { return this->y; }

double Vector3d::getZ() const { return this->z; }

double Vector3d::getNorm() const {
    return sqrt(this->squareNorm());
}

Vector3d Vector3d::getNormalizedVector() const { return Vector3d(); }

double Vector3d::dotProduct(const Vector3d &vector) const { return 0; }

Vector3d Vector3d::crossProduct(const Vector3d &vector) const {
  return Vector3d();
}

double Vector3d::squareNorm() const {
    return this->x * this->x + this->y * this->y + this->z * this->z;
}
