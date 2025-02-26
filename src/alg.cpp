// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1)
    return false;
  else if (value == 2)
    return true;
  else if (value % 2 == 0)
    return false;
  else if (value >= 3) {
    for (uint64_t p = 3; p*p <= value; p += 2) {
      if (value % p == 0)
        return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t erin = 1;
  if (n < 1)
    return 0;
  else if (n == 1)
    return 2;
  else if (n > 1) {
    uint64_t andrey = 2;
    while(1){
      if(checkPrime(andrey)){
        if (erin == n)
          return andrey;
        erin++;
      }
      andrey++;
    }
  }
}

uint64_t nextPrime(uint64_t value) {
  if (value < 1)
    return 0;
  else if (value == 1)
    return 2;
  else if (value > 1) {
    while(1){
      value++;
      if (checkPrime(value))
        return value;
    }
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sumdohbound = 0;
  while (hbound > 0) {
    hbound--;
    sumdohbound += hbound;
  }
  return sumdohbound;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t schet = 0;
  if (lbound < 3)
    return 0;
  else if ((lbound >= 3) && (lbound < hbound)){
    while(lbound != hbound-2){
      if ((checkPrime(lbound) == 1) && (checkPrime(lbound+2) == 1))
        schet++;
      lbound++;
    }
    return schet++;
  }
}
