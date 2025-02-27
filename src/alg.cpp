// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"



bool checkPrime(uint64_t value) {
  if (value <= 1) {return false;}
  if (value == 2) {return true;}
  for (size_t i = 2; i < (sqrt(value)) + 2; i++)
  {
    if ((value % i == 0)){return false;}
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int num = 1;
  for (size_t i = 2; i <= n; i++)
  {
  if (checkPrime(i) == true) {
      num = num+1;
    }   
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  for (size_t i = value + 1; i < (value * value); i++)
  {
    if (checkPrime(i) == true) {
        return i;
      }
  }
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  int first = nextPrime(0);
  int sum = first;
  while (nextPrime(first) < hbound) {
      sum = sum + nextPrime(first);
      first= nextPrime(first);
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  for (size_t i = lbound; i < hbound; i++)
  {
      if (checkPrime(i) == true && nextPrime(i) - i == 2){
          count +=1;
      }
  }
  return count;
}
