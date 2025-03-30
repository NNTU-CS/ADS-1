// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  for (uint64_t i = 2; i * i <= value; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0, m = 1;
  while (count < n) {
    m++;
    if (checkPrime(m)) {
      count++;
    }
  }
  return m;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t nextValue = value + 1;
  while (true) {
    if (checkPrime(nextValue)) {
      return nextValue;
    }
    nextValue++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  uint64_t start = lbound > 2 ? lbound : 2;
  for (uint64_t i = start; i < hbound - 2; i++) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count++;
    }
  }
  return count;
}
