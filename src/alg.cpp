// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>
#include<cmath>

bool checkPrime(uint64_t value) {
  if (value < 2)
    return false;
  if (value % 2 == 0 && value > 2)
    return false;
  for (uint64_t i = 3; i <= sqrt(value); i += 2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t col = 0;
  uint64_t candidat = 1;

  while (col < n) {
    candidat++;
    if (checkPrime(candidat)) {
      col++;
    }
  }
  return candidat;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) return 2;

  uint64_t candidat = value;

  if (candidat % 2 == 0) {
    candidat++;
  } else {
    candidat += 2;
  }

  while (true) {
    if (checkPrime(candidat)) {
      return candidat;
    }
    candidat += 2;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  uint64_t candidat = 1;

  while (candidat < hbound) {
    candidat++;
    if (checkPrime(candidat)) {
      sum += candidat;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t col = 0;
  uint64_t candidat = lbound;

  while (candidat < hbound - 2) {
    if (checkPrime(candidat) && checkPrime(candidat + 2)) {
      col++;
    }
    candidat++;
  }
  return col;
}
