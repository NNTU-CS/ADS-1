// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  uint64_t i;
  if (value <= 1) {
    return false;
  }
  if (value == 2) {
    return true;
  }
  if (value % 2 == 0) {
    return false;
  }
  for (i = 3; i * i <= value; i = i + 2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t num = 2;
  uint64_t count = 0;
  while (true) {
    if (checkPrime(num)) {
      count++;
    }
    if (count == n) {
      return num;
    }
    num++;
  }
}

uint64_t nextPrime(uint64_t value) {
  while (true) {
    value++;
    if (checkPrime(value)) {
      return value;
    }
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t summa = 0;
  uint64_t i;
  if (hbound > 2) {
    summa = summa + 2;
  }
  for (i = 3; i < hbound; i = i + 2) {
    if (checkPrime(i)) {
      summa = summa + i;
    }
  }
  return summa;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  uint64_t i;
  for (i = lbound; i < hbound-2; i++) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count++;
    }
  }
  return count;
}
