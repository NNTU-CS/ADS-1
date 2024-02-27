// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  for (unit64_t i = 2; i < value; i++) {
    if (value % i == 0){
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (checkPrime(n)){
    unit64_t count = 0;
    while (n != 1) {
      if (checkPrime(n)) {
        count++;
      }
      n--;
    }
    return count;
  }
}

uint64_t nextPrime(uint64_t value) {
  value +=1;
  while (!checkPrime(value)) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  unit64_t sum = 0;
  for (unit64_t = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum +=i;
    }
  }
  return sum;
}
