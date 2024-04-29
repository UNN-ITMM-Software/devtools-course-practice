// Copyright 2024 Mukhin Ivan
#ifndef MODULES_MUKHIN_I_VECTORS_INCLUDE_VECTORS_H_
#define MODULES_MUKHIN_I_VECTORS_INCLUDE_VECTORS_H_

#include <cmath>
#include <ostream>
#include <type_traits>
#include <initializer_list>

namespace mukhin_i {

template<typename T,
         typename =\
         typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class Vector3D{
    T x;
    T y;
    T z;

 public:
    T operator[](int i) const {
        switch (i) {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            default:
                break;
        }
        return 0.0;
    }

    T& operator[](int i) {
        switch (i) {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            default:
                break;
        }
        return 0.0;
    }

    Vector3D() : x(0), y(0), z(0) {};

    Vector3D(const std::initializer_list<T>& values) {
        auto iter = values.begin();
        x = *(iter++);
        y = *(iter++);
        z = *(iter++);
    }

    Vector3D(const Vector3D& v) noexcept {
        x = v.x;
        y = v.y;
        z = v.z;
    }

    Vector3D& operator=(const Vector3D& v) {
        if (this == &v) return *this;
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    T norm() {
        return std::sqrt(dot(*this, *this));
    }

    friend Vector3D operator+(const Vector3D& v1, const Vector3D& v2) {
        return Vector3D({v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
    }

    friend Vector3D operator-(const Vector3D& v1, const Vector3D& v2) {
        return Vector3D({v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
    }

    friend Vector3D operator*(const Vector3D& v1, const Vector3D& v2) {
        return Vector3D({v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
    }

    friend T dot(const Vector3D& v1, const Vector3D& v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    friend bool operator==(const Vector3D& v1, const Vector3D& v2) {
        if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z) {
            return true;
        } else {
            return false;
        }
    }

    friend bool operator!=(const Vector3D& v1, const Vector3D& v2) {
        return !(v1 == v2);
    }

    friend std::ostream& operator<<(std::ostream& obj, const Vector3D& v) {
        obj << "{" << v[0]
            << " , " << v[1]
            << " , " << v[2]
            << "}" << std::endl;
        return obj;
    }
};

}  // namespace mukhin_i
#endif  // MODULES_MUKHIN_I_VECTORS_INCLUDE_VECTORS_H_
