// Copyright 2024 Nikitin Kirill
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

class Triangle {
 public:
  Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

  double sideLength(double x1, double y1, double x2, double y2) const;
  double perimeter() const;
  double area() const;

 private:
  double x1, y1, x2, y2, x3, y3;
};

#endif  // TRIANGLE_H
#pragma once
