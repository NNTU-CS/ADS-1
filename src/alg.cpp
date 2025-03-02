// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value == 2) return true;
  if (value % 2 == 0) return false;
  uint64_t limit = static_cast<uint64_t>(sqrt(value));
  for (uint64_t i = 3; i <= limit; i += 2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n <= 1) return 2;
  uint64_t currentNum = 2;
  uint64_t currentPos = 1;
  while (currentPos < n) {
    currentNum = nextPrime(currentNum);
    currentPos++;
  }
  return currentNum;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t newNum = (value < 2) ? 2 : value + 1;
  if (newNum % 2 == 0) newNum++;
  while (!checkPrime(newNum)) {
    newNum += 2;
  }
  return newNum;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
  uint64_t sm = 2;
  for (uint64_t i = 3; i < hbound; i += 2) {
    if (checkPrime(i)) {
      sm += i;
    }
  }
  return sm;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  uint64_t i = (lbound % 2 == 0) ? lbound + 1 : lbound;
  while (i < hbound - 2) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count++;
    }
    i += 2;
  }
  return count;
}
