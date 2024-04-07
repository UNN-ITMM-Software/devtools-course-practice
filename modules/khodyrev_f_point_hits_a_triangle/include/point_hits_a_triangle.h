// Copyright 2024 Khodyrev Fedor

#ifndef MODULES_KHODYREV_F_POINT_HITS_A_TRIANGLE_INCLUDE_POINT_HITS_A_TRIANGLE_H_
#define MODULES_KHODYREV_F_POINT_HITS_A_TRIANGLE_INCLUDE_POINT_HITS_A_TRIANGLE_H_

class Point {
 private:
  double x;
  double y;

 public:
  Point(double x_coord, double y_coord);
  double getX() const;
  double getY() const;
};

class Triangle {
 private:
  Point v1;
  Point v2;
  Point v3;
  static double distance(const Point& p1, const Point& p2);

 public:
  Triangle(const Point& v1, const Point& v2, const Point& v3);
  bool isValid() const;
  bool isInside(const Point& p) const;
};

#endif  // MODULES_KHODYREV_F_POINT_HITS_A_TRIANGLE_INCLUDE_POINT_HITS_A_TRIANGLE_H_
