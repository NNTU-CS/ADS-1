// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) {
return false;
  }
  if (value <= 3) {
    return true;
  }
  if (value % 2 == 0 || value % 3 == 0) {
    return false;
  }
  for (uint64_t i = 5; i * i <= value; i = i + 6) {
    if (value % i == 0 || value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 1) {
    return 2;
  }
  uint64_t count = 1;
  uint64_t i = 3;
  while (count < n) {
    if (checkPrime(i)) {
      count++;
    }
    if (count == n) {
      return i;
    }
    i += 2;
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) {
    return 2;
  }
  uint64_t i = value + 1;
  if (i % 2 == 0) {
    i += 1;
  }
  while (true) {
    if (checkPrime(i))
  return i;
    i = (i == 2) ? 3 : i + 2;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  if (hbound >= 2) {
    sum +=2;
  }
  for (uint64_t n = 3; n <= hbound; n+=2) {
    if (checkPrime(n)) {
      sum += n;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound - 2; ++i) {
    if (i < 2) {
      continue;
    }
    if (checkPrime(i) && checkPrime(i + 2)) {
      count++;
    }
  }
  return count;
}
