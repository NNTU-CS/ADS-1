// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
bool checkPrime(uint64_t value) {
  // вставьте код функции
  for (int i = 2; i < (value + 2) / 2; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}
uint64_t nPrime(uint64_t n) {
  // вставьте код функции
  int value = 2;
  int iCount = 1;
  while (iCount < n) {
    value++;
    if (checkPrime(value) == true) {
      iCount++;
    }
  }
  return value;
}
uint64_t nextPrime(uint64_t value) {
  // вставьте код функции
  uint64_t value2 = value + 1;
  if (value2 <= 2) return 2;
  if (value2 % 2 == 0) {
    value2++;
  }
    while (true) {
    if (checkPrime(value2)) {
      return value2;
    }
    value2 += 2;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  // вставьте код функции
  if (hbound <= 2) return 0;
  uint64_t sum = 0;
  uint64_t current_prime = 2;
  while (current_prime < hbound) {
    sum += current_prime;
    current_prime = nextPrime(current_prime);
  }
  return sum;
}
uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  // вставьте код функции
  uint64_t count = 0;
  for (uint64_t p = lbound; p < hbound; ++p) {
      if (checkPrime(p)) {
      uint64_t next = p + 2;
      if (next < hbound && checkPrime(next)) {
        count++;
      }
    }
  }
  return count;
}
