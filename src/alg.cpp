// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  int count = 0;
  for (int i = 1; i <= value; i++) {
      if (value % i == 0)
          count++;
  }
  if (count == 2)
      return true;
  return false;
}

uint64_t nPrime(uint64_t n) {
  int c = 0;
  for (int i = 1; ; i++) {
      if (checkPrime(i))
          c++;
      if (c == n) {
          return i;
          break;
      }
  }
}

uint64_t nextPrime(uint64_t value) {
  for (int i = value + 1; ; i++) {
      if (checkPrime(i)) {
          return i;
          break;
      }
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
      if (checkPrime(i)) {
          sum += i;
      }
  }
  return sum;
}
