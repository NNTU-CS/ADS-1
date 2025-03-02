// Copyright 2025 NNTU-CS
#include <cstdint>
#include <cmath>
#include <algorithm>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value == 2 || value == 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;

  uint64_t limit = static_cast<uint64_t>(std::sqrt(value));
  for (uint64_t i = 5; i <= limit; i += 6) {
    if (value % i == 0 || value % (i + 2) == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 1) return 2;

  uint64_t count = 1;
  uint64_t candidate = 3;

  while (count < n) {
    if (checkPrime(candidate)) {
      count++;
    }
    candidate += 2;
  }

  return candidate - 2;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t candidate = value + 1;

  while (!checkPrime(candidate)) {
    candidate++;
  }

  return candidate;
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
  uint64_t count = 0;
  uint64_t prev_prime = 0;

  for (uint64_t i = std::max<uint64_t>(lbound, 2ULL); i < hbound; ++i) {
    if (checkPrime(i)) {
      if (prev_prime != 0 && i - prev_prime == 2) {
        count++;
      }
      prev_prime = i;
    }
  }

  return count;
}
