// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value == 0 || value == 1){
    return false;
  }
  for (int i = 2; i < value / 2 + 1; i++) {
    if (value % i == 0){
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0; 
  uint64_t currNum = 1; 
  while (count < n) {
    currNum ++;
    if (checkPrime(currNum)) {
      count++;
    }
  }
  return currNum;
}

uint64_t nextPrime(uint64_t value) {
  value++;
  while (!checkPrime(value)) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; sum < hbound;i++) {
    if (checkPrime(i) ) {
      sum += i;
    }
    if (sum >= hbound) {
      return sum - i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (lbound; lbound < hbound;lbound++) {
    if (checkPrime(lbound) && checkPrime(lbound + 2)){
      count++;
    }
  }
  return count++;
}
