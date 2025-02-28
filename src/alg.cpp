// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2)
    return false;
  for (int i = 2; i*i <=value ; i++)
    if (value % i == 0)
      return false;
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;
  uint64_t check = 0;
  uint64_t* res = new uint64_t[n]{ 0 };
  while (count<n) {
    check++;
    if (checkPrime(check)) {
      res[count] = check;
      count++;
    }
  }  
  uint64_t result = res[n-1];
  return result;
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
  for (int i = 0; i < hbound; i++)
    if (checkPrime(i))
      sum += i;
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound-2; i++) {
    if (checkPrime(i) && checkPrime(i + 2))
      count++;
  }
  return count;
}
