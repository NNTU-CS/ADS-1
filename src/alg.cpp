// Copyright 2022 NNTU-CS
#include "alg.h"
#include <math.h>
#include <cstdint>

bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  for (uint64_t i = 2; i <= sqrt(value); i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n < 1) {
    return 0;
  }
  uint64_t cnt = 0, num = 1;
  while (cnt < n) {
    num++;
    if (checkPrime(num) == true) {
      cnt++;
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t next = value + 1;
  while (checkPrime(next) == false) {
    next++;
  }
  return next;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t s = 0;
  for (uint64_t i = 0; i < hbound; i++) {
    if (checkPrime(i) == true) {
      s += i;
    }
  }
  return s;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t cnt = 0;
  for (uint64_t i = lbound; i < (hbound - 1); i++) {
    if (checkPrime(i) == true && checkPrime(i + 2) == true) {
      cnt++;
    }
  }
  return cnt;
}
