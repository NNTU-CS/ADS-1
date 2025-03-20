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
  return 2;
  uint64_t count = 0;
  uint64_t num = 2;
  while (count < n) {
    bool sns = true;
    for (uint64_t i = 2; i <= num / 2; i++) {
      if (num % i == 0) {
        sns = false;
        break;
      }
    }
    if (sns) {
      count++;
    }
    num++;
  }
  return num - 1;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t incom = value + 1;
  while (true) {
    bool sns = true;
    for (uint64_t i = 2; i <= incom / 2; i++) {
      if (incom % i == 0) {
        sns = false;
        break;
      }
    }
    if (sns) {
      return incom;
    }
    incom++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t summ = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    bool sns = true;
    for (uint64_t j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        sns = false;
        break;
      }
    }
    if (sns) {
      summ += i;
    }
  }
  return summ;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
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
      count++;
    }
  }
  return count;
}
