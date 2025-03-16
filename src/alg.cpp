// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  for (int i = 2; i * i <= value; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0, m = 1;
  while (count < n) {
    m++;
    if (checkPrime(m)) {
      count++;
    }
  }
  return m;
}

uint64_t nextPrime(uint64_t value) {
  nextValue = value + 1;
  while (true) {
    if (checkPrime(nextValue)) {
      return nextValue;
    }
    nextValue++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t summa = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (chekPrime(i)) {
      summa += i;
    }
  }
  return summa;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t countPair = 0, prePrime = 0;
  for (uint64_t i = lbound; i < hbound; i++;) {
    if (chekPrime(i)) {
      if (i - prePrime == 2) {
        countPair++;
      }
      prePrime = i;
    }
  }
  return counPair;
}
