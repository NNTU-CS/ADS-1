// Copyright 2022 NNTU-CS
#include "../include/alg.h"
#include <cmath>
#include <cstdint>

bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  uint64_t array = 2;
  for (uint64_t i = static_cast<uint64_t>(pow(value, 0.5)) + 1; i > 1; i--) {
    if (value % i == 0) {
      array++;
    }
  }
  if (array == 2 || value == 2) {
    return true;
  }
  return false;
}

uint64_t nPrime(uint64_t n) {
  for (uint64_t i = 1;; i++) {
    if (checkPrime(i)) {
      n--;
    }
    if (n == 0) {
      return i;
    }
  }
}

uint64_t nextPrime(uint64_t value) {
  // вставьте код функции
  while (1) {
    value++;
    if (checkPrime(value)) {
      return value;
    }
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t n = hbound - 1;
  uint64_t sum = 0;
  while (n > 1) {
    if (checkPrime(n)) {
      sum += n;
    }
    n--;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  // вставьте код функции
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound - 1; i++) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count++;
    }
  }
  return count;
}
