// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2) return true;
  if (value % 2 == 0) return false;

  for (uint64_t i = 3; i * i <= value; i += 2) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;
  uint64_t num = 2;

  while (true) {
    if (checkPrime(num)) {
      ++count;
      if (count == n) return num;
    }
    ++num;
  }
}

uint64_t nextPrime(uint64_t value) {
  uint64_t num = value + 1;
  while (true) {
    if (checkPrime(num)) return num;
    ++num;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t num = 2; num < hbound; ++num) {
    if (checkPrime(num)) sum += num;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t num = lbound; num + 2 < hbound; ++num) {
    if (checkPrime(num) && checkPrime(num + 2)) {
      ++count;
    }
  }
  return count;
}
