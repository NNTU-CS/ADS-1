// Copyright 2022 NNTU-CS
#include <cstdint>

#include "alg.h"

bool checkPrime(uint64_t value) {
  for (uint64_t i = 2; i <= value / 2; i++) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t k = 0, a = 2;

  while (k != n) {
    if (checkPrime(a)) k++;
    a++;
  }
  return a - 1;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t a = value + 1;

  while (!checkPrime(a)) {
    a++;
  }
  return a;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 2, x = 3;

  if (hbound < 3)
    return 0;
  else {
    while (x < hbound) {
      if (checkPrime(x)) sum += x;
      x++;
    }
    return sum;
  }
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t k = 0;

  for (uint64_t i = lbound; i <= hbound - 3; i++) {
    if (checkPrime(i) && checkPrime(i + 2)) k++;
  }
  return k;
}
