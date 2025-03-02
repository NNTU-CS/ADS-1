// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) return false;  
  for (uint64_t i = 2; i <= (sqrt(value)); i++) {
            if (value % i == 0) {
              return false;
          }
    }
  return true;
}

uint64_t nPrime(uint64_t n) {
    if (n <= 1) return 2;
    uint64_t currentPos = 1;
    uint64_t currentNum = 1; 
    while (currentPos < n) {
        currentNum++;
        if (checkPrime(currentNum)) {
            currentPos++;
        }
    }
  return currentNum;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t newNum = value+1;
    while (!checkPrime(newNum)) {
        newNum++;
    }
  return newNum;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sm = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
        sm+=i;
    }
  }
  return sm;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
    for (uint64_t i = lbound; i < hbound-2; i++) {
        if (checkPrime(i) && checkPrime(i+2)) {
            count++;
        }
    }
    return count;
}
