// Copyright 2024 Vinokurov Ivan

#include "include/figure_surface.h"

double FigureSurface::fnCalculateSurfaceParallelepiped(double _a,
       double _b, double _c) {
    double result = 0.0;

    if (_a <= 0 || _b <= 0 || _c <= 0) {
        throw std::invalid_argument("Invalid arguments");
    }

    return result = 2 * (_a * _b + _b * _c + _a * _c);
}

double FigureSurface::fnCalculateSurfaceCylinderSide(double _r, double _h) {
    double result = 0.0;

    if (_r <= 0 || _h <= 0) {
        throw std::invalid_argument("Invalid arguments");
    }

    return result = 2 * PI * _r * _h;
}

double FigureSurface::fnCalculateSurfaceCylinderFull(double _r, double _h) {
    double result = 0.0;

    if (_r <= 0 || _h <= 0) {
        throw std::invalid_argument("Invalid arguments");
    }

    return result = 2 * PI * _r * (_r + _h);
}

double FigureSurface::fnCalculateSurfaceConeSide(double _r, double _l) {
    double result = 0.0;

    if (_r <= 0 || _l <= 0) {
        throw std::invalid_argument("Invalid arguments");
    }

    return result = PI * _r  * _l;
}

double FigureSurface::fnCalculateSurfaceConeFull(double _r, double _l) {
    double result = 0.0;

    if (_r <= 0 || _l <= 0) {
        throw std::invalid_argument("Invalid arguments");
    }

    return result = PI * _r * (_r + _l);
}

double FigureSurface::fnCalculateSurfaceSphere(double _r) {
    double result = 0.0;

    if (_r <= 0) {
        throw std::invalid_argument("Invalid arguments");
    }

    return result = 4 * PI * _r * _r;
}
