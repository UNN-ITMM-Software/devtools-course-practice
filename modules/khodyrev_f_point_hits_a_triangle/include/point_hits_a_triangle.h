// Copyright 2024 Khodyrev Fedor

#ifndef MODULES_KHODYREV_F_POINT_HITS_A_TRIANGLE_INCLUDE_POINT_HITS_A_TRIANGLE_H_
#define MODULES_KHODYREV_F_POINT_HITS_A_TRIANGLE_INCLUDE_POINT_HITS_A_TRIANGLE_H_

class Point {
 private:
  double x;
  double y;

 public:
  Point(double x_coord = 0,
   double y_coord = 0);
  double getX() const;
  double getY() const;
  bool operator==(const Point& other) const;
};

class Triangle {
 private:
  Point v1;
  Point v2;
  Point v3;
  static double distance(const Point& p1, const Point& p2);

 public:
  Triangle(const Point& v1 = Point(1, 1),
   const Point& v2 = Point(-1, 1), const Point& v3 = Point(0, -1));
  bool isValid() const;
  bool isInside(const Point& p) const;
};

#endif  // MODULES_KHODYREV_F_POINT_HITS_A_TRIANGLE_INCLUDE_POINT_HITS_A_TRIANGLE_H_
