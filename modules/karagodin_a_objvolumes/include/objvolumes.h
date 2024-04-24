// Copyright 2024 Karagodin Andrey

#ifndef MODULES_KARAGODIN_A_OBJVOLUMES_INCLUDE_OBJVOLUMES_H_
#define MODULES_KARAGODIN_A_OBJVOLUMES_INCLUDE_OBJVOLUMES_H_
#define _USE_MATH_DEFINES

#include <math.h>
#include <cmath>
#include <stdexcept>

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
  double volume() const;
};

class Cube : public Shape3D {
 private:
  double side;

 public:
  explicit Cube(double s);
  double volume() const;
};

class Cylinder : public Shape3D {
 private:
  double radius, height;

 public:
  Cylinder(double r, double h);
  double volume() const;
};

#endif  // MODULES_KARAGODIN_A_OBJVOLUMES_INCLUDE_OBJVOLUMES_H_
