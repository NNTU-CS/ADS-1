// Copyright 2022 NNTU-CS
#include <math.h>
#include <stdio.h>

#include <iostream>

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  for (int i = 2; static_cast<int>(i <= pow(value, 0.5)); i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t k = 0;
  uint64_t i = 0;

  while (k != n) {
    i += 1;
    bool isPrime = true;

    if (i < 2) continue;

    for (uint64_t h = 2; h <= sqrt(i); h++) {
      if (i % h == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      k += 1;
    }
  }
  return i;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t next = value + 1;
  while (true) {
    bool pr = true;
    for (uint64_t i = 2; i <= sqrt(next); i++) {
      if (next % i == 0) {
        pr = false;
        break;
      }
    }
    if (pr) {
      return next;
    }
    next++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t present = 2; present < hbound; present++) {
    bool isPrime = true;
    for (uint64_t i = 2; i <= sqrt(present); i++) {
      if (present % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      sum += present;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  uint64_t k;
  uint64_t l;
  for (uint64_t present = lbound; present < hbound; present++) {
    bool isPrime = true;
    for (uint64_t i = 2; i <= sqrt(present); i++) {
      if (present % i == 0) {
        isPrime = false;
      }
    }
    if (isPrime) {
      k = present;
      for (uint64_t next = k + 1; next < hbound; next++) {
        bool isPrime2 = true;
        for (uint64_t i = 2; i <= sqrt(next); i++) {
          if (next % i == 0) {
            isPrime2 = false;
            break;
          }
        }
        if (isPrime2) {
          l = next;
          if (l - k == 2) {
            count += 1;
          }
          break;
        }
      }
    }
  }
  return count;
}
