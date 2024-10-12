// Copyright 2024 Smirnov Pavel

#include "include/number_to_words.h"

#include <sstream>
#include <string>

std::string NumberToWords::convert(int number) {
  std::stringstream ss;

  if (number == 0) {
    return "zero";
  }

  if (number < 0) {
    ss << "negative ";
    number = -number;
  }

  if (number >= 1000000000) {
    ss << convert(number / 1000000000) << " billion ";
    number %= 1000000000;
  }

  if (number >= 1000000) {
    ss << convert(number / 1000000) << " million ";
    number %= 1000000;
  }

  if (number >= 1000) {
    ss << convert(number / 1000) << " thousand ";
    number %= 1000;
  }

  ss << convertLessThanOneThousand(number);

  return ss.str();
}

std::string NumberToWords::convertLessThanOneThousand(int number) {
  std::stringstream ss;

  if (number >= 100) {
    ss << convertLessThanOneThousand(number / 100) << " hundred ";
    number %= 100;
  }

  if (number >= 20) {
    switch (number / 10) {
      case 2:
        ss << "twenty ";
        break;
      case 3:
        ss << "thirty ";
        break;
      case 4:
        ss << "forty ";
        break;
      case 5:
        ss << "fifty ";
        break;
      case 6:
        ss << "sixty ";
        break;
      case 7:
        ss << "seventy ";
        break;
      case 8:
        ss << "eighty ";
        break;
      case 9:
        ss << "ninety ";
        break;
    }
    number %= 10;
  }

  switch (number) {
    case 1:
      ss << "one";
      break;
    case 2:
      ss << "two";
      break;
    case 3:
      ss << "three";
      break;
    case 4:
      ss << "four";
      break;
    case 5:
      ss << "five";
      break;
    case 6:
      ss << "six";
      break;
    case 7:
      ss << "seven";
      break;
    case 8:
      ss << "eight";
      break;
    case 9:
      ss << "nine";
      break;
    case 10:
      ss << "ten";
      break;
    case 11:
      ss << "eleven";
      break;
    case 12:
      ss << "twelve";
      break;
    case 13:
      ss << "thirteen";
      break;
    case 14:
      ss << "fourteen";
      break;
    case 15:
      ss << "fifteen";
      break;
    case 16:
      ss << "sixteen";
      break;
    case 17:
      ss << "seventeen";
      break;
    case 18:
      ss << "eighteen";
      break;
    case 19:
      ss << "nineteen";
      break;
  }

  return ss.str();
}

