// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"



bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  for (size_t i = 2; i * i <= value; i++) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int num = 1;
  for (size_t i = 2; i <= n; i++) {
    if (checkPrime(i) == true) num++;
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  for (size_t i = value + 1; i < (value * value); i++) {
    if (checkPrime(i) == true) return i;
  }
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  int first = 2;
  int sum = 0;
  while (first < hbound) {
    sum = sum + first;
    first = nextPrime(first);
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  for (size_t i = lbound; i < hbound; i++) {
    if ((checkPrime(i) == true) && (checkPrime(i+2) == true)) count ++;
  }
  return count;
}
