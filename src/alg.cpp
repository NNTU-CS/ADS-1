// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  for (int i = 2; i < (value + 2) / 2; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int value = 2;
  int val_num = 1;
  while (val_num < n) {
    value++;
    if (checkPrime(value) == true) {
      val_num++;
    }
  }
  return value;
}

uint64_t nextPrime(uint64_t value) {
  value++;
  while (checkPrime(value) != true) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 0; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  for (int value = lbound; value < hbound; value = nextPrime(value)) {
    if ((nextPrime(value) < hbound) && (nextPrime(value) - value == 2)) {
      count++;
    }
  }
  return count;
}
