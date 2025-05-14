// Copyright 2022 NNTU-CS
#include <iostream>
#include <cmath>
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  if (value == 2) {
    return true;
  }
  if (value % 2 == 0) {
    return false;
  }

  uint64_t sqrt_val = static_cast<uint64_t>(std::sqrt(value)) + 1;
  for (uint64_t i = 3; i < sqrt_val; i += 2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 2;
  }
  uint64_t count = 1;
  uint64_t candidate = 3;

  while (count < n) {
    if (checkPrime(candidate)) {
      count++;
      if (count == n) {
        return candidate;
      }
    }
    candidate += 2;
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) {
    return 2;
  }
  uint64_t candidate = value + 1;
  while (true) {
    if (checkPrime(candidate)) {
      return candidate;
    }
    candidate++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;

  uint64_t sum = 2;
  for (uint64_t i = 3; i < hbound; i += 2) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound - lbound < 2) {
    return 0;
  }

  uint64_t count = 0;
  uint64_t prev_prime = 0;
  uint64_t start = (lbound % 2 == 0) ? lbound + 1 : lbound;
  if (start == 1) start = 3;

  for (uint64_t i = start; i < hbound; i += 2) {
    if (checkPrime(i)) {
      if (i - prev_prime == 2) {
        count++;
      }
      prev_prime = i;
    }
  }
  return count;
}
