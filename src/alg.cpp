// Copyright 2022 NNTU-CS
#include "alg.h"
#include <math.h>
#include <cstdint>

bool checkPrime(uint64_t value) {
    for (uint64_t i = 2; i <= sqrt(value); i++) {
        if (value % i == 0) {
      return false;
    }
  }
  return true;
}
uint64_t nextPrime(uint64_t value) {
    for (uint64_t i = value + 1; ; i++) {
        if (checkPrime(i)) {
      return i;
    }
  }
}
uint64_t nPrime(uint64_t n) {
  uint64_t count = 1, next = 2;
    for (;;) {
        if (count == n) {
      return next;
        } else {
        next = nextPrime(next);
        count++;
      }
    }
  }
uint64_t sumPrime(uint64_t hbound) {
    u_int64_t summary = 0, current = 2;
    for (; current < hbound;) {
      summary += current;
      current = nextPrime(current);
    }
    return summary;
  }
uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0, current = 2;
    if (lbound >= hbound) {
      return 0;
    }
    if (checkPrime(lbound)) {
      current = lbound;
    } else {
        current  = nextPrime(lbound);
      }
    while (current < hbound) {
        uint64_t first = current;
        uint64_t second = nextPrime(current);
        if (second >= hbound) {
          break;
        }
        if (second - first == 2) {
          count++;
          current = second;
        } else {
            current = second;
          }
        }
        return count;
      }
