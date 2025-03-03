// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2) return true;
  if (value % 2 == 0) return false;

  for (uint64_t i = 3; i * i <= value; i += 2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;

  uint64_t count = 0;
  uint64_t number = 1;

  while (count < n) {
    number++;
    if (checkPrime(number)) {
      count++;
    }
  }
  return number;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t next = value + 1;

  while (!checkPrime(next)) {
    next++;
  }
  return next;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 2;
  for (uint64_t i = 3; i < hbound; i += 2) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound < 3 || lbound >= hbound) return 0;

  uint64_t count = 0;
  uint64_t prevPrime = 0;
  for (uint64_t i = lbound; i < hbound; i++) {
    if (checkPrime(i)) {
      prevPrime = i;
      break;
    }
  }

  for (uint64_t i = prevPrime + 1; i < hbound; i++) {
    if (checkPrime(i)) {
      if (i - prevPrime == 2) {
        count++;
      }
      prevPrime = i;
    }
  }
  return count;
}
