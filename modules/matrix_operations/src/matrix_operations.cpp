// Copyright 2021 Kiseleva Anastasia

#include<vector>
#include "include/matrix_operations.h"

Matrix::Matrix(unsigned int row, unsigned int col) {
    rows = row;
    cols = col;
    if ((row != 0) && (col != 0)) {
        data.resize(row);
        for (unsigned int i = 0; i < row; i++) {
            data[i].resize(col);
            for (unsigned int j = 0; j < col; j++)
                data[i][j] = 0;
        }
    } else {
        throw "Wrong size";
    }
}

Matrix::~Matrix() {}

Matrix::Matrix(const Matrix& tmp) {
    rows = tmp.rows;
    cols = tmp.cols;
    data = tmp.data;
}

Matrix Matrix::operator*(const Matrix& A) const {
    Matrix res(rows, A.cols);
    if (cols == A.rows) {
        for (unsigned int i = 0; i < rows; i++) {
            for (unsigned int j = 0; j < A.cols; j++) {
                double c = 0.0;
                for (unsigned int k = 0; k < cols; k++) {
                    c += data[i][k] * A.data[k][j];
                }
                res[i][j] = c;
            }
        }
    } else {
        throw "Wrong size";
    }
    return res;
}

Matrix Matrix::operator* (const double tmp) const {
    Matrix res(rows, cols);
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            res[i][j] = data[i][j] * tmp;
        }
    }
    return res;
}

Matrix Matrix::operator/ (const double tmp) const {
    Matrix res(rows, cols);
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            res[i][j] = data[i][j] / tmp;
        }
    }
    return res;
}

std::vector<double> Matrix::operator*(const std::vector<double>& tmp) const {
    std::vector<double> res(rows);
    if (tmp.size() == cols) {
        for (unsigned int i = 0; i < rows; i++) {
           double c = 0.0;
            for (unsigned int j = 0; j < cols; j++) {
                c += data[i][j] * tmp[j];
            }
            res[i] = c;
        }
    } else {
        throw "Wrong size";
    }
    return res;
}

Matrix Matrix::operator+(const Matrix& A) const {
    Matrix res(rows, cols);
    if ((rows == A.rows) && (cols == A.cols)) {
        for (unsigned int i = 0; i < rows; i++) {
            for (unsigned int j = 0; j < cols; j++) {
                res[i][j] = data[i][j] + A.data[i][j];
            }
        }
    } else {
        throw "Wrong size";
    }
    return res;
}

Matrix Matrix::operator-(const Matrix& A) const {
    Matrix res(rows, cols);
    if ((rows == A.rows) && (cols == A.cols)) {
        for (unsigned int i = 0; i < rows; i++) {
            for (unsigned int j = 0; j < cols; j++) {
                res[i][j] = data[i][j] - A.data[i][j];
            }
        }
    } else {
        throw "Wrong size";
    }
    return res;
}

Matrix& Matrix::operator=(const Matrix& A) {
    if (this == &A) return *this;
    rows = A.rows;
    cols = A.cols;
    data = A.data;
    return *this;
}

bool Matrix::operator==(const Matrix& tmp) const {
    if (cols != tmp.cols || rows != tmp.rows) {
        return false;
    }
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            if (data[i][j] != tmp.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

std::vector<double>& Matrix::operator[](unsigned int k) {
    if ((k >= 0) && (k <= rows)) {
        return data[k];
    } else {
        throw - 1;
    }
}

void Matrix::set_data(const std::vector < std::vector < double>>& new_data) {
    data = new_data;
    rows = data.size();
    cols = data[0].size();
}

Matrix Matrix::Get_Transpose() const {
    Matrix res(cols, rows);
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            if (i != j) {
                res[j][i] = data[i][j];
            } else {
                res[i][j] = data[i][j];
            }
        }
    }
    return res;
}

int Matrix::Get_Rows() const {
    return rows;
}

int Matrix::Get_Cols() const {
    return cols;
}

Matrix Matrix::GetMatrWithout_i_row_j_col(unsigned int i,
    unsigned int j) const {
    Matrix res(rows - 1, rows - 1);
    unsigned int ki, kj, di;
    di = 0;
    for (ki = 0; ki < rows - 1; ki++) {
        if (ki == i) {
            di = 1;
        }
       int dj = 0;
        for (kj = 0; kj < rows - 1; kj++) {
            if (kj == j) {
                dj = 1;
            }
            res[ki][kj] = data[ki + di][kj + dj];
        }
    }
    return res;
}

double Matrix::Determinant() const {
    if (rows == cols) {
        int k;
        double res = 0.0;
        k = 1;
        if (rows == 1) {
            res = data[0][0];
            return res;
        }
        if (rows == 2) {
            res = data[0][0] * data[1][1] - (data[1][0] * data[0][1]);
            return res;
        }
        if (rows > 2) {
            for (unsigned int i = 0; i < rows; i++) {
                Matrix c(rows - 1, rows - 1);
                c = this->GetMatrWithout_i_row_j_col(i, 0);
                res = res + k * data[i][0] * c.Determinant();
                k = -k;
            }
        }
        return res;
    } else {
        throw "Wrong size";
    }
}

void Matrix::Inverse() {
    if (rows == cols) {
        double deter = this->Determinant();
        if (deter != 0) {
            Matrix transp(rows, rows);
            transp = this->Get_Transpose();
            Matrix allied(rows, rows);
            Matrix c(rows - 1, rows - 1);
            for (unsigned int i = 0; i < rows; i++) {
                for (unsigned int j = 0; j < rows; j++) {
                    c = transp.GetMatrWithout_i_row_j_col(i, j);
                    if ((j + i + 1) % 2 == 0) {
                        allied[i][j] = c.Determinant() * (-1);
                    } else {
                        allied[i][j] = c.Determinant();
                    }
                }
            }
            for (unsigned int i = 0; i < rows; i++) {
                for (unsigned int j = 0; j < rows; j++) {
                    data[i][j] = allied[i][j] / deter;
                }
            }
        } else {
            throw "Wrong matrix";
        }
    } else {
        throw "Wrong size";
    }
}
