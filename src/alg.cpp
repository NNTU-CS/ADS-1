// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  if (value == 2) {
    return true;
  }
  if (value % 2 == 0) {
    return false;
  }
  for (int i = 3; i * i <= value; i += 2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int final = 2;
  int count = 0;
  while (1) {
    if (checkPrime(final)) {
      count += 1;
    }
    if (count == n) {
      return final;
    }
    final += 1;
  }
}

uint64_t nextPrime(uint64_t value) {
  while (1) {
    value++;
    if (checkPrime(value)) {
      return value;
    }
  }
}

uint64_t sumPrime(uint64_t hbound) {
  int sum = 0;
  if (hbound > 2) {
    sum += 2;
  }
  for (int i = 3; i < hbound; i += 2) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  for (lbound; lbound < hbound-2; lbound += 1) {
    if (checkPrime(lbound) and checkPrime(lbound + 2)) {
      count += 1;
    }
  }
  return count;
}
