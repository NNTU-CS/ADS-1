// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) {
      return false;
  }
  for (int i = 2; i < value; i++) {
      if (value % i == 0) {
          return false;
      }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int count = 0;
  for (int i = 2; ; i++) {
      if (checkPrime(i) == true) {
          count += 1;
      }
      if (count == n) {
          return i;
          break;
      }
  }
}

uint64_t nextPrime(uint64_t value) {
  for (int i = value + 1; ; i++) {
      if (checkPrime(i) == true) {
          return i;
          break;
      }
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sumOfPrime = 0;
  for (int i = 2; i <= hbound; i++) {
      if (checkPrime(i) == true) {
          sumOfPrime += i;
      }
  }
  return sumOfPrime;
}
