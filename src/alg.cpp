// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value > 1) {
    int d = 2;
    while (d*d <= value) {
      if (value % d == 0)
        return false;
      else
        d++;
    }
    return true;
  } else {
    return false;
    }
}

uint64_t nPrime(uint64_t n) {
  uint64_t rowNum = 0, i = 2;
  while (rowNum != n) {
    if (checkPrime(i++))
     rowNum++;
  }
  return i-1;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2)
    return 2;
  if (checkPrime(value) == true)
    value++;
  while (checkPrime(value) != true) {
    if (value % 2 == 0)
      value++;
    else
     value += 2;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  if (hbound > 2)
    sum = 2;
  for (uint64_t i = 3; i < hbound; i += 2) {
    if (checkPrime(i))
      sum += i;
  }
  return sum;
}
