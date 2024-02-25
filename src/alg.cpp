// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  bool perem2 = true;
  if (value <= 1) {
    return false;
  }
  for (uint64_t k = 2; k <= value / 2; k++) {
    if (value % k == 0) {
      perem2 = false;
      break;
    }
  }
  return perem2;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;
  uint64_t number = 1;
  while (count < n) {
    number++;
    if (checkPrime(number)) {
      count++;
    }
  }
  return number;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t low = value - 1;
  uint64_t up = value + 1;
  while (true) {
    if (checkPrime(low)) {
      return low;
    } else if (checkPrime(up)) {
      return up;
    }
    low--;
    up++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t j = 2; j < hbound; j++) {
    bool perem3 = true;
    for (uint64_t k = 2; k <= j / 2; k++) {
      if (j % k == 0) {
        perem3 = false;
        break;
      }
    }
    if (perem3) {
      sum += j;
    }
  }
  return sum;
}
