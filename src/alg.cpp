// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  for (uint64_t divisor = 2; divisor * divisor <= value; ++divisor) {
    if (value % divisor == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }
  uint64_t count = 0;
  uint64_t currentNum = 2;
  while (true) {
    if (checkPrime(currentNum)) {
      ++count;
      if (count == n) {
        return currentNum;
      }
    }
    ++currentNum;
  }
}

uint64_t nextPrime(uint64_t value) {
  uint64_t candidate = value + 1;
  while (true) {
    if (checkPrime(candidate)) {
      return candidate;
    }
    ++candidate;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound < 2) {
    return 0;
  }
  uint64_t sum = 0;
  for (uint64_t num = 2; num < hbound; ++num) {
    if (checkPrime(num)) {
      sum += num;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound < 3 || lbound > hbound) {
    return 0;
  }
  uint64_t twinCount = 0;
  for (uint64_t num = lbound; num + 2 < hbound; ++num) {
    if (checkPrime(num) && checkPrime(num + 2)) {
      ++twinCount;
    }
  }
  return twinCount;
}
