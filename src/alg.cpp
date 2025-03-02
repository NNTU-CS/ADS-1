// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  for (uint64_t i = 2; i <= value / 2; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t cnt = 0;
  uint64_t num = 2;
  while (cnt < n) {
    bool prost_or_not = true;
    for (uint64_t i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
          prost_or_not = false;
          break;
        }
    }
    if (prost_or_not) {
      cnt++;
    }
    num++;
  }
  return num-1;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t next_num = value + 1;
  while (true) {
    bool prost_or_not = true;
    for (uint64_t i = 2; i <= next_num / 2; i++) {
      if (next_num % i == 0) {
        prost_or_not = false;
        break;
      }
    }
    if (prost_or_not) {
      return next_num;
    }
    next_num++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    bool prost_or_not = true;
    for (uint64_t j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        prost_or_not = false;
        break;
      }
    }
    if (prost_or_not) {
        sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t cnt = 0;
  for (uint64_t i = lbound; i < hbound - 1; i++) {
    bool num1 = true;
    bool num2 = true;
      for (uint64_t j = 2; j <= i / 2; j++) {
        if (i % j == 0) {
          num1 = false;
          break;
        }
      }
      for (uint64_t j = 2; j <= (i + 2) / 2; j++) {
        if ((i + 2) % j == 0) {
          num2 = false;
          break;
        }
      }
      if (num1 && num2 && (i + 2) < hbound) {
        cnt++;
      }
  }
  return cnt;
}
