// Copyright 2024 Vinokurov Ivan

#ifndef MODULES_VINOKUROV_I_FIGURE_SURFACE_INCLUDE_FIGURE_SURFACE_H_
#define MODULES_VINOKUROV_I_FIGURE_SURFACE_INCLUDE_FIGURE_SURFACE_H_

#define PI 3.141592653589793238463

#include <stdexcept>
#include <vector>

class FigureSurface {
 public:
     double fnCalculateSurfaceParallelepiped(double _a, double _b, double _c);

     double fnCalculateSurfaceCylinderSide(double _r, double _h);

     double fnCalculateSurfaceCylinderFull(double _r, double _h);

     double fnCalculateSurfaceConeSide(double _r, double _l);

     double fnCalculateSurfaceConeFull(double _r, double _l);

     double fnCalculateSurfaceSphere(double _r);
};

#endif  // MODULES_VINOKUROV_I_FIGURE_SURFACE_INCLUDE_FIGURE_SURFACE_H_
