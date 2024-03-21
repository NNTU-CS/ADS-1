// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
    for (uint64_t i = 2; i <= pow(value, 0.5); i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
  int count = 0;
  int i = 2;
  while (true) {
    if (checkPrime(i)) {
      count++;
      if (n == count) {
        return i;
        break;
      }
    }
    i++;
  }
}

uint64_t nextPrime(uint64_t value) {
    uint64_t i = value + 1;
    while (!(checkPrime(i))) {
        i++;
    }
    return i;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
