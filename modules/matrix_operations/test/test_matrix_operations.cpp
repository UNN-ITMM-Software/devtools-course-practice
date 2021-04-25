// Copyright 2021 Kiseleva Anastasia

#include <gtest/gtest.h>
#include<limits>
#include<vector>
#include "include/matrix_operations.h"

const double EPSILON = std::numeric_limits<double>::epsilon() * 100;

TEST(KISELEVA_MATRIX_OPERATIONS, Get_rows_and_cols) {
    Matrix res(4, 4);

    ASSERT_TRUE(res.Get_Cols() == res.Get_Rows());
}

TEST(KISELEVA_MATRIX_OPERATIONS, Size_zero) {
    ASSERT_ANY_THROW(Matrix(0, 3));
}

TEST(KISELEVA_MATRIX_OPERATIONS, Set_data__brackets__comparison) {
    Matrix one(2, 2);
    Matrix two(2, 2);
    bool res;

    one[0][0] = 4;
    one[0][1] = 5;
    one[1][0] = 1;
    one[1][1] = -1;

    two.set_data({ {4, 5}, {1, -1} });
    res = (one == two);

    ASSERT_TRUE(res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, brackets__THROW) {
    Matrix one(2, 2);

    ASSERT_ANY_THROW(one[-1][0]);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Multiplication_of_two_matrices_THROW) {
    Matrix one(4, 8);
    Matrix two(10, 5);
    Matrix three(8, 10);

    ASSERT_ANY_THROW(three = one*two);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Equality_of_two_matrices) {
    Matrix one(2, 3);
    Matrix two(2, 3);

    one.set_data({ {1, 2, 1}, {4, 1, 2} });

    two = one;

    ASSERT_EQ(one, two);
}
TEST(KISELEVA_MATRIX_OPERATIONS, Multiplication_of_two_matrices) {
    Matrix one(2, 3);
    Matrix two(3, 2);
    Matrix exept(2, 2);
    Matrix res(2, 2);

    one.set_data({ {1, 2, 1}, {4, 1, 2} });
    two.set_data({ {2, 2}, {1, 5}, {0, 4} });
    exept.set_data({ {4, 16}, {9, 21} });

    res = one * two;

    ASSERT_EQ(exept, res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Multiplication_of_double_and_matrix) {
    Matrix one(2, 3);
    Matrix exept(2, 3);
    double tmp = 3;
    Matrix res(2, 3);

    one.set_data({ {1, 2, 1}, {4, 1, 2} });
    exept.set_data({ {3, 6, 3}, {12, 3, 6} });

    res = one * tmp;

    ASSERT_EQ(exept, res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Multiplication_of_vector_and_matrix_THROW) {
    Matrix one(2, 3);
    std::vector<double> two = { 1, 5 };
    std::vector<double> res(2);

    ASSERT_ANY_THROW(res = one * two);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Multiplication_of_vector_and_matrix) {
    Matrix one(2, 3);
    std::vector<double> two(3);
    std::vector<double> exept(2);
    std::vector<double> res(2);

    one.set_data({ {1, 2, 1}, {4, 1, 2} });
    two = { 3, 2, -2 };
    exept = { 5, 10 };

    res = one * two;

    ASSERT_EQ(exept, res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Division_of_double_and_matrix) {
    Matrix one(2, 3);
    Matrix exept(2, 3);
    double tmp = 3;
    Matrix res(2, 3);

    exept.set_data({ {1, 2, 1}, {4, 1, 2} });
    one.set_data({ {3, 6, 3}, {12, 3, 6} });

    res = one / tmp;

    ASSERT_EQ(exept, res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Sum_of_two_matrix_THROW) {
    Matrix one(2, 3);
    Matrix two(4, 2);
    Matrix res(2, 2);

    ASSERT_ANY_THROW(res = one + two);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Sum_of_two_matrix) {
    Matrix one(2, 3);
    Matrix res(2, 3);
    Matrix two(2, 3);
    Matrix exept(2, 3);

    one.set_data({ {1, 2, 1}, {4, 1, 2} });
    two.set_data({ {3, 6, 3}, {12, 3, 6} });
    exept.set_data({ {4, 8, 4}, {16, 4, 8} });

    res = one + two;

    ASSERT_EQ(exept, res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Subtraction_of_two_matrix_THROW) {
    Matrix one(2, 3);
    Matrix two(4, 2);
    Matrix res(2, 2);

    ASSERT_ANY_THROW(res = one - two);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Subtraction_of_two_matrix) {
    Matrix one(2, 3);
    Matrix res(2, 3);
    Matrix two(2, 3);
    Matrix exept(2, 3);

    one.set_data({ {1, 2, 1}, {4, 1, 2} });
    two.set_data({ {3, 6, 3}, {12, 3, 6} });
    exept.set_data({ {-2, -4, -2}, {-8, -2, -4} });

    res = one - two;

    ASSERT_EQ(exept, res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Transpose_of_matrix) {
    Matrix one(2, 3);
    Matrix res(3, 2);
    Matrix exept(3, 2);

    one.set_data({ {1, 2, 1}, {4, 1, 2} });
    exept.set_data({ {1, 4}, {2, 1}, {1, 2} });

    res = one.Transpose();

    ASSERT_EQ(exept, res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Get_Matrix_Without_i_row_j_col) {
    Matrix one(3, 3);
    Matrix exept(2, 2);
    Matrix res(2, 2);

    one.set_data({ { 1, 1, 1 }, { 2, 2, 2 }, { 3, 3, 3 } });
    exept.set_data({ {2, 2}, {3, 3} });

    res = one.GetMatrWithout_i_row_j_cols(0, 0);

    ASSERT_EQ(exept, res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Determinant_THROW) {
    Matrix one(4, 8);

    ASSERT_ANY_THROW(one.Determinant());
}

TEST(KISELEVA_MATRIX_OPERATIONS, Determinant_of_1x1) {
    Matrix one(1, 1);
    double exept;
    double res;

    one.set_data({ {1} });
    exept = 1;

    res = one.Determinant();

    ASSERT_DOUBLE_EQ(exept, res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Determinant_of_2x2) {
    Matrix one(2, 2);
    double exept;
    double res;

    one.set_data({ {1, 2}, {1, -3} });
    exept = -5;

    res = one.Determinant();

    ASSERT_DOUBLE_EQ(exept, res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Determinant_of_3x3) {
    Matrix one(3, 3);
    double exept;
    double res;

    one.set_data({ { 1, -2, 0 }, { 4, 5, 6 }, { 1, 2, 7 } });
    exept = 67;

    res = one.Determinant();

    ASSERT_DOUBLE_EQ(exept, res);
}

TEST(KISELEVA_MATRIX_OPERATIONS, Inverse_THROW_1) {
    Matrix one(4, 8);

    ASSERT_ANY_THROW(one.Inverse());
}

TEST(KISELEVA_MATRIX_OPERATIONS, Inverse_THROW_2) {
    Matrix one(2, 2);

    one.set_data({ { 1, 1 }, { 1, 1 } });

    ASSERT_ANY_THROW(one.Inverse());
}

TEST(KISELEVA_MATRIX_OPERATIONS, Inverse_matrix) {
    Matrix one(3, 3);
    Matrix two(3, 3);
    Matrix exept(3, 3);
    Matrix res(3, 3);

    one.set_data({ { 1, 4, -2 }, { 5, 2, 3 }, { 2, 7, 2 } });
    exept.set_data({ { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 1.0 } });
    two = one;

    one.Inverse();
    res = two * one;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_NEAR(exept[i][j], res[i][j], EPSILON);
        }
    }
}
