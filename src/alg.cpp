// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value == 1) return false;
  for (uint64_t divider = 2; divider * divider <= value; divider++) {
    if (value % divider == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 1) return 2;
  uint64_t counter = 1;
  int i;
  for (i = 3;; i+=2) {
    if (checkPrime(i)) counter++;
    if (counter == n) return i;
  }
}

uint64_t nextPrime(uint64_t value) {
  for (uint64_t x = value + 1;; x++) {
    if (checkPrime(x)) return x;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound == 3) return 2;
  uint64_t sum = 2;
  for (uint64_t i = 3; i < hbound; i+=2) {
    if (checkPrime(i) == true) sum += i;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int counter = 0;
  for (uint64_t i = (lbound / 2) * 2 + 1; i < hbound - 2; i += 2) {
    if (checkPrime(i) && checkPrime(i + 2)) counter++;
  }
  return counter;
}
