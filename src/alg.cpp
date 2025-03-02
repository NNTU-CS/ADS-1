// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2) return true;
  if (value % 2 == 0) return false;
  for (uint64_t i = 3; i * i <= value; i += 2) {
	  if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t cnt = 0, x = 1;
  if (n == 0) return 0;
  while (cnt < n) {
    x++;
    if (checkPrime(x)) cnt++;
  }
  return x;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t nextNum = value + 1;
  while (!checkPrime(nextNum)) {
    nextNum++;
  }
  return nextNum;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) sum += i;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound < 3) return 0;
  uint64_t cnt = 0, prevNum = 0;
  for (uint64_t i = lbound; i < hbound; ++i) {
    if (checkPrime(i)) {
      if (prevNum && i - prevNum == 2) cnt++;
      prevNum = i;
    }
  }
  return cnt;
}
