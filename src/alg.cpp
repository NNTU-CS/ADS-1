// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>


bool checkPrime(uint64_t value) {
  for (uint64_t i = 3; i <= sqrt(value); i ++) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n < 1) return 0;
  uint64_t count = 0;
  uint64_t num = 1;
  while (count < n) {
    num++;
    if (checkPrime(num)) {
      count++;
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t next = value + 1;
  while (!checkPrime(next)) {
    next++;
  }
  return next;
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
  uint64_t lastPrime = 0;
  for (uint64_t i = lbound; i < hbound; i++) {
    if (checkPrime(i)) {
      if (lastPrime != 0 && i - lastPrime == 2) {
        count++;
      }
      lastPrime = i;
    }
  }
  return count;
}
