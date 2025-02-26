// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include <vector>
#include <stdexcept>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value == 2 || value == 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;
  for (uint64_t i = 5; i * i <= value; i += 6) {
    if (value % i == 0 || value % (i + 2) == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return UINT64_MAX;
  if (n == 1) return 2;
  if (n == 2) return 3;

  uint64_t limit = n * (std::log(n) + std::log(std::log(n)));
  if (limit < 5) limit = 5;

  std::vector<bool> sieve(limit + 1, true);
  sieve[0] = sieve[1] = false;
  for (uint64_t i = 2; i * i <= limit; ++i) {
    if (sieve[i]) {
      for (uint64_t j = i * i; j <= limit; j += i) {
        sieve[j] = false;
      }
    }
  }

  uint64_t count = 0;
  for (uint64_t i = 2; i <= limit; ++i) {
    if (sieve[i]) {
      ++count;
      if (count == n) return i;
    }
  }
  return UINT64_MAX;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t candidate = value + 1;
  while (true) {
    if (checkPrime(candidate)) return candidate;
    ++candidate;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) sum += i;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound <= lbound) return 0;

  std::vector<bool> sieve(hbound, true);
  sieve[0] = sieve[1] = false;
  for (uint64_t i = 2; i * i < hbound; ++i) {
    if (sieve[i]) {
      for (uint64_t j = i * i; j < hbound; j += i) {
        sieve[j] = false;
      }
    }
  }

  uint64_t count = 0;
  for (uint64_t i = lbound; i + 2 < hbound; ++i) {
    if (sieve[i] && sieve[i + 2]) ++count;
  }
  return count;
}
