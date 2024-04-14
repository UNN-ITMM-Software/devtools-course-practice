// Copyright 2024 Karagodin Andrey

#ifndef MODULES_KARAGODIN_A_3D_OBJECT_VOLUME_INCLUDE_OBJVOLUMES_H_
#define MODULES_KARAGODIN_A_3D_OBJECT_VOLUME_INCLUDE_OBJVOLUMES_H_

#include <cmath>

class Shape3D {
 public:
  virtual double volume() const = 0;
  virtual ~Shape3D() {}
};

class Sphere : public Shape3D {
 private:
  double radius;

 public:
  explicit Sphere(double r);
  double volume() const override;
};

class Cube : public Shape3D {
 private:
  double side;

 public:
  explicit Cube(double s);
  double volume() const override;
};

class Cylinder : public Shape3D {
 private:
  double radius, height;

 public:
  Cylinder(double r, double h);
  double volume() const override;
};

#endif  // MODULES_KARAGODIN_A_3D_OBJECT_VOLUME_INCLUDE_OBJVOLUMES_H_
