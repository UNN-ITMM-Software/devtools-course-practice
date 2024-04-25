// Copyright 2024 Vinokurov Ivan

#include <gtest/gtest.h>
#include "include/figure_surface.h"

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Parallelepiped) {
    double a = 2.0, b = 3.0, c = 0.0;
    FigureSurface figureSurfaceCalc;

    ASSERT_THROW(figureSurfaceCalc.fnCalculateSurfaceParallelepiped(a, b, c),
    std::invalid_argument);
}

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Cylinder_Side) {
    double r = 0.0, h = 3.0;
    FigureSurface figureSurfaceCalc;

    ASSERT_THROW(figureSurfaceCalc.fnCalculateSurfaceCylinderSide(r, h),
    std::invalid_argument);
}

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Cylinder_Full) {
    double r = 2.0, h = -3.0;
    FigureSurface figureSurfaceCalc;

    ASSERT_THROW(figureSurfaceCalc.fnCalculateSurfaceCylinderFull(r, h),
    std::invalid_argument);
}

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Cone_Side) {
    double r = 0.0, l = 3.0;
    FigureSurface figureSurfaceCalc;

    ASSERT_THROW(figureSurfaceCalc.fnCalculateSurfaceConeSide(r, l),
    std::invalid_argument);
}

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Cone_Full) {
    double r = 2.0, l = -3.0;
    FigureSurface figureSurfaceCalc;

    ASSERT_THROW(figureSurfaceCalc.fnCalculateSurfaceConeFull(r, l),
    std::invalid_argument);
}

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Sphere) {
    double r = -2.0;
    FigureSurface figureSurfaceCalc;

    ASSERT_THROW(figureSurfaceCalc.fnCalculateSurfaceSphere(r),
    std::invalid_argument);
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Parallelepiped) {
  double a = 2.0, b = 3.0, c = 2.5, resApproximate = 37.0;
  FigureSurface figureSurfaceCalc;

  ASSERT_NO_THROW(figureSurfaceCalc.fnCalculateSurfaceParallelepiped(a, b, c));
  ASSERT_LE(
  figureSurfaceCalc.fnCalculateSurfaceParallelepiped(a, b, c) - resApproximate,
      0.001);
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Cylinder_Side) {
    double r = 6.0, h = 1.4, resApproximate = 52.992;
    FigureSurface figureSurfaceCalc;

    ASSERT_NO_THROW(figureSurfaceCalc.fnCalculateSurfaceCylinderSide(r, h));
    ASSERT_LE(
    figureSurfaceCalc.fnCalculateSurfaceCylinderSide(r, h) - resApproximate,
    0.001);
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Cylinder_Full) {
    double r = 2.1, h = 10.3, resApproximate = 164.196;
    FigureSurface figureSurfaceCalc;

    ASSERT_NO_THROW(figureSurfaceCalc.fnCalculateSurfaceCylinderFull(r, h));
    ASSERT_LE(
    figureSurfaceCalc.fnCalculateSurfaceCylinderFull(r, h) - resApproximate,
    0.001);
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Cone_Side) {
    double r = 1.4, l = 3.7, resApproximate = 16.436;
    FigureSurface figureSurfaceCalc;

    ASSERT_NO_THROW(figureSurfaceCalc.fnCalculateSurfaceConeSide(r, l));
    ASSERT_LE(
    figureSurfaceCalc.fnCalculateSurfaceConeSide(r, l) - resApproximate,
    0.001);
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Cone_Full) {
    double r = 2.3, l = 3.7, resApproximate = 43.353;
    FigureSurface figureSurfaceCalc;

    ASSERT_NO_THROW(figureSurfaceCalc.fnCalculateSurfaceConeFull(r, l));
    ASSERT_LE(
    figureSurfaceCalc.fnCalculateSurfaceConeFull(r, l) - resApproximate,
    0.001);
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Sphere) {
    double r = 2.0, resApproximate = 50.265;
    FigureSurface figureSurfaceCalc;

    ASSERT_NO_THROW(figureSurfaceCalc.fnCalculateSurfaceSphere(r));
    ASSERT_LE(
    figureSurfaceCalc.fnCalculateSurfaceSphere(r) - resApproximate,
    0.001);
}
