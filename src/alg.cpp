// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include "math.h"

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  for (uint64_t i = 2; i < static_cast<uint64_t>(sqrt(value) + 1); ++i) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t num = 2;
  uint64_t cnt = 0;
  for (; cnt < n; num++) {
    if (checkPrime(num)) cnt++;
  }
  return num-1;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t next = value+1;
  for (; !checkPrime(next); next++) {}
  return next;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound < 2) return 0;
  uint64_t sum = 0;
  for (uint64_t num = 2; num < hbound; num = nextPrime(num)) sum += num;
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t cnt = 0;
  for (uint64_t i = lbound; i < hbound; i = nextPrime(i)) {
    if (nextPrime(i) - i == 2) cnt++;
  }
  return cnt;
}
