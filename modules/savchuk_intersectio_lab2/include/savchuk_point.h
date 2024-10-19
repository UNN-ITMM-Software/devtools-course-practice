// Copyright 2024 Savchuk Anton

#ifndef MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_SAVCHUK_POINT_H_
#define MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_SAVCHUK_POINT_H_

class Point {
 public:
  Point(double x, double y) : x(x), y(y) {}
  double getX() const { return x; }
  double getY() const { return y; }

 private:
  double x;
  double y;
};

#endif  // MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_SAVCHUK_POINT_H_
