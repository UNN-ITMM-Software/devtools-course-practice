// Copyright 2021 Kiseleva Anastasia

#include<vector>
#include "include/matrix_operations.h"

Matrix::Matrix(int row, int col) {
    rows = row;
    cols = col;
    if ((row != 0) && (col != 0)) {
        data.resize(row);
        for (int i = 0; i < row; i++) {
            data[i].resize(col);
            for (int j = 0; j < col; j++)
                data[i][j] = 0;
        }
    } else {
        throw "Wrong size";
    }
}

Matrix::Matrix(const Matrix& tmp) {
    rows = tmp.rows;
    cols = tmp.cols;
    data = tmp.data;
}

Matrix Matrix::operator*(Matrix A) {
    Matrix res(rows, A.cols);
    if (cols == A.rows) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < A.cols; j++) {
                double c = 0.0;
                for (int k = 0; k < cols; k++) {
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

Matrix Matrix::operator* (double tmp) {
    Matrix res(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = data[i][j] * tmp;
        }
    }
    return res;
}

Matrix Matrix::operator/ (double tmp) {
    Matrix res(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = data[i][j] / tmp;
        }
    }
    return res;
}

std::vector<double> Matrix::operator*(std::vector<double> tmp) {
    std::vector<double> res(rows);
    if (tmp.size() == cols) {
        double c;
        for (int i = 0; i < rows; i++) {
            c = 0.0;
            for (int j = 0; j < cols; j++) {
                c += data[i][j] * tmp[j];
            }
            res[i] = c;
        }
    } else {
        throw "Wrong size";
    }
    return res;
}

Matrix Matrix::operator+(Matrix A) {
    Matrix res(rows, cols);
    if ((rows == A.rows) && (cols == A.cols)) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[i][j] = data[i][j] + A.data[i][j];
            }
        }
    } else {
        throw "Wrong size";
    }
    return res;
}

Matrix Matrix::operator-(Matrix A) {
    Matrix res(rows, cols);
    if ((rows == A.rows) && (cols == A.cols)) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[i][j] = data[i][j] - A.data[i][j];
            }
        }
    } else {
        throw "Wrong size";
    }
    return res;
}

Matrix* Matrix::operator=(Matrix A) {
    rows = A.rows;
    cols = A.cols;
    data = A.data;
    return this;
}

bool Matrix::operator==(const Matrix& tmp) const {
    if (cols != tmp.cols || rows != tmp.rows) {
        return false;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] != tmp.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

std::vector<double>& Matrix::operator[](int k) {
    if ((k >= 0) && (k <= rows)) {
        return data[k];
    } else {
        throw - 1;
    }
}

void Matrix::set_data(std::vector < std::vector < double>> new_data) {
    data = new_data;
    rows = data.size();
    cols = data[0].size();
}

Matrix Matrix::Transpose() {
    Matrix res(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i != j) {
                res[j][i] = data[i][j];
            } else {
                res[i][j] = data[i][j];
            }
        }
    }
    return res;
}

int Matrix::Get_Rows() {
    return rows;
}

int Matrix::Get_Cols() {
    return cols;
}

Matrix Matrix::GetMatrWithout_i_row_j_cols(int i, int j) {
    Matrix res(rows - 1, rows - 1);
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki < rows - 1; ki++) {
        if (ki == i) {
            di = 1;
        }
        dj = 0;
        for (kj = 0; kj < rows - 1; kj++) {
            if (kj == j) {
                dj = 1;
            }
            res[ki][kj] = data[ki + di][kj + dj];
        }
    }
    return res;
}

double Matrix::Determinant() {
    if (rows == cols) {
        int i, n, k;
        double res = 0.0;
        j = 0;
        k = 1;
        if (rows < 1) {
            throw "Wrong matrix";
        }
        if (rows == 1) {
            res = data[0][0];
            return res;
        }
        if (rows == 2) {
            res = data[0][0] * data[1][1] - (data[1][0] * data[0][1]);
            return res;
        }
        if (rows > 2) {
            for (i = 0; i < rows; i++) {
                Matrix c(rows - 1, rows - 1);
                c = this->GetMatrWithout_i_row_j_cols(i, 0);
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
            transp = this->Transpose();
            Matrix allied(rows, rows);
            Matrix c(rows - 1, rows - 1);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < rows; j++) {
                    c = transp.GetMatrWithout_i_row_j_cols(i, j);
                    if ((j + i + 1) % 2 == 0) {
                        allied[i][j] = c.Determinant() * (-1);
                    } else {
                        allied[i][j] = c.Determinant();
                    }
                }
            }
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < rows; j++) {
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
