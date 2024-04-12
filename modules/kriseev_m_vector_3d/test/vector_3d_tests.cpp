// Copyright 2024 Kriseev Mikhail
#include <gtest/gtest.h>

#include "include/vector_3d.h"

TEST(Vector3d, getX_correct) {
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
TEST(Vector3d, getY_correct) {
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
TEST(Vector3d, getZ_correct) {
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
TEST(Vector3d, getNorm_from_valid_vector_correct) {
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
TEST(Vector3d, getNorm_from_unit_vector_correct) {
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
TEST(Vector3d, getNorm_from_zero_vector_correct) {
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

TEST(Vector3d, getNormalizedVector_valid_vector_correct) {
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
TEST(Vector3d, getNormalizedVector_unit_vector_unchanged) {
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
TEST(Vector3d, getNormalizedVector_zero_vector_throws) {
  // Arrange
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
  Vector3d vector(x, y, z);
  // Act & Assert (?)
  ASSERT_ANY_THROW(vector.getNormalizedVector());
}
