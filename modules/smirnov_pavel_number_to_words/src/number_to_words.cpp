// Copyright 2024 Smirnov Pavel

#include "include/number_to_words.h"

#include <string>

std::string NumberToWords::convert(int number) {
  if (number == 0) {
    return "zero";
  }

  std::string result;

  if (number < 0) {
    result += "negative ";
    number = -number;
  }

  if (number >= 1000000000) {
    result += convert(number / 1000000000) + " billion ";
    number %= 1000000000;
  }

  if (number >= 1000000) {
    result += convert(number / 1000000) + " million ";
    number %= 1000000;
  }

  if (number >= 1000) {
    result += convert(number / 1000) + " thousand ";
    number %= 1000;
  }

  result += convertLessThanOneThousand(number);

  return result;
}

std::string NumberToWords::convertLessThanOneThousand(int number) {
  std::string result;

  if (number >= 100) {
    result += convertLessThanOneThousand(number / 100) + " hundred ";
    number %= 100;
  }

  if (number >= 20) {
    switch (number / 10) {
      case 2:
        result += "twenty ";
        break;
      case 3:
        result += "thirty ";
        break;
      case 4:
        result += "forty ";
        break;
      case 5:
        result += "fifty ";
        break;
      case 6:
        result += "sixty ";
        break;
      case 7:
        result += "seventy ";
        break;
      case 8:
        result += "eighty ";
        break;
      case 9:
        result += "ninety ";
        break;
    }
    number %= 10;
  }

  switch (number) {
    case 1:
      result += "one";
      break;
    case 2:
      result += "two";
      break;
    case 3:
      result += "three";
      break;
    case 4:
      result += "four";
      break;
    case 5:
      result += "five";
      break;
    case 6:
      result += "six";
      break;
    case 7:
      result += "seven";
      break;
    case 8:
      result += "eight";
      break;
    case 9:
      result += "nine";
      break;
    case 10:
      result += "ten";
      break;
    case 11:
      result += "eleven";
      break;
    case 12:
      result += "twelve";
      break;
    case 13:
      result += "thirteen";
      break;
    case 14:
      result += "fourteen";
      break;
    case 15:
      result += "fifteen";
      break;
    case 16:
      result += "sixteen";
      break;
    case 17:
      result += "seventeen";
      break;
    case 18:
      result += "eighteen";
      break;
    case 19:
      result += "nineteen";
      break;
  }

  return result;
}
