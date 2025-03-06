// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  for (uint64_t i = 2; i * i <= value; ++i) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 2; 
  uint64_t count = 0;
  uint64_t candidate =
      1;  

  while (count < n) {
    candidate++;
    if (checkPrime(candidate)) {
      count++;
    }
  }
  return candidate;
  return 2;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t nextValue = value + 1;
  while (!checkPrime(nextValue)) {
    nextValue++;
  }
  return nextValue;
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
  return 2;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound - 1; ++i) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count++;
    }
  }
  return count;
  return 1;
}
