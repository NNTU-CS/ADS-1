// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>

bool checkPrime(uint64_t value) {
  uint64_t k;
  for (int i = 1; i <= sqrt(value); i++) {
    if (value % i == 0)
      k += 1;
  }
  if (k == 1)
    return true;
  else
    return false;
}

uint64_t nPrime(uint64_t n) {
  uint64_t i, a = 2, k;
  while (i < n) {
    k = 0;
    for (int j = 1; j <= sqrt(a); j++) {
      if (a % j == 0)
        k += 1;
    }
    if (k == 1)
      i += 1;
    a += 1;
  }
  return a - 1;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t i, k;
  while (k != 1) {
    k = 0;
    value += 1;
    for (int j = 1; j <= sqrt(value); j++) {
      if (value % j == 0)
        k += 1;
    }
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t i = 2, sum;
  while (i < hbound) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum - 1;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t k, a = lbound;
  while (a + 2 < hbound) {
    if (checkPrime(a) && checkPrime(a + 2)) {
      k += 1;
    }
    a += 1;
  }
  return k;
}
