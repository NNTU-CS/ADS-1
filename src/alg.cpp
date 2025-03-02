// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  for (uint64_t k = 2; k < value; ++k) {
    if (value % k == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n < 1) return 0;
  uint64_t k = 0;
  uint64_t i = 1;

  while (k < n) {
    ++i;
    if (checkPrime(i)) ++k;
  }
  return i;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t i = value + 1;
  while (!checkPrime(i)) ++i;
  return i;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t k = 0;
  for (uint64_t i = lbound; i < hbound - 2; ++i) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      ++k;
    }
  }
  return k;
}
