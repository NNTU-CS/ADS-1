// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  for (int i = 2; i*i <= value; i++) {
    if (value%i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 1) return 2;
  if (n == 2) return 3;
  uint64_t count = 2;
  uint64_t number = 5;
  while (count < n) {
    if (checkPrime(number)) count++;
    if (count == n) return number;
    number += 2;
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) return 2;
  uint64_t nextNum = value + 1;
  while (true) {
    if (checkPrime(nextNum)) return nextNum;
    nextNum++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t value = 2; value < hbound; value++) {
    if (checkPrime(value)) sum += value;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound-1; i++) {
    if (checkPrime(i) && checkPrime(i+2)) count++;
  }
  return count;
}
