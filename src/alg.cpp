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
  uint64_t number = 1;
  uint64_t count = 0;
  for ( ; count < n; number++ ) {
    if (checkPrime(number)) {
      count++;
    }
  }
  return number;
}

uint64_t nextPrime(uint64_t value) {
  if (value <= 1) return 2;
  value++;
  while (!checkPrime(value)) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound < 2) return 0;
  uint64_t sum = 2;
  for (uint64_t number=3; number <= hbound; number+=2) {
    if (checkPrime(number)) {
      sum += number;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  if (lbound < 2) {
    lbound = 2;
  }
  for (uint64_t number = lbound; number < hbound - 2; ++number) {
    if (checkPrime(number) && checkPrime(number + 2)) {
      count++;
    }
  }
  return count;
}
