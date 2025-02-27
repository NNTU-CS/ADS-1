// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <math.h>
bool checkPrime(uint64_t value) {
  for (uint64_t k = 2; k <= sqrt(value); k++) {
      if (value != 1) {
      if ((value % k == 0)) {
        return false;
      }
      else {
        return false;
      }
    }
  }
  return true;
}
uint64_t nPrime(uint64_t n) {
  int count = 0;
  uint64_t res = 0;
  uint64_t j = 0;
  for (j = 2; j < pow(n, 2); j++) {
    if (checkPrime(j) == true) count++;
    if (count == n) res = j;
  }
  return res;
}
uint64_t nextPrime(uint64_t value) {
  uint64_t count = 0;
  for (uint64_t m = value; m < pow(value, 2); m++) {
    if (checkPrime(m) == true) count = m;
  }
  return count;
}
uint64_t sumPrime(uint64_t hbound) {
  int sum = 0;
  uint64_t res = 0
  int count = 0;
  for (int j = 2; j < pow(hbound, 2); j++) {
    if (checkPrime(j) == true) {
      count++;
      sum += j;
      if (count == hbound) res = sum;
    }
  }
  return sum;
}
uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  for (int i = lbound; i <= hbound; i++) {
    if ((checkPrime(i) == true) && (checkPrime(i + 2) == true)) count++;
  }
  return count;
}
