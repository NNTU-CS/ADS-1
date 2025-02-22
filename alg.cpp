// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
  int value_sqrt = (pow(value, 0.5) + 1) / 1;
  for (int i = 2; i <= value_sqrt; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t prime_number = 0;
  uint64_t counter = 0;
  bool flag = false;
  for (uint64_t i = 2; flag != true; i++) {
    if (checkPrime(i)) {
      counter++;
    }
    if (counter == n) {
      flag = true;
      prime_number = i;
    }
  }

  return prime_number;
}

uint64_t nextPrime(uint64_t value) {
  bool flag = false;
  uint64_t next_prime = 0;

  for (uint64_t i = value + 1; flag != true; i++) {
    if (checkPrime(i)) {
      next_prime = i;
      flag = true;
    }
  }

  return next_prime;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;

  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum = sum + i;
    }
  }

  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int twin_count = 0;

  for (uint64_t i = lbound; i < hbound; i++) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      twin_count++;
    }
  }

  return twin_count;
}
