// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  for (uint64_t i = 2; i <= (value / 2); i++)
{
    if (value%i==0)
{
      return false;
    }
  }
  if (value==0 || value ==1)
{
    return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t value = 0;
  for (uint64_t i = 0; i < n; ++i)
{
    value += 1;
    while (checkPrime(value) != true)
{
      value += 1;
    }
  }
  return value;
}

uint64_t nextPrime(uint64_t value) {
  value += 1;
  while (checkPrime(value) != true)
{
    value += 1;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t value = 0;
  uint64_t sum = 0;
  for (uint64_t i = 0; i < (hbound-1); ++i)
{
    value += 1;
    while (checkPrime(value) != true)
{
      value += 1;
    }
    sum += value;
  }
  return sum;
  }

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i < (hbound-1); ++i)
{
    if (checkPrime(i) == true && checkPrime(i + 2) == true && i+2<hbound)
{
      count += 1;
    }
  }
  return count;
}
