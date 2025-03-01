// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  uint64_t count = 0;
  for (uint64_t i = 2; i < value / 2 + 1; i++) {
    if (value % i == 0) {
      count++;
    }
  }
  if (count >= 1)
  return false;
  else
  return true;
}

uint64_t nPrime(uint64_t n) {
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
  while (!checkPrime(++value)) {}
    return value;
  }

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
  while (--hbound > 1) {
    if (checkPrime(hbound)) {
        sum += hbound;
      }
    }
    return sum;
  }

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t lastPrime = 0;
    uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound; i++) {
    if (checkPrime(i)) {
        lastPrime = i;
        break;
      }
    }
  for (uint64_t i = lastPrime + 1; i < hbound; i++) {
    if (checkPrime(i)) {
      if (i - lastPrime == 2) {
          count++;
        }
        lastPrime = i;
      }
    }
    return count;
  }
