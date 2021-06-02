// Copyright 2021 Kuznetsov Nikita

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/bit_array_application.h"
#include "include/bit_array.h"

std::string BitArrayApplication::help(const std::string& filename) const {
  return "This is an application of bit array.\n\n" \
    "Please provide arguments in one of two formats:\nFormat 1:\n$ " +
    filename + " <size_of_array>\n\n" \
    "Format 2:\n$ " + filename + " <not_null_elements>\n\n" \
    "Where <size_of_vector> is one integer positive number, " \
    "\n<not_null_elements> are sequence of numbers of an array" \
    "Example1: " + filename + " 5\n" \
    "Example2: " + filename + " 0 4 5 7\n";
}

bool BitArrayApplication::validateNumberOfArguments(int argc,
  const char* argv[]) const {
  if (argc <= 1) {
    return false;
  }
  return true;
}

int BitArrayApplication::retPositiveNumber(const char* argv) const {
  std::stringstream convert(argv);
  int result;
  if (!(convert >> result))
    throw std::runtime_error("ERROR: " + std::string(argv) +
      " is invalid argument\n\n");
  if (result <= 0)
    throw std::runtime_error("ERROR: " + std::string(argv) +
      " is not positive number\n\n");
  return result;
}

std::string BitArrayApplication::operator()(int argc,
  const char* argv[]) const {
  try {
    if (!validateNumberOfArguments(argc, argv)) {
      return help(argv[0]);
    } else if (argc == 2) {
      int size = retPositiveNumber(argv[1]);
      BitArray arr(size);

      for (int i = 0; i < size; ++i)
        arr.SetBit(i);

      std::ostringstream stream;
      std::vector<uint> memMask(size);

      for (int i = 0; i < size; ++i)
        memMask[i] = arr.GetBit(i);

      stream << "Bit array: ";
      for (size_t i = 0; i < memMask.size(); ++i) {
        stream << memMask[i];
      }

      return stream.str();
    } else {
      int size = argc - 1;
      std::vector<uint> not_null;

      for (int i = 0; i < size; i++) {
        std::stringstream convert(argv[i + 1]);
        int num;
        if (!(convert >> num)) {
          throw std::runtime_error("ERROR: " +
            std::string(argv[i + 1]) + " is invalid argument\n\n");
        }
        not_null.push_back(num);
      }

      uint max = 0;
      for (size_t i = 0; i < not_null.size(); ++i) {
        if (not_null[i] > max)
          max = not_null[i];
      }

      BitArray arr(max + 1);
      for (size_t i = 0; i < max + 1; ++i) {
        for (size_t j = 0; j < not_null.size(); ++j) {
          if (i == not_null[j]) {
            arr.SetBit(i);
          }
        }
      }

      std::ostringstream stream;
      std::vector<uint> memMask(max + 1);

      for (size_t i = 0; i < max + 1; ++i)
        memMask[i] = arr.GetBit(i);

      stream << "Bit array: ";
      for (size_t i = 0; i < memMask.size(); ++i) {
        stream << memMask[i];
      }

      return stream.str();
    }
  } catch(const std::exception& e) {
    return e.what() + help(argv[0]);
  }
}
