// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  for (uint64_t i = 2; i * i <= value; i++) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t kol = 0;
  uint64_t num = 0;

  if (n < 2) return 0;
  while (kol < n) {
    num++;
    if (checkPrime(num)) {
      kol++;
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  value++;
  while (!checkPrime(value)) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t num = 2; num < hbound; num++) {
    if (checkPrime(num)) {
      sum += num;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t kol = 0;
  uint64_t pervChisl = 0;

  for (uint64_t num = lbound; num < hbound; num++) {
    if (checkPrime(num)) {
      if (pervChisl != 0 && num - pervChisl == 2) {
        kol++;
      }
      pervChisl = num;
    }
  }
  return kol;
}
