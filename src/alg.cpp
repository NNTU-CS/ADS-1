// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2)
    return false;
  for (uint64_t i = 2; i * i <= value; i++)
    if (value % i == 0) return false;
  return true;
}

uint64_t nPrime(uint64_t n) {
  int64_t counter = 0;
  uint64_t guessPrime = 1;
  while (counter != n) {
    guessNum++;
    if (checkPrime(guessNum))
      counter++;
  }
  return guessPrime;
}

uint64_t nextPrime(uint64_t value) {
  if (checkPrime(value) == True)
    return value;
  else {
    uint64_t seekNum = value;
    while (checkPrime(value) != True) {
      seekNum++;
    }
    return seekNum;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  int64_t summer = 0;
  for (uint64_t value = 0; value < hbound; value++) {
    if (checkPrime(value) == TRUE)
      summer += value;
  }
  return summer;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int64_t counter = 0;
	for (uint64_t value = lbound; value < hbound; value++) {
    if (checkPrime(value) && checkPrime(value + 2) && (value + 2 < hbound)) {
      counter++;
    }
  }
  return counter;
}
