// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  for (int del = 2; del <= sqrt(value); del++) {
    if (value%del == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int counterSimple = 0;
  int number = 1;
  while (counterSimple != n) {
    number++;
    if (checkPrime(number)) counterSimple++;
  }
  return number;
}

uint64_t nextPrime(uint64_t value) {
  value++;
  while (!checkPrime(value)) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sumSimple = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) sumSimple += i;
  }
  return sumSimple;
}


uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int countSimpleCouple = 0;
  int firstNumber = -1;
  for (int i = lbound; i < hbound; i++) {
    if (checkPrime(i)) {
      if (i-firstNumber == 2) {
        countSimpleCouple++;
      }
      firstNumber = i;
    }
  }
  return countSimpleCouple;
}
