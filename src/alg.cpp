// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 3) {
    if (value == 2) {
      return true;
    }
    return false;
  }
  uint64_t limit = value/2;
  for (int i = 2; i < limit; i++) {
    if (value % i == 0){
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  // вставьте код функции
  return 2;
}

uint64_t nextPrime(uint64_t value) {
  // вставьте код функции
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  // вставьте код функции
  return 2;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  // вставьте код функции
  return 1;
}
