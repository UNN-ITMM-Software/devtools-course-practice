  // Copyright 2024 Videneva Ekaterina

#include "include/euler_function.h"
#include <stdexcept>

// euler_function(int value) is equal to the
// number of natural numbers from the segment[1, value − 1]
// coprime to value
// Let fi(n) is euler_function(int value) then
// fi has the following properties:
// 1. fi(p) = p - 1, where p is prime number
// 2. fi(p^n) = p^n - p^(n-1), where p is prime number
// 3. fi(p1^n * k) = fi(p^n) * fi(k),
// where p is prime number, k is not divisible by number
// to find the value of the function,
// the decomposition of the number into prime factors is used
// that is fi(a) = fi(p1^(n1)*p2^(n2)*...*pm^(nm)) =
// fi(p1^(n1))*fi(p2^(n2))*...*fi(pm^(nm)), where a is composed number,
// p[i] is prime number, n[j] is natural number
int64_t euler_function(int64_t value) {
  // the euler function is defined for natural numbers
  if (value <= 0) throw std::runtime_error("value <= 0");

  int64_t n;
  int64_t numberOfCoprimeNumbers = 1;

  // Decomposition of a number into prime numbers.
  // If value is composite number, then its divisor
  // belongs to the segment [2,
  // floor(sqrt(value))]. If value is prime number,
  // then the body of the loop will not be executed.
  // Enumerate all integers from 2 to sqrt(value).
  for (int64_t number = 2; number * number <= value; ++number) {
    // if (value % number == 0) then number is prime number and value =
    // (number)^n * k, where k is not divisible by number
    if (value % number == 0) {
      n = 0;
      // we find the greatest degree n of the number in the decomposition of
      // value
      while (value % number == 0) {
        n++;
        value /= number;
      }
      // Now value = pow(number, n) * k, where k is not divisible by number
      // Using the property of the Euler function that fi(k * p^n) = fi(k) *
      // fi(p^n) and fi(p^n) = p^n - p^(n-1). Adding to answers fi(p^n) and
      // continue decompisiting k.
      numberOfCoprimeNumbers *=
          (pow(number, n) - pow(number, n - 1));
    }
  }
  // after running the loop variable 'value' is 1 or prime number
  // if value is prime then adding to answers fi(p) = p - 1
  if (value > 1) numberOfCoprimeNumbers *= value - 1;

  return numberOfCoprimeNumbers;
}
