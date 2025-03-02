// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  for (uint64_t i = 2; i * i <= value; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }
  uint64_t count = 0;
  uint64_t number = 1;
  while (count < n) {
    number++;
    if (checkPrime(number)) {
      count++;
    }
  }
  return number;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t nextNum = value + 1;
  while (!checkPrime(nextNum)) {
    nextNum++;
  }
  return nextNum;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t j = 2; j < hbound; j++) {
    if (checkPrime(j)) {
      sum += j;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t cnt = 0;
  for (uint64_t k = lbound; k < hbound - 2; k++) {
    if (checkPrime(k) && checkPrime(k+2)) {
      cnt++;
    }
  }
  return cnt;
}
