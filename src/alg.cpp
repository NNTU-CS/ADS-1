// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  uint64_t count=0;
  for(uint64_t i=2; i<=sqrt(value);i++)
    {
      if (value % i == 0)
        count++;
    }
  if (count==0)
    return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count=0;
  uint64_t num=2;
  while (count!=n)
    {
      if (checkPrime(num))
        count++;
      num++;
    }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  // вставьте код функции
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  // вставьте код функции
  return 2;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  // вставьте код функции
  return 1;
}
