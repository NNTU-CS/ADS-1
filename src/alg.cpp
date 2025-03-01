// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include "math.h"

bool checkPrime(uint64_t value) {
  if (value <= 1 || value % 2 == 0) {
    return false;
  }
  for (int i = 3; i < sqrt(value) + 1; i += 2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n != 1) {
    uint64_t count = 1, i = 3;
    while (count != n) {
      if (checkPrime(i)) {
        ++count;
        if (count == n) {
          return i;
        }
      }
      ++i;
    }
  }
  return 2;
}

uint64_t nextPrime(uint64_t value) {
  ++value;
  while (!checkPrime(value)) {
    ++value;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound > 2) {
    uint64_t sum = 2, i = 3;
    while (i < hbound) {
      if (checkPrime(i)) {
        sum += i;
      }
      ++i;
    }
    return sum;
  }
  return 2;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (int i = lbound; i < hbound - 2; ++i) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count += 1;
    }
  }
  return count;
}
