// Copyright 2024 Vinokurov Ivan

#include <gtest/gtest.h>
#include "include/figure_surface.h"

TEST(Vinokurov_I_Figure_Surface, Default_Constructor_Works) {
    ASSERT_NO_THROW(new FigureSurface());
}

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Parallelepiped) {

    double a = 2.0, b = 3.0, c = 0.0;

    ASSERT_THROW(new fnCalculateSurfaceParallelepiped(a, b, c));
}

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Cylinder_Side) {
    double r = 0.0, h = 3.0;

    ASSERT_THROW(new fnCalculateSurfaceCylinderSide(r, h));
}

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Cylinder_Full) {
    double r = 2.0, h = -3.0;

    ASSERT_THROW(new fnCalculateSurfaceCylinderFull(r, h));
}

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Cone_Side) {
    double r = 0.0, l = 3.0;

    ASSERT_THROW(new fnCalculateSurfaceConeSide(r, l));
}

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Cone_Full) {
    double r = 2.0, l = -3.0;

    ASSERT_THROW(new fnCalculateSurfaceConeFull(r, l));
}

TEST(Vinokurov_I_Figure_Surface, Non_Valid_Arguements_Sphere) {
    double r = -2.0;

    ASSERT_THROW(new fnCalculateSurfaceSphere(r));
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Parallelepiped) {

    double a = 2.0, b = 3.0, c = 2.5, resApproximate = 37.0;

    ASSERT_NO_THROW(new fnCalculateSurfaceParallelepiped(a, b, c));
    ASSERT_LE(fnCalculateSurfaceParallelepiped(r) - resApproximate, 0.001)
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Cylinder_Side) {
    double r = 6.0, h = 1.4, resApproximate = 52.992;

    ASSERT_NO_THROW(new fnCalculateSurfaceCylinderSide(r, h));
    ASSERT_LE(fnCalculateSurfaceCylinderSide(r) - resApproximate, 0.001)
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Cylinder_Full) {
    double r = 2.1, h = 10.3, resApproximate = 164.196;

    ASSERT_NO_THROW(new fnCalculateSurfaceCylinderFull(r, h));
    ASSERT_LE(fnCalculateSurfaceCylinderFull(r) - resApproximate, 0.001)
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Cone_Side) {
    double r = 1.4, l = 3.7, resApproximate = 16.436;

    ASSERT_NO_THROW(new fnCalculateSurfaceConeSide(r, l));
    ASSERT_LE(fnCalculateSurfaceConeSide(r) - resApproximate, 0.001)
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Cone_Full) {
    double r = 2.3, l = 3.7, resApproximate = 42.588;

    ASSERT_NO_THROW(new fnCalculateSurfaceConeFull(r, l));
    ASSERT_LE(fnCalculateSurfaceConeFull(r) - resApproximate, 0.001)
}

TEST(Vinokurov_I_Figure_Surface, Valid_Arguements_Sphere) {
    double r = 2.0, resApproximate = 50.24;

    ASSERT_NO_THROW(new fnCalculateSurfaceSphere(r));
    ASSERT_LE(fnCalculateSurfaceSphere(r) - resApproximate, 0.001)
}
