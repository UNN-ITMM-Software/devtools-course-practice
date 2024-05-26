// Copyright 2024 Martynov Aleksandr

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Martynov_Aleksandr_ComplexNumberTest, Can_Create) {
  double real_1 = 1.0;
  double imagine_1 = 8.0;

  ComplexNumber z1(real_1, imagine_1);
  EXPECT_EQ(real_1, z1.getRe());
  EXPECT_EQ(imagine_1, z1.getIm());
}

TEST(Martynov_Aleksandr_ComplexNumberTest, Can_Create_Zero) {
  double real_1 = 0.0;
  double imagine_1 = 0.0;

  ComplexNumber z1(real_1, imagine_1);
  EXPECT_EQ(real_1, z1.getRe());
  EXPECT_EQ(imagine_1, z1.getIm());
}


TEST(Martynov_Aleksandr_ComplexNumberTest, Add_Numbers) {
  double real_1 = 1.0;
  double imagine_1 = 8.0;
  double real_2 = 8.0;
  double imagine_2 = -3.0;

  ComplexNumber z1(real_1, imagine_1);
  ComplexNumber z2(real_2, imagine_2);
  ComplexNumber z3 = z1 + z2;

  EXPECT_EQ(real_1 + real_2, z3.getRe());
  EXPECT_EQ(imagine_1 + imagine_2, z3.getIm());
}


TEST(Martynov_Aleksandr_ComplexNumberTest, Divide_Numbers) {
  double r1 = 4.2;
  double i1 = 3.6;
  double r2 = 2;
  double i2 = 3.0;

  ComplexNumber z1(r1, i1);
  ComplexNumber z2(r2, i2);
  ComplexNumber z3 = z1 / z2;

  EXPECT_DOUBLE_EQ((r1 * r2 + i1 * i2) / (r2 * r2 + i2 * i2), z3.getRe());
  EXPECT_DOUBLE_EQ((i1 * r2 - r1 * i2) / (r2 * r2 + i2 * i2), z3.getIm());
}

TEST(Martynov_Aleksandr_ComplexNumberTest, Divide_by_zero) {
  double r1 = 4.2;
  double i1 = 3.6;
  double r2 = 0.0;
  double i2 = 0.0;

  ComplexNumber z1(r1, i1);
  ComplexNumber z2(r2, i2);
  ASSERT_ANY_THROW(z1 / z2);
}

TEST(Martynov_Aleksandr_ComplexNumberTest, Is_Equal) {
  double real_1 = 1.0;
  double imagine_1 = 8.0;
  double real_2 = 1.0;
  double imagine_2 = 8.0;

  ComplexNumber z1(real_1, imagine_1);
  ComplexNumber z2(real_2, imagine_2);
  ASSERT_TRUE(z1 == z2);
}
