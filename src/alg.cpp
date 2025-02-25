// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) {
  return false;
  }
    for (uint64_t i = 2; i * i <= value; i++) {
        if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int counter = 0;
  for (uint64_t i =2;i<=n;i++){
    if (checkPrime(i)) {
      counter++;
    }
  }
  return counter;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t i = value;
  do{
    i++;
  } while (!checkPrime(i));
  return i;
}

uint64_t sumPrime(uint64_t hbound) {
  int sum=0;
   for (uint64_t i=2;i<hbound;i++){
   if (checkPrime(i)) {
      sum+=i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int counter = 0;
    for (uint64_t i=lbound;i<hbound;i++){
    if (checkPrime(i) && checkPrime(i+2))
    counter++;
  }
  return counter;;
}
