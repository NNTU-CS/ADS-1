// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>

bool checkPrime(uint64_t value) {
  if (value < 2) {
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
  uint64_t count = 0;
  uint64_t num = 2;
  while (true) {
    if (checkPrime(num)) {
      count++;
      if (count == n) return num;
    }
    num++;
  }
}

uint64_t nextPrime(uint64_t value) {
  for (uint64_t i = value + 1;; i++) {
    if (checkPrime(i)) return i;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) sum += i;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound; i++) {
    if ((i + 2 < hbound) && checkPrime(i) && checkPrime(i + 2)) count++;
  }
  return count;
}
