// Copyright 2024 Derun Andrey

#include <gtest/gtest.h>

#include "include/bisymmetric.h"

TEST(Derun_A_Bisymmetric, Default_Constructor) {
  ASSERT_NO_THROW(new BisymmetricMatrix<int>());
}

TEST(Derun_A_Bisymmetric, Parametric_Constructor_1) {
  int size = 10;
  ASSERT_NO_THROW(new BisymmetricMatrix<int>(10));
}

TEST(Derun_A_Bisymmetric, Parametric_Constructor_2) {
  auto m = BisymmetricMatrix<char>(
      {{'a', 'b', 'c'}, {'b', 'd', 'b'}, {'c', 'b', 'a'}});
  ASSERT_NO_THROW(new BisymmetricMatrix<char>(
      {{'a', 'b', 'c'}, {'b', 'd', 'b'}, {'c', 'b', 'a'}}));

  m.display();

  ASSERT_EQ(m.getElement(0, 0), 'a');
  ASSERT_EQ(m.getElement(0, 1), 'b');
  ASSERT_EQ(m.getElement(0, 2), 'c');

  ASSERT_EQ(m.getElement(1, 0), 'b');
  ASSERT_EQ(m.getElement(1, 1), 'd');
  ASSERT_EQ(m.getElement(1, 2), 'b');

  ASSERT_EQ(m.getElement(2, 0), 'c');
  ASSERT_EQ(m.getElement(2, 1), 'b');
  ASSERT_EQ(m.getElement(2, 2), 'a');
}

TEST(Derun_A_Bisymmetric, Parametric_Constructor_2_Exc) {
  ASSERT_ANY_THROW(new BisymmetricMatrix<char>(
      {{'a', 'b', 'c'}, {'b', 'd', 'e'}, {'c', 'e', 'f'}}));
}

TEST(Derun_A_Bisymmetric, Get_N) {
  auto m = BisymmetricMatrix<char>(
      {{'a', 'b', 'c'}, {'b', 'd', 'b'}, {'c', 'b', 'a'}});
  EXPECT_EQ(m.getN(), 3);
}

TEST(Derun_A_Bisymmetric, Set_Element) {
  auto m = BisymmetricMatrix<char>(
      {{'a', 'b', 'c'}, {'b', 'd', 'b'}, {'c', 'b', 'a'}});

  m.display();
  std::cout << "\n";
  m.setElement(0, 0, 'g');
  m.display();

  ASSERT_EQ(m.getElement(0, 0), 'g');
  ASSERT_EQ(m.getElement(2, 2), 'g');

  std::cout << "\n";
  m.setElement(2, 0, 'g');
  m.display();

  ASSERT_EQ(m.getElement(2, 0), 'g');
  ASSERT_EQ(m.getElement(0, 2), 'g');
}

TEST(Derun_A_Bisymmetric, Set_Element_Exc) {
  auto m = BisymmetricMatrix<char>(
      {{'a', 'b', 'c'}, {'b', 'd', 'b'}, {'c', 'b', 'a'}});
  ASSERT_ANY_THROW(m.setElement(10, 0, 'a'));
}

TEST(Derun_A_Bisymmetric, Get_Element_Exc) {
  auto m = BisymmetricMatrix<char>(
      {{'a', 'b', 'c'}, {'b', 'd', 'b'}, {'c', 'b', 'a'}});
  ASSERT_ANY_THROW(m.getElement(10, 0));
}
