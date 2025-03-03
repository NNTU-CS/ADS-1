// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  for (uint64_t i = 2; i * i <= value; ++i) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;
  uint64_t num = 2;
  while (count < n) {
    bool isPrime = true;
    for (uint64_t i = 2; i * i <= num; ++i) {
      if (num % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      ++count;
    }
    ++num;
  }
  return num - 1;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t num = value + 1;
  while (true) {
    bool isPrime = true;
    for (uint64_t i = 2; i * i <= num; ++i) {
      if (num % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      return num;
    }
    ++num;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    bool isPrime = true;
    for (uint64_t j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound - 2; ++i) {
    bool isPrime1 = true;
    bool isPrime2 = true;
    for (uint64_t j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        isPrime1 = false;
        break;
      }
    }
    for (uint64_t j = 2; j * j <= (i + 2); ++j) {
      if ((i + 2) % j == 0) {
        isPrime2 = false;
        break;
      }
    }
    if (isPrime1 && isPrime2) {
      ++count;
    }
  }
  return count;
}

