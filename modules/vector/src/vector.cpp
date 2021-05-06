// Copyright 2021 Vlasov Maksim

#include "include/vector.h"

#include <cmath>
#include <limits>
#include <stdexcept>

Vector::Vector() : m_x(0), m_y(0), m_z(0) {
}

Vector::Vector(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {
}

bool Vector::operator==(const Vector& other) const {
    return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
}

bool Vector::operator!=(const Vector& other) const {
    return !(*this == other);
}

double Vector::x() const {
    return m_x;
}

double Vector::y() const {
    return m_y;
}

double Vector::z() const {
    return m_z;
}

void Vector::setX(double x) {
    m_x = x;
}

void Vector::setY(double y) {
    m_y = y;
}

void Vector::setZ(double z) {
    m_z = z;
}

double Vector::norm() const {
    return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

double Vector::dot(const Vector& other) const {
    return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

Vector Vector::operator*(const Vector& other) const {
    double x = m_y * other.m_z - m_z * other.m_y;
    double y = m_z * other.m_x - m_x * other.m_z;
    double z = m_x * other.m_y - m_y * other.m_x;
    return Vector(x, y, z);
}

Vector Vector::normalize() const {
    double norm_ = norm();
    if (norm_ < std::numeric_limits<double>::epsilon())
        throw std::runtime_error("Zero vector cannot be normalized.");
    return Vector(m_x / norm_, m_y / norm_, m_z / norm_);
}
