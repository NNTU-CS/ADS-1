// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>


bool checkPrime(uint64_t value) {
  if (value <= 1) {
        return false;
  }
  for (uint64_t a = 2; a <= sqrt(value); a++) {
      if (value % a == 0) {
          return false;
      }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t num = 1;
  int x;
  if (n<=1) {
    return 2;
  }
  for (x=3;;x+=2) {
    if (checkPrime(x) {
        num++;
      }
    if (x==n) {
      return x;
    }
  }
}

uint64_t nextPrime(uint64_t value) {
  uint64_t num;
  for (num = value + 1;;x++) {
    if (checkPrime(num) {
        return num;
      }
  }
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound == 3) {
    return 2;
  }
  uint64_t summ = 2;
  uint64_t a;
  for (a = 3; a < hbound; a+=2) {
    if (checkPrime(a) == true) { 
      summ += a;
    }
  }
  return summ;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  uint64_t a;
  for (a = (lbound / 2) * 2 + 1; a < hbound - 2; a += 2) {
    if (checkPrime(a) && checkPrime(a + 2)) {
      count++;
    }
  }
  return count;
}
