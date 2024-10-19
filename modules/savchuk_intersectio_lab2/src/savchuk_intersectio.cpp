// Copyright 2024 Savchuk Anton

#include "include/savchuk_intersectio.h"

#include <algorithm>
#include <cmath>

int orientation(const Point& p, const Point& q, const Point& r) {
  double val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
               (q.getX() - p.getX()) * (r.getY() - q.getY());

  if (val == 0) return 0;
  return (val > 0) ? 1 : 2;
}

bool TwoSegments::checkIntersection(const Segment& segment1,
                                    const Segment& segment2) {
  const Point& p1 = segment1.getStart();
  const Point& q1 = segment1.getEnd();
  const Point& p2 = segment2.getStart();
  const Point& q2 = segment2.getEnd();

  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  if (o1 != o2 && o3 != o4) return true;

  if (o1 == 0 && segment1.onSegment(p1, p2, q1)) return true;

  if (o2 == 0 && segment1.onSegment(p1, q2, q1)) return true;

  if (o3 == 0 && segment2.onSegment(p2, p1, q2)) return true;

  if (o4 == 0 && segment2.onSegment(p2, q1, q2)) return true;

  return false;
}

bool TwoSegments::checkParallel(const Segment& segment1,
                                const Segment& segment2) {
  double slope1 = (segment1.getEnd().getY() - segment1.getStart().getY()) /
                  (segment1.getEnd().getX() - segment1.getStart().getX());
  double slope2 = (segment2.getEnd().getY() - segment2.getStart().getY()) /
                  (segment2.getEnd().getX() - segment2.getStart().getX());

  if (std::isinf(slope1) && std::isinf(slope2)) return true;

  return slope1 == slope2;
}
