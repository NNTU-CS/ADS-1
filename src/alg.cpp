// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
  if (value <= 1) {
    return false;
  }
  if (value == 2) {
    return true;
  }
  for (int i = 2; i < value; i ++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
  uint64_t counter = 0;
  uint64_t number = 1;
  while (counter < n) {
    number++;
    if (checkPrime(number)) {
      counter++;
        }
  }
  return number;
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
  uint64_t number = value + 1;
  while (!checkPrime(number)) {
    number++;
  }
  return number;
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}
