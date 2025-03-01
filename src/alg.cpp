// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value == 0 || value == 1) {
    return false;
  }
  for (int i = 2; i < value / 2 + 1; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;
  uint64_t currNum = 1;
  while (count < n) {
    currNum++;
    if (checkPrime(currNum)) {
      count++;
    }
  }
  return currNum;
}

uint64_t nextPrime(uint64_t value) {
  value++;
  while (!checkPrime(value)) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound <= lbound) {
    return 0;
  }
  uint64_t count = 0;
  uint64_t previous = 0;
  for (uint64_t i = lbound; i < hbound; ++i) {
    if (checkPrime(i)) {
      if (previous != 0 && i - previous == 2) {
        count++;
      }
      previous = i;
    }
}

return count;
}
