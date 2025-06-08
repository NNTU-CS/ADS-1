// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value < 2) return false;
  for (int i = 2; i * i <= value; i++) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
   int pos = 1;
  int num = 2;
  if (n == 1) return 2;
  while (pos < n) {
    num++;
    if (checkPrime(num) == true) pos++;
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
    value += 1;
  while (checkPrime(value) != true) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
   uint64_t first = 2;
  uint64_t sumP = 0;
  if (hbound <= 2) return 0;
  while (first < hbound) {
    sumP += first;
    first = nextPrime(first);
  }
  return sumP;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  for (int i = lbound; i < hbound; i++) {
    if ((checkPrime(i) == true) && (checkPrime(i+2) == true)) count++;
  }
  return count;
}
