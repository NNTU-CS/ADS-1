// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  uint64_t count = 0;
  for (uint64_t i = 2; i <= sqrt(value); i++)
  {
    if (value % i == 0)
      count++;
  }
    if (count == 0)
        return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 1;
  uint64_t num = 2;
  while (count != n){
    num++;
    if (checkPrime(num)){
      count++;
    }
}
  return num;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t num = value + 1;
  while (!checkPrime(num)){
   num++;
  }
  return num;
 }

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t n = 2; n < hbound; n++){
    if (checkPrime(n))
      sum += n;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0, a = 2;
  for(uint64_t i = lbound; i < hbound; i++){
    if(checkPrime(i)){
      if(i - a == 2){
        count++;
      }
      a = i;
    }
  }
  return count;
}
