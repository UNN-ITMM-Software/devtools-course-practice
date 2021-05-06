// Copyright 2021 Panova Olga

#include <gtest/gtest.h>
#include "include/3d_shapes_volume.h"

TEST(PANOVA_SHAPES_VOLUME, Cube_Wrong_Data) {
    Cube bad(0, 0, 0, -2);

    ASSERT_ANY_THROW(bad.Volume());
}

TEST(PANOVA_SHAPES_VOLUME, Sphere_Wrong_Data) {
    Sphere bad(0, 0, 0, 0);

    ASSERT_ANY_THROW(bad.Volume());
}

TEST(PANOVA_SHAPES_VOLUME, Cone_Wrong_Data) {
    Cone bad(0, 0, 0, -1, -3.23);

    ASSERT_ANY_THROW(bad.BaseArea());
}

TEST(PANOVA_SHAPES_VOLUME, Parall_ed_Wrong_Data) {
    Parallelepiped bad(0, 0, 0, 1, -1, 1);

    ASSERT_ANY_THROW(bad.Volume());
}

TEST(PANOVA_SHAPES_VOLUME, Prism_Wrong_Data) {
    Prism bad(0, 0, 0, 2, -2, 0);

    ASSERT_ANY_THROW(bad.BaseArea());
}

TEST(PANOVA_SHAPES_VOLUME, Pyramid_Wrong_Data) {
    Pyramid bad(0, 0, 0, -1, -2, -3);

    ASSERT_ANY_THROW(bad.BaseArea());
}

TEST(PANOVA_SHAPES_VOLUME, Torus_Wrong_Data) {
    Torus bad(0, 0, 0, 3, -2);

    ASSERT_ANY_THROW(bad.Volume());
}

TEST(PANOVA_SHAPES_VOLUME, Frustum_Wrong_Data) {
    Frustum bad(0, 0, 0, 1, 3, 0);

    ASSERT_ANY_THROW(bad.Volume());
}

TEST(PANOVA_SHAPES_VOLUME, Calculate_Cube_Volume) {
    // Arrange
    double side = 1.1;
    double true_volume = 1.331;

    // Act
    Cube shape(1, 2, 3, side);
    double volume = shape.Volume();

    // Assert
    ASSERT_DOUBLE_EQ(true_volume, volume);
}

TEST(PANOVA_SHAPES_VOLUME, Calculate_Sphere_Volume) {
    // Arrange
    double radius = 1.2;
    double true_volume = 7.23823;

    // Act
    Sphere shape(3, 2, 1, radius);
    double volume = shape.Volume();
    volume = round(volume * 100000) / 100000;

    // Assert
    ASSERT_DOUBLE_EQ(true_volume, volume);
}

TEST(PANOVA_SHAPES_VOLUME, Calculate_Cone_Volume) {
    // Arrange
    double base_radius = 1.3;
    double h = 2.3;
    double true_volume = 4.07046;

    // Act
    Cone shape(1, 0, 4, base_radius, h);
    double volume = shape.Volume();
    volume = round(volume * 100000) / 100000;

    // Assert
    ASSERT_DOUBLE_EQ(true_volume, volume);
}

TEST(PANOVA_SHAPES_VOLUME, Calculate_Parall_ed_Volume) {
    // Arrange
    double length = 4.18, width = 2.77, h = 2.95;
    double true_volume = 34.15687;

    // Act
    Parallelepiped shape(0, 0, 0, length, width, h);
    double volume = shape.Volume();

    // Assert
    ASSERT_DOUBLE_EQ(true_volume, volume);
}

TEST(PANOVA_SHAPES_VOLUME, Calculate_Prism_Volume) {
    // Arrange
    double side = 13.01, h = 5.39;
    int n = 5;
    double true_volume = 147.13815;

    // Act
    Prism shape(0, 0, 0, side, h, n);
    double volume = shape.Volume();
    volume = round(volume * 100000) / 100000;

    // Assert
    ASSERT_DOUBLE_EQ(true_volume, volume);
}

TEST(PANOVA_SHAPES_VOLUME, Calculate_Pyramid_Volume) {
    // Arrange
    double side = 2.09, h = 4.86;
    int n = 9;
    double true_volume = 7.11693;

    // Act
    Pyramid shape(0, 0, 0, side, h, n);
    double volume = shape.Volume();
    volume = round(volume * 100000) / 100000;

    // Assert
    ASSERT_DOUBLE_EQ(true_volume, volume);
}

TEST(PANOVA_SHAPES_VOLUME, Calculate_Torus_Volume) {
    // Arrange
    double d = 10.87, r = 3.51;
    double true_volume = 2643.46472;

    // Act
    Torus shape(0, 0, 0, d, r);
    double volume = shape.Volume();
    volume = round(volume * 100000) / 100000;

    // Assert
    ASSERT_DOUBLE_EQ(true_volume, volume);
}

TEST(PANOVA_SHAPES_VOLUME, Calculate_Frustum_Volume) {
    // Arrange
    double R = 1.01, r = 6.4, h = 7.3;
    double true_volume = 370.33296;

    // Act
    Frustum shape(0, 0, 0, r, R, h);
    double volume = shape.Volume();
    volume = round(volume * 100000) / 100000;

    // Assert
    ASSERT_DOUBLE_EQ(true_volume, volume);
}

