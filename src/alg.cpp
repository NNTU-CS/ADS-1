// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value == 1) return false; 
  for (uint64_t k = 2; k*k <= value; k++) {
      if (value % k == 0) return false;
  }
  return true;
}
uint64_t nPrime(uint64_t n) {
  uint64_t next = 1;
  uint64_t count = 0;
  while (count != n){
      next += 1;
      if (checkPrime(next)) count++;
  }
  return next;
}
uint64_t nextPrime(uint64_t value) {
  uint64_t counter = value + 1;
  while (checkPrime(counter) == false) {
      counter++;
  }
  return counter;
}
uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  uint64_t count = 2;
  while (count != hbound) {
      if (checkPrime(count) == true) {
          sum += count;
      }
      count++;
  }
  return sum;
}
uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t per = lbound;
  uint64_t count = 0;
  while (per != hbound) {
      if ((checkPrime(per) == true) && (checkPrime(per + 2) == true)) count++;
      per++;
  }
  return count - 1;
}
