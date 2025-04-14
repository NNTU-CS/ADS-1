#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
  uint64_t koef = 0;
  for (int el = 1; el <= sqrt(value); el++) {
    if (value % el == 0) koef += 1;
  }
  if (koef == 1) {
    return true;
  } else {
    return false;
  }
}

uint64_t nPrime(uint64_t n) {
  uint64_t el = 0, a = 2;
  while (el < n) {
    if (checkPrime(a)) {
      el += 1;
    }
    a += 1;
  }
  return a - 1;
}

uint64_t nextPrime(uint64_t value) {
  value += 1;
  while (!checkPrime(value)) {
    value += 1;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t el = 2, sum = 0;
  while (el < hbound) {
    if (checkPrime(el)) {
      sum += el;
    }
    el += 1;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t koef = 0, a = lbound;
  while (a + 2 < hbound) {
    if (checkPrime(a) && checkPrime(a + 2)) {
      koef += 1;
    }
    a += 1;
  }
  return koef;
}
