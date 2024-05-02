// Copyright 2024 Shubin Mikhail

#include <sstream>

#include "include/application.hpp"
#include "include/tmatrix.h"

#define REQ_ARGC 5

std::string MatOpsApplication::Parse(int argc, char *argv[]) {
  if (Validate(argc, argv)) {
    size_t size = 0;
    std::string string1;
    std::string string2;
    std::string string3;
    std::string string4;
    std::string string5;
    string1 = argv[1];  // size
    size = std::stoi(string1);

    double *matrix_array1 = new double[size * size];
    double *matrix_array2;
    TDynamicMatrix<double> matrix1(size);
    TDynamicMatrix<double> matrix2(size);

    string3 = argv[2];  // mat1
    std::istringstream iss(string3);
    std::string s;

    size_t i = 0;
    while (getline(iss, s, ' ')) {
      try {
        matrix_array1[i] = std::stod(s);
      } catch (...) {
        Help(argv[0], "Invalid matrix1 input.");
        return message_;
      }
      i++;
    }
    if (i != size * size) {
      Help(argv[0], "Invalid matrix1 size.");
      return message_;
    }
    for (size_t j = 0; j < size; j++) {
      for (size_t k = 0; k < size; k++) {
        matrix1[j][k] = matrix_array1[j * size + k];
      }
    }

    if (argc == REQ_ARGC) {
      string5 = argv[4];  // mat2
      matrix_array2 = new double[size * size];
      iss = std::istringstream(string5);

      i = 0;
      while (getline(iss, s, ' ')) {
        try {
          matrix_array2[i] = std::stod(s);
        } catch (...) {
          Help(argv[0], "Invalid matrix2 input.");
          return message_;
        }
        i++;
      }
      if (i != size * size) {
        Help(argv[0], "Invalid matrix2 size.");
        return message_;
      }
      for (size_t j = 0; j < size; j++) {
        for (size_t k = 0; k < size; k++) {
          matrix2[j][k] = matrix_array2[j * size + k];
        }
      }
    }

    string4 = argv[3];  // op
    TDynamicMatrix<double> matrix_res;
    double double_res;
    std::ostringstream msg_stream;
    switch (string4[0]) {
    case '+':
      matrix_res = matrix1 + matrix2;
      msg_stream << "matrix1: "
             << matrix1 << " matrix2: "
             << matrix2 << " result (sum): "
             << matrix_res << std::endl;
      break;
    case '-':
      matrix_res = matrix1 - matrix2;
      msg_stream << "matrix1: "
             << matrix1 << " matrix2: "
             << matrix2 << " result (sub): "
             << matrix_res << std::endl;
      break;
    case '*':
      matrix_res = matrix1 * matrix2;
      msg_stream << "matrix1: "
             << matrix1 << " matrix2: "
             << matrix2 << " result (mult): "
             << matrix_res << std::endl;
      break;
    case 'i':
      matrix_res = matrix1.findInverse();
      msg_stream << "matrix: "
             << matrix1 << " result (inverse): "
             << matrix_res << std::endl;
      break;
    case 'd':
      double_res = matrix1.findDeterm();
      msg_stream << "matrix: "
             << matrix1 << " result (det): "
             << double_res << std::endl;
      break;
    default:
      Help(argv[0], "Unknown operation.");
      return message_;
      break;
    }

    message_ = msg_stream.str();
  }

  return message_;
}

bool MatOpsApplication::Validate(int argc, char *argv[]) {
  std::string help_str("--help");
  if (argc == 1) {
    Help(argv[0]);
    return false;
  } else if (help_str.compare(argv[1]) == 0) {
    Help(argv[0]);
    return false;
  } else if (argc != REQ_ARGC && argc != REQ_ARGC - 1) {
    Help(argv[0], "Invalid number of arguments.");
    return false;
  }
  return true;
}

void MatOpsApplication::Help(const char *application, const char *message) {
  std::stringstream _message;

  if (message) {
    _message << "Error: " << message << '\n';
  } else {
    _message << "This is a matrix calculator.\n";
  }
  _message << "Usage:\n";
  _message << '\t' << application << " <size> <first matrix>"
    " <operation> <second matrix>\n";
  _message << "Where:\n";
  _message << '\t' << "<size> is the size of the matrix.\n";
  _message << '\t' << "<first matrix>, <second matrix> are input matrices.\n";
  _message << '\t' << "<operation> is operation over matrix/ces"
    " (+ (sum), - (sub), * (mult), i (inversion), d (determiant)).\n";
  message_ = _message.str();
}
