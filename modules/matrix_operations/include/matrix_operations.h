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

    Matrix(const Matrix& tmp);

    ~Matrix();

    void set_data(const std::vector<std::vector< double>>& new_data);

    std::vector<double>& operator[](unsigned int k);

    Matrix operator*(const Matrix& A) const;

    Matrix operator* (const double tmp) const;

    Matrix operator/ (const double tmp) const;

    std::vector<double> operator*(const std::vector<double>& tmp) const;

    Matrix operator+(const Matrix& A) const;

    Matrix operator-(const Matrix& A) const;

    Matrix& operator=(const Matrix& A);

    bool operator==(const Matrix& tmp) const;

    int Get_Rows() const;

    int Get_Cols() const;

    Matrix Get_Transpose() const;

    Matrix GetMatrWithout_i_row_j_col(unsigned int i, unsigned int j) const;

    double Determinant() const;

    void Inverse();
};

#endif  // MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_OPERATIONS_H_
