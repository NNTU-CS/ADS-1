// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value == 0 || value == 1) return false;
  for (int i = 2; i*i <= value; ++i) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t i = 2;
  while (n > 1) {
    i += 1;
    if (checkPrime(i)) {
      n -= 1;
    }
  }
  return i;
}

uint64_t nextPrime(uint64_t value) {
  value += 1;
  while (!checkPrime(value)) {
    value += 1;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (int i = 2; i < hbound; ++i) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

