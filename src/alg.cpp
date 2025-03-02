// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>
#include <math.h>

bool checkPrime(uint64_t value) {
    for (uint64_t i = 2; i <= sqrt(value); i++) {
        if (value % i == 0) {
      return false;
    }
  }
}
uint64_t nPrime(uint64_t n) {
  uint64_t cnt = 0;
  uint64_t num = 0;
    while (true) {
        if (checkPrime(num)) {
      cnt++;
            if (cnt == n) {
        return num;
      }
    }
    num++;
  }
}
uint64_t nextPrime(uint64_t value) {
  uint64_t num = value + 1;
    while (!checkPrime(num)) {
    num++;
  }
  return num;
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
  uint64_t cnt = 0;
    for (uint64_t i = lbound; i < hbound - 1; ++i) {
        if (checkPrime(i) && checkPrime(i + 2)) {
      cnt++;
    }
  }
  return cnt;
}
