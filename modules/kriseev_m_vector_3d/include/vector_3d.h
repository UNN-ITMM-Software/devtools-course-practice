// Copyright 2024 Kriseev Mikhail
#ifndef MODULES_KRISEEV_M_VECTOR_3D_INCLUDE_VECTOR_3D_H_
#define MODULES_KRISEEV_M_VECTOR_3D_INCLUDE_VECTOR_3D_H_

#include <initializer_list>

class Vector3d {
 public:
  explicit Vector3d(double x = 0.0, double y = 0.0, double z = 0.0);

  double getX() const;

  double getY() const;

  double getZ() const;

  double getNorm() const;

  Vector3d getNormalizedVector() const;

  double dotProduct(const Vector3d &vector) const;

  Vector3d crossProduct(const Vector3d &vector) const;

  Vector3d operator/(double factor) const;

  Vector3d operator*(double factor) const;

  Vector3d operator+(const Vector3d &v) const;

  Vector3d operator-(const Vector3d &v) const;

  bool operator==(const Vector3d &v) const;
  bool operator!=(const Vector3d &v) const;

 private:
  double x;
  double y;
  double z;

  double squareNorm() const;
};

#endif  // MODULES_KRISEEV_M_VECTOR_3D_INCLUDE_VECTOR_3D_H_
