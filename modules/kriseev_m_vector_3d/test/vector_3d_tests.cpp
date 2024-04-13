// Copyright 2024 Kriseev Mikhail
#include <gtest/gtest.h>

#include "include/vector_3d.h"

TEST(KriseevM_Vector3d, getX_correct) {
  // Arrange
  double x = 2.0;
  double y = 3.0;
  double z = 4.0;
  Vector3d vector(x, y, z);
  // Act
  double actualValue = vector.getX();
  // Assert
  ASSERT_EQ(x, actualValue);
}
TEST(KriseevM_Vector3d, getY_correct) {
  // Arrange
  double x = 2.0;
  double y = 3.0;
  double z = 4.0;
  Vector3d vector(x, y, z);
  // Act
  double actualValue = vector.getY();
  // Assert
  ASSERT_EQ(y, actualValue);
}
TEST(KriseevM_Vector3d, getZ_correct) {
  // Arrange
  double x = 2.0;
  double y = 3.0;
  double z = 4.0;
  Vector3d vector(x, y, z);
  // Act
  double actualValue = vector.getZ();
  // Assert
  ASSERT_EQ(z, actualValue);
}
TEST(KriseevM_Vector3d, getNorm_from_valid_vector_correct) {
  // Arrange
  double x = 2.0;
  double y = 2.0;
  double z = 1.0;
  double norm = 3.0;
  Vector3d vector(x, y, z);
  // Act
  double actualValue = vector.getNorm();
  // Assert
  ASSERT_NEAR(norm, actualValue, 1e-9);
}
TEST(KriseevM_Vector3d, getNorm_from_unit_vector_correct) {
  // Arrange
  double x = 0.0;
  double y = 0.0;
  double z = 1.0;
  double norm = 1.0;
  Vector3d vector(x, y, z);
  // Act
  double actualValue = vector.getNorm();
  // Assert
  ASSERT_NEAR(norm, actualValue, 1e-9);
}
TEST(KriseevM_Vector3d, getNorm_from_zero_vector_correct) {
  // Arrange
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
  double norm = 0.0;
  Vector3d vector(x, y, z);
  // Act
  double actualValue = vector.getNorm();
  // Assert
  ASSERT_NEAR(norm, actualValue, 1e-9);
}

TEST(KriseevM_Vector3d, getNormalizedVector_valid_vector_correct) {
  // Arrange
  double x = 2.0;
  double y = 3.0;
  double z = 4.0;
  double expectedNorm = 1.0;
  Vector3d vector(x, y, z);
  // Act
  double actualNorm = vector.getNormalizedVector().getNorm();
  // Assert
  ASSERT_NEAR(expectedNorm, actualNorm, 1e-9);
}
TEST(KriseevM_Vector3d, getNormalizedVector_unit_vector_unchanged) {
  // Arrange
  double x = 1.0;
  double y = 0.0;
  double z = 0.0;
  Vector3d vector(x, y, z);
  // Act
  Vector3d normalizedVector = vector.getNormalizedVector();
  // Assert
  ASSERT_EQ(normalizedVector, vector);
}
TEST(KriseevM_Vector3d, getNormalizedVector_zero_vector_throws) {
  // Arrange
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
  Vector3d vector(x, y, z);
  // Act & Assert (?)
  ASSERT_ANY_THROW(vector.getNormalizedVector());
}
TEST(KriseevM_Vector3d, dotProduct_correct) {
  // Arrange
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  double x2 = 4.0;
  double y2 = 3.0;
  double z2 = 2.0;
  Vector3d vector1{x1, y1, z1};
  Vector3d vector2{x2, y2, z2};
  double expectedDotProduct = 25.0;
  // Act
  double actualDotProduct = vector1.dotProduct(vector2);
  // Assert
  ASSERT_NEAR(expectedDotProduct, actualDotProduct, 1e-9);
}
TEST(KriseevM_Vector3d, crossProduct_collinear_vectors_correct) {
  // Arrange
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  double x2 = -4.0;
  double y2 = -6.0;
  double z2 = -8.0;
  Vector3d vector1{x1, y1, z1};
  Vector3d vector2{x2, y2, z2};
  double expectedX = 0.0;
  double expectedY = 0.0;
  double expectedZ = 0.0;
  Vector3d expectedCrossProduct{expectedX, expectedY, expectedZ};
  // Act
  Vector3d actualCrossProduct = vector1.crossProduct(vector2);
  // Assert
  ASSERT_EQ(expectedCrossProduct, actualCrossProduct);
}
TEST(KriseevM_Vector3d, crossProduct_non_collinear_vectors_correct) {
  // Arrange
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  double x2 = 4.0;
  double y2 = 3.0;
  double z2 = 2.0;
  Vector3d vector1{x1, y1, z1};
  Vector3d vector2{x2, y2, z2};
  double expectedX = -6.0;
  double expectedY = 12.0;
  double expectedZ = -6.0;
  Vector3d expectedCrossProduct{expectedX, expectedY, expectedZ};
  // Act
  Vector3d actualCrossProduct = vector1.crossProduct(vector2);
  // Assert
  ASSERT_EQ(expectedCrossProduct, actualCrossProduct);
}
TEST(KriseevM_Vector3d, division_operator_correct) {
  // Arrange
  double factor = 2.0;
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  Vector3d vector{x1, y1, z1};
  double expectedX = 1.0;
  double expectedY = 1.5;
  double expectedZ = 2.0;
  Vector3d expected{expectedX, expectedY, expectedZ};
  // Act
  Vector3d actual = vector / factor;
  // Assert
  ASSERT_EQ(expected, actual);
}
TEST(KriseevM_Vector3d, multiply_operator_correct) {
  // Arrange
  double factor = 2.0;
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  Vector3d vector{x1, y1, z1};
  double expectedX = 4.0;
  double expectedY = 6.0;
  double expectedZ = 8.0;
  Vector3d expected{expectedX, expectedY, expectedZ};
  // Act
  Vector3d actual = vector * factor;
  // Assert
  ASSERT_EQ(expected, actual);
}
TEST(KriseevM_Vector3d, addition_operator_correct) {
  // Arrange
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  double x2 = 4.0;
  double y2 = 3.0;
  double z2 = 2.0;
  Vector3d vector1{x1, y1, z1};
  Vector3d vector2{x2, y2, z2};
  double expectedX = 6.0;
  double expectedY = 6.0;
  double expectedZ = 6.0;
  Vector3d expected{expectedX, expectedY, expectedZ};
  // Act
  Vector3d actual = vector1 + vector2;
  // Assert
  ASSERT_EQ(expected, actual);
}

TEST(KriseevM_Vector3d, subtraction_operator_correct) {
  // Arrange
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  double x2 = 4.0;
  double y2 = 3.0;
  double z2 = 2.0;
  Vector3d vector1{x1, y1, z1};
  Vector3d vector2{x2, y2, z2};
  double expectedX = -2.0;
  double expectedY = 0.0;
  double expectedZ = 2.0;
  Vector3d expected{expectedX, expectedY, expectedZ};
  // Act
  Vector3d actual = vector1 - vector2;
  // Assert
  ASSERT_EQ(expected, actual);
}

TEST(KriseevM_Vector3d, equality_operator_equal_correct) {
  // Arrange
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  double x2 = 2.0;
  double y2 = 3.0;
  double z2 = 4.0;
  Vector3d vector1{x1, y1, z1};
  Vector3d vector2{x2, y2, z2};
  // Act
  bool actual = vector1 == vector2;
  // Assert
  ASSERT_TRUE(actual);
}
TEST(KriseevM_Vector3d, equality_operator_non_equal_correct) {
  // Arrange
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  double x2 = 4.0;
  double y2 = 3.0;
  double z2 = 2.0;
  Vector3d vector1{x1, y1, z1};
  Vector3d vector2{x2, y2, z2};
  // Act
  bool actual = vector1 == vector2;
  // Assert
  ASSERT_FALSE(actual);
}
TEST(KriseevM_Vector3d, non_equality_operator_equal_correct) {
  // Arrange
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  double x2 = 2.0;
  double y2 = 3.0;
  double z2 = 4.0;
  Vector3d vector1{x1, y1, z1};
  Vector3d vector2{x2, y2, z2};
  // Act
  bool actual = vector1 != vector2;
  // Assert
  ASSERT_FALSE(actual);
}
TEST(KriseevM_Vector3d, non_equality_operator_non_equal_correct) {
  // Arrange
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  double x2 = 4.0;
  double y2 = 3.0;
  double z2 = 2.0;
  Vector3d vector1{x1, y1, z1};
  Vector3d vector2{x2, y2, z2};
  // Act
  bool actual = vector1 != vector2;
  // Assert
  ASSERT_TRUE(actual);
}
TEST(KriseevM_Vector3d, division_operator_division_by_zero_throws) {
  // Arrange
  double factor = 0.0;
  double x1 = 2.0;
  double y1 = 3.0;
  double z1 = 4.0;
  Vector3d vector{x1, y1, z1};
  double expectedX = 1.0;
  double expectedY = 1.5;
  double expectedZ = 2.0;
  Vector3d expected{expectedX, expectedY, expectedZ};
  // Act & Assert (?)
  ASSERT_ANY_THROW(vector / factor);
}
