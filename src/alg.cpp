// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
      if (value <= 1) return false;
      uint64_t limit = value / 2;
      for (uint64_t i = 2; i <= limit; ++i) {
          if (value % i == 0) {
              return false;
      }
    return true;
  }

uint64_t nPrime(uint64_t n) {
    uint64_t found = 0;
    uint64_t candidate = 1;  
    while (found < n) {
          ++candidate;
          if (checkPrime(candidate)) {
              ++found;
          }
      }
      return candidate;
  }

uint64_t nextPrime(uint64_t value) {
    for (uint64_t candidate = value + 1; ; ++candidate) {
        if (checkPrime(candidate)) {
            return candidate;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t total = 0;
    uint64_t num = 1;
    while (++num < hbound) {
        if (checkPrime(num)) {
            total += num;
        }
    }
    return total;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t twinCount = 0;
    uint64_t lastPrime = 0;
    bool firstFound = false;
    for (uint64_t num = lbound; num < hbound; ++num) {
          if (checkPrime(num)) {
              if (firstFound && num - lastPrime == 2) {
                  ++twinCount;
              }
              lastPrime = num;
              firstFound = true;
          }
      }
    return twinCount;
  }
