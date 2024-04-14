// Copyright 2024 Kriseev Mikhail

#include "include/vector_3d.h"

#include <cmath>
#include <stdexcept>

#define EPSILON 1e-9

Vector3d::Vector3d(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector3d::getX() const { return x; }

double Vector3d::getY() const { return y; }

double Vector3d::getZ() const { return z; }

double Vector3d::getNorm() const { return sqrt(squareNorm()); }

Vector3d Vector3d::getNormalizedVector() const {
  if (std::abs(x) < EPSILON && std::abs(y) < EPSILON && std::abs(z) < EPSILON) {
    throw std::invalid_argument("Cannot normalize zero vector");
  }
  return (*this) / (getNorm());
}

double Vector3d::dotProduct(const Vector3d &vector) const {
  return x * vector.x + y * vector.y + z * vector.z;
}

Vector3d Vector3d::crossProduct(const Vector3d &vector) const {
  return Vector3d{
      y * vector.z - z * vector.y,
      z * vector.x - x * vector.z,
      x * vector.y - y * vector.x,
  };
}

double Vector3d::squareNorm() const {
  return x * x + y * y + z * z;
}

Vector3d Vector3d::operator/(double factor) const {
  if (std::abs(factor) < EPSILON) {
    throw std::invalid_argument("Attempted division by zero");
  }
  return Vector3d{x / factor, y / factor, z / factor};
}

Vector3d Vector3d::operator*(double factor) const {
  return Vector3d{x * factor, y * factor, z * factor};
}

Vector3d Vector3d::operator+(const Vector3d &v) const {
  return Vector3d{x + v.x, y + v.y, z + v.z};
}

Vector3d Vector3d::operator-(const Vector3d &v) const {
  return Vector3d{x - v.x, y - v.y, z - v.z};
}

bool Vector3d::operator==(const Vector3d &v) const {
  return std::abs(x - v.x) < EPSILON &&
         std::abs(y - v.y) < EPSILON && std::abs(z - v.z) < EPSILON;
}

bool Vector3d::operator!=(const Vector3d &v) const {
  return !operator==(v);
}
