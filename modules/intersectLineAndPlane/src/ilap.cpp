// Copyright 2021 Loganov Andrei
#include <cmath>
#include <limits>
#include "include/ilap.h"

Point Point::CreateVector(Point A, Point B) {
    Point m;
    m.x = B.x - A.x;
    m.y = B.y - A.y;
    m.z = B.z - A.z;
    return m;
}
Point Point::VProizv(Point A, Point B) {
    Point VP;
    VP.x = A.y * B.z - B.y * A.z;
    VP.y = A.z * B.x - B.z * A.x;
    VP.z = A.x * B.y - B.x * A.y;
    return VP;
}
double Point::ScalarProizv(Point A, Point B) {
    return A.x * B.x + A.y * B.y + A.z * B.z;;
}

Point Point::Normalize(Point A) {
    Point B = A;
    double  norm;
    double n1 = pow(B.x, 2);
    double n2 = pow(B.y, 2);
    double n3 = pow(B.z, 2);
    norm = sqrt(n1+ n2 +n3);
    B.x  /= norm;
    B.y  /= norm;
    B.z  /= norm;
    return B;
}

void Point::PlaneIntersectLine(Point A, Point B, Point C, Point X, Point Y) {
    Point N;
    Point R;
    Point T;
    double eps;
    double d;
    N = VProizv(CreateVector(A, B), CreateVector(A, C));
    N = Normalize(N);
    R = CreateVector(X, A);
    d = ScalarProizv(N, R);
    T = CreateVector(X, Y);
    eps = ScalarProizv(N, T);
    if (eps != 0) {
        x = X.x + T.x * d / eps;
        y = X.y + T.y * d / eps;
        z = X.z + T.z * d / eps;
    } else {
        x = std::numeric_limits<double>::max();
        y = std::numeric_limits<double>::max();
        z = std::numeric_limits<double>::max();
    }
}
