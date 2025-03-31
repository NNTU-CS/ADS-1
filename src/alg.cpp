// Copyright 2022 NNTU-CS
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
  uint64_t limit = value/2;
  for (int i = 2; i < limit; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 1) {
    return 2;
  }
  int count = 1;
  int num = 2;
  while (count < n) {
    num++;
    if (checkPrime(num)) {
      count++;
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  do {
    value++;
  } while (!checkPrime(value));
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  int num = 2;
  int sum = 0;
  while (num < hbound) {
    sum += num;
    num = nextPrime(num);
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  for (int num = lbound; num < hbound; num = nextPrime(num)) {
    int next = nextPrime(num);
    if (next - num == 2 && next < hbound) {
      count++;
    }
  }
  return count;
}
