// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include "math.h"
bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
    for (uint64_t i = 2; i * i <= value; ++i) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  uint64_t count = 0;
  uint64_t num = 1;
    while (count < n) {
    ++num;
        if (checkPrime(num)) {
      ++count;
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t a = value + 1;
    while (!checkPrime(a)) {
    ++a;
  }
  return a;
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
  uint64_t k = 0;
  uint64_t prevPrime = 0;
    for (uint64_t i = lbound; i < hbound; ++i) {
        if (checkPrime(i)) {
            if (prevPrime != 0 && i - prevPrime == 2) {
        ++k;
      }
      prevPrime = i;
    }
  }
  return k;
}
