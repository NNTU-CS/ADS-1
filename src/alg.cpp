// Copyright 2022 NNTU-CS
#include <cmath>
#include <cstdint>

#include "alg.h"

namespace {

bool check_prime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  uint64_t sqrt_val = static_cast<uint64_t>(std::sqrt(value)) + 1;
  for (uint64_t i = 2; i < sqrt_val; ++i) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

}

bool checkPrime(uint64_t value) {
  return check_prime(value);
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }
  uint64_t count = 0;
  uint64_t prime = 0;

  for (uint64_t num = 2; count < n; ++num) {
    if (check_prime(num)) {
      prime = num;
      ++count;
    }
  }
  return prime;
}

uint64_t nextPrime(uint64_t value) {
  for (uint64_t num = value + 1;; ++num) {
    if (check_prime(num)) {
      return num;
    }
  }
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t num = 2; num < hbound; ++num) {
    if (check_prime(num)) {
      sum += num;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t prev_prime = static_cast<uint64_t>(-10);
  uint64_t count = 0;

  for (uint64_t num = lbound; num < hbound; ++num) {
    if (check_prime(num)) {
      if (prev_prime + 2 == num) {
        ++count;
      }
      prev_prime = num;
    }
  }
  return count;
}
