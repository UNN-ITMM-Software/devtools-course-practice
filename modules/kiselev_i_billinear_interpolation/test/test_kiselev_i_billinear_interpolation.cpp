// Copyright 2024 Kiselev Igor

#include <gtest/gtest.h>
#include <vector>

#include "include/Billinear_interpolation.h"
#include "include/Color.h"

TEST(Kiselev_Igor_Billinear_interpolation_test,
    test_color_constructors_and_getters) {
    Color c1 = Color(12, 23, 34);
    Color c2 = Color(c1);
    ASSERT_EQ(c1.getR(), 12);
    ASSERT_EQ(c1.getG(), 23);
    ASSERT_EQ(c1.getB(), 34);
    ASSERT_EQ(c2.getR(), 12);
    ASSERT_EQ(c2.getG(), 23);
    ASSERT_EQ(c2.getB(), 34);
}

TEST(Kiselev_Igor_Billinear_interpolation_test, test_color_setters) {
    Color c1 = Color(0, 0, 0);
    Color c2 = Color(0, 0, 0);
    c1.setR(12);
    c1.setG(23);
    c1.setB(34);
    c2.setColor(12, 23, 34);
    ASSERT_EQ(c1.getR(), 12);
    ASSERT_EQ(c1.getG(), 23);
    ASSERT_EQ(c1.getB(), 34);
    ASSERT_EQ(c2.getR(), 12);
    ASSERT_EQ(c2.getG(), 23);
    ASSERT_EQ(c2.getB(), 34);
}

TEST(Kiselev_Igor_Billinear_interpolation_test,
    test_billinear_interpolation_constructors) {
    std::vector<std::vector<Color>> v(2, std::vector<Color>
        (2, Color(0, 0, 0)));
    ASSERT_NO_THROW(BillinearInterpolation bi1 = BillinearInterpolation(v));
    BillinearInterpolation bi1 = BillinearInterpolation(v);
    BillinearInterpolation bi2 = BillinearInterpolation(v);
    ASSERT_NO_THROW(BillinearInterpolation bi3 = BillinearInterpolation(bi1));
    ASSERT_NO_THROW(BillinearInterpolation bi4 = bi1);
    ASSERT_NO_THROW(bi2 = bi1);
}

TEST(Kiselev_Igor_Billinear_interpolation_test, test_twoCore_is_no_fall) {
    std::vector<std::vector<Color>> v(3, std::vector<Color>
        (3, Color(0, 0, 0)));
    BillinearInterpolation bi1 = BillinearInterpolation(v);
    ASSERT_NO_THROW(bi1.twoCore());
}

TEST(Kiselev_Igor_Billinear_interpolation_test, test_twoCore_is_correct) {
    std::vector<std::vector<Color>> v(2, std::vector<Color>
        (2, Color(40, 40, 40)));
    v[1][1] = Color(60, 60, 60);
    v[1][0] = Color(50, 50, 50);
    v[0][1] = Color(50, 50, 50);
    BillinearInterpolation bi1 = BillinearInterpolation(v);
    std::vector<std::vector<Color>> ans(1, std::vector<Color>
        (1, Color(50, 50, 50)));
    std::vector<std::vector<Color>> res = bi1.twoCore();
    ASSERT_EQ(ans[0][0].getR(), res[0][0].getR());
    ASSERT_EQ(res[0][0].getG(), ans[0][0].getG());
    ASSERT_EQ(res[0][0].getB(), ans[0][0].getB());
}

TEST(Kiselev_Igor_Billinear_interpolation_test, test_threeCore_is_no_throw) {
    std::vector<std::vector<Color>> v(3, std::vector<Color>
        (3, Color(0, 0, 0)));
    BillinearInterpolation bi1 = BillinearInterpolation(v);
    ASSERT_NO_THROW(bi1.threeCore());
}

TEST(Kiselev_Igor_Billinear_interpolation_test, test_threeCore_is_correct) {
    std::vector<std::vector<Color>> v(3, std::vector<Color>
        (3, Color(0, 0, 0)));
    v[2][2] = Color(60, 60, 60);
    v[2][0] = Color(50, 50, 50);
    v[0][2] = Color(50, 50, 50);
    v[0][0] = Color(40, 40, 40);
    BillinearInterpolation bi1 = BillinearInterpolation(v);
    int ans = 50;
    std::vector<std::vector<Color>> res = bi1.threeCore();
    ASSERT_EQ(ans, res[1][1].getR());
    ASSERT_EQ(res[1][1].getG(), ans);
    ASSERT_EQ(res[1][1].getB(), ans);
}
