// Copyright 2024 Belan Vadim

#ifndef MODULES_BELAN_INTERSECTIO_LAB3_INCLUDE_SAVCHUK_INTERSECTIO_H_
#define MODULES_BELAN_INTERSECTIO_LAB3_INCLUDE_SAVCHUK_INTERSECTIO_H_

#include "include/savchuk_point.h"
#include "include/savchuk_segment.h"

class TwoSegments {
 public:
    static bool checkIntersection
    (const Segment& segment1, const Segment& segment2);
    static bool checkParallel(const Segment& segment1, const Segment& segment2);
};

#endif  // MODULES_BELAN_INTERSECTIO_LAB3_INCLUDE_SAVCHUK_INTERSECTIO_H_
