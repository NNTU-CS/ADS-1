// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2 || value == 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return true;
  uint64_t limit = static_cast<uint64_t>(std::sqrt(value));
  for (uint64_t i = 5; i <= limit; i += 6) {
    if (value % i == 0 || value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  uint64_t count = 0;
  uint64_t value = 1;
  while (true) {
    ++value;
    if (checkPrime(value)) {
      ++count;
      if (count == n) return value;
    }
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t candidate = value + 1;
  while (true) {
    if (checkPrime(candidate)) return candidate;
    ++candidate;
  }
  return 0;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound < 2) return 0;
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) sum += i;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound < 3) return 0;
  std::vector<uint64_t> primesInRange;
  for (uint64_t i = lbound; i < hbound; ++i) {
    if (checkPrime(i)) primesInRange.push_back(i);
  }
  uint64_t count = 0;
  for (size_t i = 0; i + 1 < primesInRange.size(); ++i) {
    if (primesInRange[i + 1] - primesInRange[i] == 2) ++count;
  }
  return count;
}
