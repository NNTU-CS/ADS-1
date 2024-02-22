// Copyright 2024 NNTU-CS
#include <iostream>
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    for (int i = 2; i < value; ++i) {
        if (value % i == 0) {
           return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
  int value = 1;
  if (n == value)
    return 2;
  for (int i = 3; i < 10000; ++i) {
    bool k = true;
    for (int j = 2; j < i; ++j) {
      if (i % j == 0) {
        k = false;
        break;
      }
    }
    if (k) {
      value++;
      if (value == n) return i;
    }
  }
  return -1;
}

uint64_t nextPrime(uint64_t value) {
  for (int i = value + 1; i < 10000; ++i) {
    bool k = true;
    for (int j = 2; j < i; ++j) {
      if (i % j == 0) {
        k = false;
        break;
      }
    }
    if (k) {
      return i;
    }
  }
  return -1;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  if (hbound >= 2)
    sum = sum + 2;
  for (uint64_t i = 3; i < hbound; ++i) {
    bool l = true;
    for (int j = 2; j < i; ++j) {
      if (i % j == 0) {
        l = false;
        break;
      }
    }
    if (l) {
      sum = sum + i;
    }
  }
  return sum;
}
