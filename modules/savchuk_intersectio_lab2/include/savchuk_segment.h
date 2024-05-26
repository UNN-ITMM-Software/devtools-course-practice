// Copyright 2024 Savchuk Anton

#ifndef MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_SAVCHUK_SEGMENT_H_
#define MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_SAVCHUK_SEGMENT_H_

#include "include/savchuk_point.h"

class Segment {
 public:
    Segment(const Point& start, const Point& end) : start(start), end(end) {}
    const Point& getStart() const { return start; }
    const Point& getEnd() const { return end; }
    bool onSegment(const Point& p, const Point& q, const Point& r) const;
 private:
    Point start;
    Point end;
};

#endif  // MODULES_SAVCHUK_INTERSECTIO_LAB2_INCLUDE_SAVCHUK_SEGMENT_H_
