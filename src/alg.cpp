// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  for (uint64_t i = 2; i*i <= value; i++)
    if (value % i == 0) {
    return false;
    }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t i = 2;
  while (n > 0) {
    if (checkPrime(i)) {
    n--;
    }
    i++;
  }
  i--;
  return i;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t i = value;
  while (i >= 2) {
    i++;
    if (checkPrime(i)) {
    return i;
    }
  }
  return  2;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t summ = 0;
  for (uint64_t i = 2; i < hbound; i++)
    if (checkPrime(i)) {
    summ += i;
    }
  return summ;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound + 2; i < hbound; i++) {
    if (checkPrime(i - 2) && checkPrime(i)) {
    count++;
    }
  }
  return count;
}
