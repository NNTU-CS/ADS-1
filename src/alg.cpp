// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath> 
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    for (uint64_t i = 2; i <= (uint64_t)sqrt(value); i++) {
        if (value % i == 0) {
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
