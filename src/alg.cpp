// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  for (int i = 2; i * i <= value; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t k = 0, m = 2;
  while (k < n) {
    if (checkPrime(m)) {
      k++;
    }
    ++m;
  }
  return m-1;
}

uint64_t nextPrime(uint64_t value) {
  if (checkPrime(value)) value++;
  while (!checkPrime(value)) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (int i = 2; i < hbound; i++) {
    if (checkPrime(i)) sum += i;
  }
  return sum;
}
