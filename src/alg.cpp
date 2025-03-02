ё// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }

  if (value == 2) {
    return true;
  }

  if (value % 2 == 0) {
    return false;
  }

  for (uint64_t i = 3; i * i <= value; i += 2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t var = 2;
  int res = 0;
  while (true) {
    if (checkPrime(var)) {
      res += 1;
    }
    if (res == n) {
      return var;
    }
    var += 1;
  }
}

uint64_t nextPrime(uint64_t value) {
  value++;

  if (value > 2 && value % 2 == 0) {
    value++;
  }

  while (true) {
    if (checkPrime(value)) {
      return value;
    }
    value++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;

  if (hbound > 2) {
    sum += 2;
  }

  for (uint64_t i = 3; i < hbound; i+=2) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;

  for (uint64_t i = lbound; i < hbound - 2; ++i) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      ++count;
    }
  }

  return count;
}
