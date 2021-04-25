// Copyright 2021 Kiseleva Anastasia

#ifndef MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_OPERATIONS_H_
#define MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_OPERATIONS_H_

#include<vector>
#include<cmath>

class Matrix {
 private:
    unsigned int rows;

    unsigned int cols;

    std::vector<std::vector<double>> data;


 public:
    Matrix(unsigned int row, unsigned int col);

    ~Matrix() {}

    Matrix(const Matrix& tmp);

    void set_data(std::vector < std::vector < double>> new_data);

    std::vector<double>& operator[](unsigned int k);

    Matrix operator*(Matrix A);

    Matrix operator* (double tmp);

    Matrix operator/ (double tmp);

    std::vector<double> operator*(std::vector<double> tmp);

    Matrix operator+(Matrix A);

    Matrix operator-(Matrix A);

    Matrix* operator=(Matrix A);

    bool operator==(const Matrix& tmp) const;

    int Get_Rows();

    int Get_Cols();

    Matrix Transpose();

    Matrix GetMatrWithout_i_row_j_cols(unsigned int i, unsigned int j);

    double Determinant();

    void Inverse();
};

#endif  // MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_OPERATIONS_H_
