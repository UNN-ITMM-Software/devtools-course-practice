// Copyright 2024 Kriseev Mikhail

#include "include/vector_3d.h"

#include <cmath>
#include <stdexcept>

#define EPSILON 1e-9

Vector3d::Vector3d(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector3d::getX() const { return this->x; }

double Vector3d::getY() const { return this->y; }

double Vector3d::getZ() const { return this->z; }

double Vector3d::getNorm() const { return sqrt(this->squareNorm()); }

Vector3d Vector3d::getNormalizedVector() const {
  if (std::abs(x) < EPSILON && std::abs(y) < EPSILON && std::abs(z) < EPSILON) {
    throw std::runtime_error("Cannot normalize zero vector");
  }
  return (*this) / (this->getNorm());
}

double Vector3d::dotProduct(const Vector3d &vector) const {
  return this->x * vector.x + this->y * vector.y + this->z * vector.z;
}

Vector3d Vector3d::crossProduct(const Vector3d &vector) const {
  return Vector3d{
      this->y * vector.z - this->z * vector.y,
      this->z * vector.x - this->x * vector.z,
      this->x * vector.y - this->y * vector.x,
  };
}

double Vector3d::squareNorm() const {
  return this->x * this->x + this->y * this->y + this->z * this->z;
}

Vector3d Vector3d::operator/(double factor) const {
  return Vector3d{this->x / factor, this->y / factor, this->z / factor};
}

Vector3d Vector3d::operator*(double factor) const {
  return Vector3d{this->x * factor, this->y * factor, this->z * factor};
}

Vector3d Vector3d::operator+(const Vector3d &v) const {
  return Vector3d{this->x + v.x, this->y + v.y, this->z + v.z};
}

Vector3d Vector3d::operator-(const Vector3d &v) const {
  return Vector3d{this->x - v.x, this->y - v.y, this->z - v.z};
}

bool Vector3d::operator==(const Vector3d &v) const {
  return std::abs(this->x - v.x) < EPSILON &&
         std::abs(this->y - v.y) < EPSILON && std::abs(this->z - v.z) < EPSILON;
}

bool Vector3d::operator!=(const Vector3d &v) const {
  return !this->operator==(v);
}
