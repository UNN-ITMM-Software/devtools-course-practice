// Copyright 2024 Savchuk Anton

#ifndef MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_SAVCHUK_INTERSECTIO_H_
#define MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_SAVCHUK_INTERSECTIO_H_

#include "../include/savchuk_point.h"
#include "../include/savchuk_segment.h"

class TwoSegments {
 public:
    static bool checkIntersection
    (const Segment& segment1, const Segment& segment2);
    static bool checkParallel(const Segment& segment1, const Segment& segment2);
};

int orientation(const Point& p, const Point& q, const Point& r);

#endif  // MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_SAVCHUK_INTERSECTIO_H_
