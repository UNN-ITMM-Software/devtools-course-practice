// Copyright 2021 Loganov Andrei

#ifndef MODULES_INTERSECTLINEANDPLANE_INCLUDE_ILAP_H_
#define MODULES_INTERSECTLINEANDPLANE_INCLUDE_ILAP_H_

class Point {
 public:
double x, y, z;
Point CreateVector(Point A, Point B);
Point VProizv(Point A, Point B);
double ScalarProizv(Point A, Point B);
Point Normalize(Point A);
void PlaneIntersectLine(Point A, Point B, Point C, Point X, Point Y);
};
#endif  // MODULES_INTERSECTLINEANDPLANE_INCLUDE_ILAP_H_
