// Copyright 2024 Savchuk Anton

#include "include/savchuk_segment.h"
#include <algorithm>

bool Segment::onSegment(const Point& p, const Point& q, const Point& r) const {
    if (q.getX() <= std::max(p.getX(), r.getX())
    && q.getX() >= std::min(p.getX(), r.getX()) &&
        q.getY() <= std::max(p.getY(), r.getY())
        && q.getY() >= std::min(p.getY(), r.getY()))
       return true;
    return false;
}
