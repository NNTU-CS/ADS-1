// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  for (uint64_t i = 2; i * i <= value; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
    if (n <= 0) {
        return 0;
    }
    uint64_t primeCount = 0;
    uint64_t number = 2;
    while (primeCount < n) {
        if (checkPrime(number)) {
            ++primeCount;
        }
        if (primeCount < n) {
            ++number;
        }
    }
    return number;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t num = value + 1;
    while (!checkPrime(num)) {
        num++;
    }
    return num;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t num = 2;
    uint64_t counter = 0;
    while (num < hbound) {
        if (checkPrime(num)) {
            counter += num;
        }
        num++;
    }
    return counter;
}
