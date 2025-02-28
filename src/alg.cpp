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
  uint64_t prime_count = 0;
  for (uint64_t candidate = 2; candidate <= 1000000; ++candidate) {
    if (checkPrime(candidate)) {
      ++prime_count;
      if (prime_count == n) {
        return candidate;
      }
    }
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  for (uint64_t candidate = value + 1; candidate <= 1000000; ++candidate) {
    if (checkPrime(candidate)) {
      return candidate;
    }
  }
  return 0;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t candidate = 2; candidate < hbound; ++candidate) {
    if (checkPrime(candidate)) {
      sum += candidate;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t twin_count = 0;
  for (uint64_t candidate = lbound; candidate + 2 < hbound; ++candidate) {
    if (checkPrime(candidate) && checkPrime(candidate + 2)) {
      ++twin_count;
    }
  }
  return twin_count;
}
