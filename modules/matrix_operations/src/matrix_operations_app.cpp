// Copyright 2021 Novozhilova Ekaterina

#include "include/matrix_operations.h"
#include "include/matrix_operations_app.h"

#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>

MyApplication::MyApplication() : message_("") {}

void MyApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a matrix calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname +
          " <number of rows of original matrix>" +
          " <number of columns of original matrix" +
          " <original matrix's elements>" +
          " <specify type of the second argument: " +
          "<number> or <matrix> or <none>" +
          " <number of elements if matrix and one number " +
          "if number and nothing if none>" +
           " <operation>\n\n" +

          "<operation> is one of the listed:\n " +
          "'*' for both matrix-number and matrix-matrix\n " +
          "'+' for two matrices\n " +
          "'/' for matrix and number\n " +
          "'-' for two matrices\n " +
          "'transpose' for a single matrix\n " +
          "'determinant' for a single matrix\n " +
          "'inverse' for a single matrix\n";
}

bool MyApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else {
        int or_rows_, or_cols_;
        or_rows_  = std::atoi(argv[1]);
        or_cols_  = std::atoi(argv[2]);
        int check = or_rows_ * or_cols_;
        if (check + 3 > argc) {
            help(argv[0],
            "ERROR: Invalid input of the original matrix.\n\n");
            return false;
        }
        unsigned int or_rows = static_cast<unsigned int>(or_rows_);
        unsigned int or_cols = static_cast<unsigned int>(or_cols_);
        if ((or_rows == 0) || (or_cols == 0)) {
            help(argv[0], "ERROR: Invalid dimension size.\n\n");
            return false;
        }
        unsigned int first_arg_num = or_rows * or_cols + 3;
        unsigned int supp_argc = 0;
        unsigned int argc_uns = static_cast<unsigned int>(argc);
        if (strcmp(argv[first_arg_num], "matrix") == 0) {
            int ad_rows_  = std::atoi(argv[first_arg_num + 1]);
            int ad_cols_  = std::atoi(argv[first_arg_num + 2]);
            unsigned int ad_rows = static_cast<unsigned int>(ad_rows_);
            unsigned int ad_cols = static_cast<unsigned int>(ad_cols_);
            if ((ad_rows == 0) || (ad_cols == 0)) {
                help(argv[0],
                "ERROR: Invalid dimension size of second matrix.\n\n");
                return false;
            }
            supp_argc = first_arg_num + 1 + 2 + ad_rows * ad_cols + 1;
            if (supp_argc != argc_uns) {
                help(argv[0],
                "ERROR: Invalid number of arguments for second matrix.\n\n");
                return false;
            }
        } else if (strcmp(argv[first_arg_num], "number") == 0) {
            supp_argc = first_arg_num + 1 + 2;
            if (supp_argc != argc_uns) {
                help(argv[0], "ERROR: Invalid number of arguments.\n\n");
                return false;
            }
        } else if (strcmp(argv[first_arg_num], "none") == 0) {
            supp_argc = first_arg_num + 1 + 1;
            if (supp_argc != argc_uns) {
                help(argv[0], "ERROR: Invalid number of arguments.\n\n");
                return false;
            }
        }
    }
    return true;
}

std::string MyApplication::parseOperation(const char* arg) {
    std::vector<std::string> ops =
    { "inverse", "transpose", "determinant", "/", "*", "+", "-" };
    auto result = std::find(std::begin(ops), std::end(ops), std::string(arg));
    if (result != std::end(ops)) {
        return std::string(arg);
    } else {
        return message_ = "error";
    }
}

std::string MyApplication::parseSecondType(const char* arg) {
    if (strcmp(arg, "matrix") == 0) {
        return ("matrix");
    } else if (strcmp(arg, "none") == 0) {
        return ("none");
    } else if (strcmp(arg, "number") == 0) {
        return ("number");
    }
    return message_ =
    "ERROR: Invalid type of second argument.";
}
std::string MyApplication::operator()(int argc, const char** argv) {
    std::string s_type;
    std::vector<std::vector<double>> arr;
    std::vector<std::vector<double>> ad_arr;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    std::ostringstream stream;
    double num = 0;
    int or_rows_  = std::atoi(argv[1]);
    int or_cols_  = std::atoi(argv[2]);
    unsigned int or_rows = static_cast<unsigned int>(or_rows_);
    unsigned int or_cols = static_cast<unsigned int>(or_cols_);
    unsigned int ad_rows;
    unsigned int ad_cols;

    arr.resize(or_rows);
    for (unsigned int i = 0; i < or_rows; i++) {
        arr[i].resize(or_cols);
    }
    int k = 0;
    try {
        for (unsigned int i = 0; i < or_rows; i++) {
            for (unsigned int j = 0; j < or_cols; j++) {
                arr[i][j] = std::stof(argv[3 + k]);
                k++;
            }
        }
    }
    catch(...) {
        help(argv[0]);
        return message_ = "ERROR: Invalid elements of matrix.";
    }
    int type_ind = or_rows * or_cols + 3;
    s_type = parseSecondType(argv[type_ind]);
    std::string op;
    if (s_type == "matrix") {
        int ad_rows_, ad_cols_;
        ad_rows_  = std::atoi(argv[type_ind + 1]);
        ad_cols_  = std::atoi(argv[type_ind + 2]);
        ad_rows = static_cast<unsigned int>(ad_rows_);
        ad_cols = static_cast<unsigned int>(ad_cols_);
        ad_arr.resize(ad_rows);
        for (unsigned int i = 0; i < ad_rows; i++) {
            ad_arr[i].resize(ad_cols);
        }
        k = 0;
        try {
            for (unsigned int i = 0; i < ad_rows; i++) {
                for (unsigned int j = 0; j < ad_cols; j++) {
                    ad_arr[i][j] = std::stof(argv[type_ind + 3 + k]);
                    k++;
                }
            }
        }
        catch(...) {
            help(argv[0]);
            return message_ = "ERROR: Invalid elements of second matrix.";
        }
        op = parseOperation(argv[type_ind + 3 + ad_rows * ad_cols]);
        if (op == "error") {
            return message_ =
            "ERROR: Invalid operation";
        }
        if ((op != "+") && (op != "*") && (op != "-")) {
            return message_ =
            "ERROR: Wrong second type or wrong operation.";
        }
    } else if (s_type == "number") {
        try {
            num = std::stof(argv[type_ind + 1]);
        }
        catch(...) {
            help(argv[0]);
            return message_ = "ERROR: Invalid number.";
        }
        op = parseOperation(argv[type_ind + 2]);
        if (op == "error") {
            return message_ =
            "ERROR: Invalid operation";
        }
        if ((op != "*") && (op != "/")) {
            return message_ =
            "ERROR: Wrong second type or wrong operation.";
        }
    } else if (s_type == "none") {
        op = parseOperation(argv[type_ind + 1]);
        if (op == "error") {
            return message_ =
            "ERROR: Invalid operation";
        }
        if ((op != "transpose") &&
            (op != "inverse") &&
            (op != "determinant")) {
                return message_ =
                "ERROR: Wrong second type or wrong operation.";
            }
    } else { return s_type; }

    Matrix m_1(or_rows, or_cols);
    m_1.set_data(arr);
    Matrix m_2(1, 1);
    if (s_type == "matrix") {
        Matrix tmp(ad_rows, ad_cols);
        tmp.set_data(ad_arr);
        m_2 = tmp;
    }

    Matrix res_m(1, 1);
    double res_num;
    unsigned int res_rows;
    unsigned int res_cols;
    if (op == "+") {
        if ((or_rows != ad_rows) || (or_cols != ad_cols)) {
            return message_ =
            "ERROR: Invalid matrix sizes for the current operation.";
        }
        res_m = m_1 + m_2;
        res_rows = res_m.Get_Rows();
        res_cols = res_m.Get_Cols();
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << res_m[i][j] << " ";
            }
        }
        stream << std::endl << std::endl;
        stream << "Res is " << std::endl;
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << res_m[i][j] << " ";
            }
            stream << std::endl;
        }
    } else if (op == "*") {
        if (s_type == "number") {
            res_m = m_1 * num;
        } else if (s_type == "matrix") {
            if ((or_rows != ad_cols) || (or_cols != ad_rows)) {
                return message_ =
                "ERROR: Invalid matrix sizes for the current operation.";
            }
            res_m = m_1 * m_2;
        }
        res_rows = res_m.Get_Rows();
        res_cols = res_m.Get_Cols();
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << res_m[i][j] << " ";
            }
        }
        stream << std::endl << std::endl;
        stream << "Res is " << std::endl;
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << res_m[i][j] << " ";
            }
            stream << std::endl;
        }
    } else if (op == "-") {
        res_m = m_1 - m_2;
        res_rows = res_m.Get_Rows();
        res_cols = res_m.Get_Cols();
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << res_m[i][j] << " ";
            }
        }
        stream << std::endl << std::endl;
        stream << "Res is " << std::endl;
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << res_m[i][j] << " ";
            }
            stream << std::endl;
        }
    } else if (op == "/") {
        res_m = m_1 / num;
        res_rows = res_m.Get_Rows();
        res_cols = res_m.Get_Cols();
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << res_m[i][j] << " ";
            }
        }
        stream << std::endl << std::endl;
        stream << "Res is " << std::endl;
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << res_m[i][j] << " ";
            }
            stream << std::endl;
        }
    } else if (op =="transpose") {
        res_m = m_1.Get_Transpose();
        res_rows = res_m.Get_Rows();
        res_cols = res_m.Get_Cols();
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << res_m[i][j] << " ";
            }
        }
        stream << std::endl << std::endl;
        stream << "Res is " << std::endl;
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << res_m[i][j] << " ";
            }
            stream << std::endl;
        }
    } else if (op == "determinant") {
        if (or_rows != or_cols) {
            return message_ =
            "ERROR: The matrix must be square.";
        }
        res_num = m_1.Determinant();
        stream << "Determinant is " << res_num << std::endl;
    } else if (op == "inverse") {
        if (or_rows != or_cols) {
            return message_ =
            "ERROR: The matrix must be square.";
        }
        m_1.Inverse();
        res_rows = m_1.Get_Rows();
        res_cols = m_1.Get_Cols();
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << m_1[i][j] << " ";
            }
        }
        stream << std::endl << std::endl;
        stream << "Res is " << std::endl;
        for (unsigned int i = 0; i < res_rows; i++) {
            for (unsigned int j = 0; j < res_cols; j++) {
                stream << m_1[i][j] << " ";
            }
            stream << std::endl;
        }
    }

    message_ = stream.str();

    return message_;
}
