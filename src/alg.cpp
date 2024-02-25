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
  for (uint64_t i = 3; i <= value/2; i ++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;
  uint64_t number = 2;
  while (count < n) {
    if (checkPrime(number)) {
      count++;
    }
    number++;
  }
  return number - 1;
}

uint64_t nextPrime(uint64_t value) {
  int number = value + 1;
  while (true) {
    if (checkPrime(number)) {
      return number;
    }
    number++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (int i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}
