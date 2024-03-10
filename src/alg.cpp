// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>


bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  for (uint64_t i = 2; i*i <= value; i++) {
    if (value%i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
  uint64_t i = 2, s = 0;
  while (true) {
    if (checkPrime(i))
      s++;
    if (s == n)
      return i;
    i++;
  }
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
  uint64_t k = value + 1;
  while (true) {
    if (checkPrime(k))
      return k;
    k++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
        if (nPrime(i)) {
            sum += i;
        }
    }
  return sum;
}
