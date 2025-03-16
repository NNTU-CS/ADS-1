// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t num) {
  if (num < 2) {
    return false;
  }
  for (uint64_t div = 2; div * div <= num; ++div) {
    if (num % div == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;
  uint64_t candidate = 1;
  while (count < n) {
    ++candidate;
    if (checkPrime(candidate)) {
      ++count;
    }
  }
  return candidate;
}

uint64_t nextPrime(uint64_t start) {
  uint64_t candidate = start + 1;
  while (!checkPrime(candidate)) {
    ++candidate;
  }
  return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t total = 0;
  for (uint64_t num = 2; num < hbound; ++num) {
    if (checkPrime(num)) {
      total += num;
    }
  }
  return total;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t twinCount = 0;
  uint64_t prevPrime = 0;
  for (uint64_t num = lbound; num < hbound; ++num) {
    if (checkPrime(num)) {
      if (prevPrime && num - prevPrime == 2) {
        ++twinCount;
      }
      prevPrime = num;
    }
  }
  return twinCount;
}
