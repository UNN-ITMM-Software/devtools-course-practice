// Copyright 2021 Ikromov Inom

#include <gtest/gtest.h>
#include <string>
#include "include/conways_game_of_life.h"

TEST(Conways_life, Do_Throw_When_Wrong_Sizes) {
    // Arrange
    int widht = 0;
    int heigth = 2;

    // Act & Assert
    EXPECT_THROW(Conways_life z(widht, heigth), std::string);
}

TEST(Conways_life, Can_Get_Widht) {
    // Arrange
    Conways_life zz(1, 2);

    // Act
    int w = zz.getW();

    // Assert
    EXPECT_EQ(1, w);
}
TEST(Conways_life, Can_Get_Heigth) {
    // Arrange
    Conways_life zy(1, 2);

    // Act
    int h = zy.getH();

    // Assert
    EXPECT_EQ(2, h);
}
TEST(Conways_life, Do_Throw_When_Put_Wrong_Point) {
    // Arrange
    Conways_life zx(1, 2);

    // Act & Assert
    EXPECT_THROW(zx.putStart(0, -1), std::string);
}
TEST(Conways_life, Can_Put_Point) {
    // Arrange
    Conways_life zx(1, 2);

    // Act
    zx.putStart(0, 0);

    // Assert
    EXPECT_EQ(zx.getPoint(0, 0), "+");
}
TEST(Conways_life, Can_create_field) {
    // Arrange
    int widht = 1;
    int heigth = 2;

    // Act
    Conways_life zc(widht, heigth);

    // Assert
    EXPECT_EQ(widht, zc.getW());
    EXPECT_EQ(heigth, zc.getH());
}
TEST(Conways_life, Can_Redraw) {
    // Arrange
    Conways_life zc(4, 4);
    zc.putStart(1, 0);
    zc.putStart(1, 1);
    zc.putStart(1, 2);

    // Act
    zc.stepNextField();

    // Assert
    EXPECT_EQ(zc.getPoint(1, 0), ".");
    EXPECT_EQ(zc.getPoint(1, 1), "+");
}
TEST(Conways_life, Can_Check_Alive_Next) {
    // Arrange
    Conways_life zc(4, 4);
    zc.putStart(1, 0);
    zc.putStart(1, 1);
    zc.putStart(1, 2);

    // Act
    bool check = zc.aliveNextStep(1, 0);

    // Assert
    EXPECT_EQ(check, false);
}
TEST(Conways_life, Can_Check_Alive_System_Next) {
    // Arrange
    Conways_life zc(4, 4);
    Conways_life zx(4, 4);
    zc.putStart(1, 0);
    zc.putStart(1, 1);
    zc.putStart(1, 2);
    zc.stepNextField();
    zx.putStart(1, 1);
    zx.stepNextField();

    // Act
    bool check1 = zc.isSystemAlive();
    bool check2 = zx.isSystemAlive();

    // Assert
    EXPECT_EQ(check1, true);
    EXPECT_EQ(check2, false);
}
TEST(Conways_life, Check_Corners) {
    // Arrange
    Conways_life zc(3, 3);
    zc.putStart(2, 0);
    zc.putStart(0, 2);
    zc.putStart(2, 2);

    // Act
    zc.stepNextField();

    // Assert
    EXPECT_EQ(zc.getPoint(0, 0), "+");
    EXPECT_EQ(zc.getPoint(2, 0), "+");
    EXPECT_EQ(zc.getPoint(0, 2), "+");
    EXPECT_EQ(zc.getPoint(2, 2), "+");
    EXPECT_EQ(zc.getPoint(1, 1), "+");
}
TEST(Conways_life, Can_Start) {
    // Arrange
    Conways_life zc(5, 5);
    zc.putStart(1, 1);
    zc.putStart(2, 1);
    zc.putStart(3, 3);
    std::string os;

    // Act
    zc.Start(os, 1);

    // Assert
    EXPECT_EQ(zc.getPoint(2, 2), "+");
}