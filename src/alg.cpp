// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value == 0 || value == 1)
  return false;
  if (value == 2)
  return true;
  for (uint64_t i = 2; i < value; i++) {
    if (value % i == 0)
    return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t position = 0;
  uint64_t num = 0;
  while (position < n) {
    num++;
    if (checkPrime(num))
    position++;
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t next = 0;
  for (uint64_t i = value + 1; i < 2 * value; i++) {
    if (checkPrime(i)) {
      next = i;
      break;
    }
  }
  return next;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = hbound - 1; i > 1; i -= 2) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return (sum + 2);
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  uint64_t twin = lbound;
  for (; twin < hbound - 1; twin++) {
    if (checkPrime(twin) && checkPrime(twin + 2)) {
      count++;
    }
  }
  return count;
}
