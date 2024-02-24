// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"



bool checkPrime(uint64_t value) {
  if ((1 == value) || (0 == value)) return false;
  for (int i = 2; i * i <= value; i++) {
      if (0 == value % i) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t num = 0;
  if (1 == n)return 2;
  for (auto i = 2; i < 1000000; ++i) {
      if (checkPrime(i)) ++num;
      if (num == n)return i;
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  for (auto i = value+1; i < value + 30; ++i) {
      if (checkPrime(i))return i;
  }
  return 0;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  if ((1 == hbound) || (2 == hbound))return 0;
  for (auto i = 1; i < hbound; ++i) {
      if (checkPrime(i)) sum += i;
  }
  return sum;
}
