// Copyright 2022 NNTU-CS
#include <cmath>
#include <cstdint>

#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value == 1) {
    return false;
  }

  if (value == 2 || value == 3) {
    return true;
  }

  int sqrtValue = static_cast<int>(sqrt(value));

  for (int i = 2; i <= sqrtValue; i++) {
    if (value % i == 0) {
      return false;
    }
  }

  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t currentNumber = 2;

  while (n > 0) {
    if (checkPrime(currentNumber)) {
      n--;
    }
    currentNumber++;
  }

  return currentNumber - 1;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t currentNumber = value;
  bool flag = false;

  while (!flag) {
    currentNumber++;

    if (checkPrime(currentNumber)) {
      flag = true;
    }
  }

  return currentNumber;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  uint64_t currentNumber = hbound;

  while (currentNumber > 1) {
    if (checkPrime(currentNumber)) {
      sum += currentNumber;
    }

    currentNumber--;
  }

  return sum;
}
