// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value > 1) {
    for (uint64_t i = 2; i <= value / 2; i++) {
      if (value % i == 0) {
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

uint64_t nPrime(uint64_t n) {
  uint64_t counter = 0;
  uint64_t number = 2;
  for (uint64_t i = 0; i < n; ) {
    if (checkPrime(number)) {
      counter++;
      if (counter == n) {
        return number;
      }
    }
    number++;
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t number = value + 1;
  while (true) {
    if (checkPrime(number)) {
      return number;
    }
    number++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 0; i < hbound; i++) {
    if (checkPrime(i)) {
      sum = sum + i;
    }
  }
  return sum;
}
