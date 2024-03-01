// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
  if (value <= 1) {
    return false;
  } else if (value > 1) {
    for (int i = 2; i < value; i++) {
      if (value % i == 0) {
        return false;
      } else {
        return true;
      }
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
  uint64_t counter = 0;
  uint64_t num = 2;
  while (counter < n) {
    if (checkPrime(num)) {
      counter++;
      }
    num++;
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
  value++;
  while (true) {
    if (checkPrime(value)) {
      return value;
      break;
      } else {
      value++;
    }
  }
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
    uint64_t summation = 0;
  for (int i = 2; i < hbound; i++) {
    if (checkPrime(i)) summation += i;
  }
  return summation;
}
