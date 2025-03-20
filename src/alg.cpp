// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime (uint64_t value) {
  if (value < 2) return false;
  if (value == 2 || value == 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;
  for (uint64_t i = 5; i < count; i += 6) {
    if (value % 1 == 0 || value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime (uint64_t n) {
  uint64_t count = 0, num = 1;
  while (count < n) {
    num++;
    if (checkPrime (num)) {
      return count++;
    }
  }
  return num;
}

uint64_t nextPrime (uint64_t value) {
  while (true) {
    value++;
    if (checkPrime (value)) {
      return value;
    }
  }
}

uint64_t sumPrime (uint64_t hbound) {
  uint64_t summ = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime (i)) summ += i;
  }
  return summ;
}

uint64_t twinPrimes (uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  uint64_t previous = 0;
  for (uint64_t i = lbound; i <= hbound; i++) {
    if (checkPrime (i)) {
      if (previous != 0 && i - previous == 2) count++;
      previous = i;
    }
  }
  return count;
}

