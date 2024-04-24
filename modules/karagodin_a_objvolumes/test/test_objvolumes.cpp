// Copyright 2024 Karagodin Andrey

#include <gtest/gtest.h>
#include "include/objvolumes.h"

class Shape3DTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    sphere = new Sphere(2.0);
    cube = new Cube(2.0);
    cylinder = new Cylinder(2.0, 3.0);
  }

  virtual void TearDown() {
    delete sphere;
    delete cube;
    delete cylinder;
  }

  Sphere *sphere;
  Cube *cube;
  Cylinder *cylinder;
};

TEST_F(Shape3DTest, SphereConstructorTestZero) { EXPECT_ANY_THROW(Sphere(0)); }

TEST_F(Shape3DTest, CubeConstructorTestZero) { EXPECT_ANY_THROW(Cube(0)); }

TEST_F(Shape3DTest, CylinderConstructorTestZero) {
  EXPECT_ANY_THROW(Cylinder(0, 0));
}

TEST_F(Shape3DTest, SphereConstructorTestNegative) {
  EXPECT_ANY_THROW(Sphere(-75562));
}

TEST_F(Shape3DTest, CubeConstructorTestNegative) {
  EXPECT_ANY_THROW(Cube(-75443));
}

TEST_F(Shape3DTest, CylinderConstructorTestNegative) {
  EXPECT_ANY_THROW(Cylinder(-172, -365));
}

TEST_F(Shape3DTest, SphereVolumeTest) {
  EXPECT_NEAR(sphere->volume(), 33.51, 0.01);
}

TEST_F(Shape3DTest, CubeVolumeTest) { EXPECT_NEAR(cube->volume(), 8.0, 0.01); }

TEST_F(Shape3DTest, CylinderVolumeTest) {
  EXPECT_NEAR(cylinder->volume(), 37.69, 0.01);
}
