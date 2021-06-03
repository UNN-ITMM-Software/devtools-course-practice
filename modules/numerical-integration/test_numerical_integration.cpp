// Copyright 2021 Tareev Daniil

#define _USE_MATH_DEFINES

#include <gtest/gtest.h>
#include <cmath>

#include "include/numerical_integration.h"

class func1 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return x * x;
     }
};

class func2 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return 1.0 - x;
     }
};

class func3 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return cos(x);
     }
};

class NumericalIntegrationTest : public NumericalIntegration {
 public:
     static const double epsilon;
     static const unsigned int N;

     static double F1(double x) {
         return (x * x * x) / 3.0;
     }

     static double F2(double x) {
         return x - (x * x) / 2.0;
     }

     static double F3(double x) {
         return sin(x);
     }
};

const double NumericalIntegrationTest::epsilon = 0.001;
const unsigned int NumericalIntegrationTest::N = 100000;

TEST(NumericalIntegrationTest, CannotCreateObjectWithInvalidBorders) {
    // Arrange
    double a = 5.0;
    double b = 3.0;

    // Act & Assert
    ASSERT_ANY_THROW(NumericalIntegration obj(a, b));
}

TEST(NumericalIntegrationTest, CopyConstructorTest) {
    // Arrange
    double a = 0.0;
    double b = 1.0;

    // Act
    NumericalIntegration obj1(a, b);
    NumericalIntegration obj2(obj1);

    // Assert
    EXPECT_EQ(obj1, obj2);
}

TEST(NumericalIntegrationTest, EqualityOperatorTest) {
    // Arrange
    double a1 = 1.0;
    double b1 = 5.2;
    double a2 = 3.0;
    double b2 = 4.3;

    // Act
    NumericalIntegration obj1(a1, b1);
    NumericalIntegration obj2(a2, b2);
    obj2 = obj1;

    // Assert
    EXPECT_EQ(obj1, obj2);
}

TEST(NumericalIntegrationTest, SetAndGetIntegrationBordersTest) {
    // Arrange
    double a1 = 0.0;
    double b1 = 1.0;
    double a2 = 5.3;
    double b2 = 6.0;

    // Act
    NumericalIntegration obj(a1, b1);
    obj.Set_integration_borders(a2, b2);

    // Assert
    EXPECT_DOUBLE_EQ(a2, obj.Get_left_border());
    EXPECT_DOUBLE_EQ(b2, obj.Get_right_border());
}

TEST(NumericalIntegrationTest, TestLeftRectangleMethod) {
    // Arrange
    double a = 0.0;
    double b = 3.0;
    double ans = NumericalIntegrationTest::F1(b) -
    NumericalIntegrationTest::F1(a);

    // Act
    NumericalIntegration obj(a, b);
    func1 f;

    // Assert
    EXPECT_NEAR(ans, obj.Left_rectangle_method(&f,
    NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}

TEST(NumericalIntegrationTest, TestRightRectangleMethod) {
    // Arrange
    double a = M_PI / 4.0;
    double b = M_PI / 2.0;
    double ans = NumericalIntegrationTest::F3(b) -
    NumericalIntegrationTest::F3(a);

    // Act
    NumericalIntegration obj(a, b);
    func3 f;

    // Assert
    EXPECT_NEAR(ans, obj.Right_rectangle_method(&f,
    NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}

TEST(NumericalIntegrationTest, TestMiddleRectangleMethod) {
    // Arrange
    double a = 2.0;
    double b = 4.0;
    double ans = NumericalIntegrationTest::F2(b) -
    NumericalIntegrationTest::F2(a);

    // Act
    NumericalIntegration obj(a, b);
    func2 f;

    // Assert
    EXPECT_NEAR(ans, obj.Middle_rectangle_method(&f,
    NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}

TEST(NumericalIntegrationTest, TestTrapezoidMethod) {
    // Arrange
    double a = -1.0;
    double b = 5.0;
    double ans = NumericalIntegrationTest::F1(b) -
    NumericalIntegrationTest::F1(a);

    // Act
    NumericalIntegration obj(a, b);
    func1 f;

    // Assert
    EXPECT_NEAR(ans, obj.Trapezoid_method(&f,
    NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}

TEST(NumericalIntegrationTest, TestSimpsonsMethod) {
    // Arrange
    double a = 4.0;
    double b = 7.0;
    double ans = NumericalIntegrationTest::F2(b) -
    NumericalIntegrationTest::F2(a);

    // Act
    NumericalIntegration obj(a, b);
    func2 f;

    // Assert
    EXPECT_NEAR(ans, obj.Simpsons_method(&f,
        NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}

TEST(NumericalIntegrationTest, TestGaussMethod) {
    // Arrange
    double a = M_PI / 6.0;
    double b = M_PI / 3.0;
    double ans = NumericalIntegrationTest::F3(b) -
    NumericalIntegrationTest::F3(a);

    // Act
    NumericalIntegration obj(a, b);
    func3 f;

    // Assert
    EXPECT_NEAR(ans, obj.Gauss_method(&f,
        NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}