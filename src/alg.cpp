// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  if (value == 2 || value == 3) {
    return true;
  }
  if (value % 2 == 0 || value % 3 == 0) {
    return false;
  }
  for (int i = 5; i * i <= value; i += 6) {
    if (value % i == 0 || value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int number = 1;
  int count = 0;
  int index = 0;
  while (index != n) {
    for (int i = 1; i <= number; i++) {
      if (number % i == 0) {
        count++;
      }
    }
    if (count == 2) {
      index++;
    }
    number++;
    count = 0;
  }
  return number - 1;
}

uint64_t nextPrime(uint64_t value) {
  int number = value + 1;
  int count = 0;
  while (true) {
    for (int i = 1; i <= number; i++) {
      if (number % i == 0) {
        count++;
      }
    }
    if (count == 2) {
      break;
    }
    number++;
    count = 0;
  }
  return number;
}

uint64_t sumPrime(uint64_t hbound) {
  int sum = 0;
  for (int i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int pairs = 0;
  int oldPrime = nextPrime(lbound);
  for (int index = lbound; index < hbound; index++) {
    int count = 0;
    for (int i = 1; i <= index; i++) {
      if (index % i == 0) {
        count++;
      }
    }
    if (count == 2) {
      if (index - oldPrime == 2) {
        pairs++;
      }
      oldPrime = index;
    }
  }
  return pairs;
}
