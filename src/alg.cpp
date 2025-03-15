// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
  uint64_t k = 0;
  for (int i = 1; i <= sqrt(value); i++) {
    if (value % i == 0) k += 1;
  }
  if (k == 1) {
    return true;
  } else {
    return false;
  }
}

uint64_t nPrime(uint64_t n) {
  uint64_t i = 0, a = 2;
  while (i < n) {
    if (checkPrime(a)) {
      i += 1;
    }
    a += 1;
  }
  return a - 1;
}

uint64_t nextPrime(uint64_t value) {
  value += 1;
  while (!checkPrime(value)) {
    value += 1;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t i = 2, sum = 0;
  while (i < hbound) {
    if (checkPrime(i)) {
      sum += i;
    }
    i += 1;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t k = 0, a = lbound;
  while (a + 2 < hbound) {
    if (checkPrime(a) && checkPrime(a + 2)) {
      k += 1;
    }
    a += 1;
  }
  return k;
}
