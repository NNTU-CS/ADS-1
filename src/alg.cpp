// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  for(int i = 2; i < (value + 2) / 2; i++) {
    if(value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int value = 2;
  int val_num = 1;
  while(val_num < n) {
    value++;
    if(checkPrime(value) == true) {
      val_num++;
    }
  }
  return value;
}

uint64_t nextPrime(uint64_t value) {
  value++;
  while(checkPrime(value) != true) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  int sum = 0;
  for(int i = 1; i < hbound; i++) {
    sum += nPrime(i);
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  for(int i = lbound; i < hbound; i = nextPrime(i)) {
    if((nextPrime(i) < hbound) && (nextPrime(i) - i == 2)) {
      count++;
    }
  }
  return count;
}

