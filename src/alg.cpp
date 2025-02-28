// Copyright 2022 NNTU-CS
// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include "math.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  for (int i = 2; i <= sqrt(value); i++)
  if (value % i == 0) return false;
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t numt = 3;
  uint64_t inum = 2;
  if (n == 1) return 2;
  if (n == 2) return 3;
  while (true) {
    numt++;
    if (checkPrime(numt)) inum++;
    if (inum == n) return numt;
  }
}

uint64_t nextPrime(uint64_t value) {
  uint64_t nextTemp = value;
  while (true) {
    nextTemp++;
    if (checkPrime(nextTemp)) return nextTemp;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sumn = 2;
  uint64_t nextT = 2;
  while (nextT != hbound) {
    nextT++;
    if (checkPrime(nextT)) sumn += nextT;
  }
  return sumn;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t icountTwin = 0;
  for (int i = lbound; i < (hbound - 2); i++) {
    if (checkPrime(i) && checkPrime(i + 2)) icountTwin++;
  }
  return icountTwin;
}
