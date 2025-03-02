// Copyright 2023 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t number) {
  if (number < 2) {
    return false;
  }
  for (uint64_t i = 2; i * i <= number; ++i) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t index) {
  if (index == 0) {
    return 0;
  }
  uint64_t num = 2, count = 0;
  while (true) {
    if (checkPrime(num)) {
      count++;
      if (count == index) {
        return num;
      }
    }
    num++;
  }
}

uint64_t nextPrime(uint64_t number) {
  uint64_t num = number + 1;
  while (!checkPrime(num)) {
    num++;
  }
  return num;
}

uint64_t sumPrime(uint64_t limit) {
  if (limit < 2) {
    return 0;
  }
  uint64_t sum = 0;
  for (uint64_t num = 2; num < limit; ++num) {
    if (checkPrime(num)) {
      sum += num;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t low, uint64_t high) {
  if (high < 3 || low > high) {
    return 0;
  }
  uint64_t twinPairs = 0;
  for (uint64_t num = low; num + 2 < high; ++num) {
    if (checkPrime(num) && checkPrime(num + 2)) {
      ++twinPairs;
    }
  }
  return twinPairs;
}
