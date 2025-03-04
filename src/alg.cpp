// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value == 2) return true;
  if (value % 2 == 0) return false;
  for (uint64_t i = 3; i * i <= value; i += 2) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  if (n == 1) return 2;
  uint64_t num = 1;
  uint64_t k = 1;
  while (k < n) {
    num += 2;
    if (checkPrime(num)) {
      k++;
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  if (value <= 1) return 2;
  uint64_t num;
  if (value % 2 == 0) {
    num = value + 1;
  }
  else {
    num = value + 2;
  }
  while (!checkPrime(num)) {
    num += 2;
  }
  return num;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
  uint64_t sum = 0;
  for (uint64_t k = 2; k < hbound; k++) {
    if (checkPrime(k)) {
      sum += k;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound < 4) return 0;
  uint64_t k = 0;
  uint64_t nch = (lbound % 2 == 0) ? lbound + 1 : lbound;
  for (uint64_t j = nch; j + 2 < hbound; j += 2) {
    if (checkPrime(j) && checkPrime(j + 2)) {
      k++;
    }
  }
  return k;
}
