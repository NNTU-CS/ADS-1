// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  for (uint64_t i = 2; i <= sqrt(value); i++) {
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
  uint64_t count = 0;
  uint64_t num = 2;
  while (true) {
    if (checkPrime(num)) {
      count++;
      if (count == n) {
        return num;
      }
    }
    num++;
  }
}

uint64_t nextPrime(uint64_t value) {
  value++;
  while (!checkPrime(value)) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t num = 2;
  uint64_t sum = 0;
  while (num < hbound) {
    if (checkPrime(num)) {
      sum += num;
    }
    num = nextPrime(num);
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t cnt = 0;
  uint64_t num = nextPrime(lbound - 1);
  while (num < hbound) {
    uint64_t next = nextPrime(num);
    if (next >= hbound) {
      break;
    }
    if ((next - num) == 2) {
      cnt++;
    }
    num = next;
  }
  return cnt;
}
