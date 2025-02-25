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
  for (uint64_t i = 5; i * i <= value; i +=6) {
    if (value % i == 0|| value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;      
  uint64_t candidate = 2;
  while (count < n) {
    if (checkPrime(candidate)) {
      count++;       
      if (count == n) {
        return candidate;
      }
    }
    candidate++;       
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  for (uint64_t i = value+1; ; i ++) {
    if ( checkPrime(i) ) {
      return i;
    }
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t summa = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      summa += i;
    }
  }
  return summa;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound - 2; i++) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count++;
    }
  }
  return count;
}
