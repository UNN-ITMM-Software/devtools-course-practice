// Copyright 2021 Vlasov Maksim
#ifndef MODULES_VECTOR_INCLUDE_VECTOR_H_
#define MODULES_VECTOR_INCLUDE_VECTOR_H_

class Vector {
    double m_x;
    double m_y;
    double m_z;

 public:
    Vector();
    Vector(double x, double y, double z);
    Vector(const Vector&) = default;
    Vector(Vector&&) = default;
    ~Vector() = default;

    Vector& operator=(const Vector&) = default;
    Vector& operator=(Vector&&) = default;

    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

    double x() const;
    double y() const;
    double z() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double norm() const;
    double dot(const Vector& other) const;
    Vector operator*(const Vector& other) const;
    Vector normalize() const;
};

#endif  // MODULES_VECTOR_INCLUDE_VECTOR_H_
