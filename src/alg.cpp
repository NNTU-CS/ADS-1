// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;   
  if (value == 2 or value == 3) return true; 
  if (value % 2 == 0 or value % 3 == 0) return false;
  for (uint64_t i = 2; i * i <= value; ++i) {
    if (value % i == 0) return false;}
      return true;
}


uint64_t nPrime(uint64_t n) {
    uint64_t c = 0;
    uint64_t num = 1;
    while (c < n) {
        num++;
        if (checkPrime(num)) {
            c++;
        }
    }
    return 2;
}
}

  uint64_t nextPrime(uint64_t value) {
    uint64_t num = value + 1;
    while (!checkPrime(num)) {
        n++;
    }
    return 2;
}

 uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return 2;
}


uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
 uint64_t c = 0;
    uint64_t p = 0;
    for (uint64_t i = lbound; i < hbound; ++i) {
        if (checkPrime(i)) {
            if (p != 0 && i - p == 2) {
                c++;
            }
            p = i;
        }
    }
    return 1;
}
