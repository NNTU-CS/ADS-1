// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  if (value == 2) {
    return true;
  }
  if (value % 2 == 0) {
    return false;
  }
  for (uint64_t i = 3; i * i <= value; i += 2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  const uint32_t SIZE = 100 * 1000;
  int a[SIZE] = {};
  for (int i = 2; i < SIZE; ++i)
    a[i] = 1;
  uint32_t k = 1;
  uint32_t p = 2;
  while (k < n) {
    for (uint32_t i = 2 * p; i < SIZE; i += p)
      a[i] = 0;
    for (uint32_t i = p + 1; i < SIZE; ++i)
      if (a[i] == 1) {
        p = i;
        break;
      }
    ++k;
  }
  return p;
}

uint64_t nextPrime(uint64_t value) {
  for (uint64_t i = value + 1; ; i++) {
    if (checkPrime(i))
      return i;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint32_t i = 0; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int temp = 0;
  int count = 0;
  for (int i = 3; i < hbound; i += 2) {
    if (!checkPrime(i)) {
      continue;
    }
    if (i >= lbound) {
      if (temp && (i - temp == 2)) {
        count++;
      }
      temp = i;
    }
  }
  return count;
}
