// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  for (uint64_t i = 2; i < value; i++)
    if (value % i == 0)
      return false;
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t* array = new uint64_t[n]{};
  uint64_t counter = 0;
  for (uint64_t i = 2; array[n - 1] == 0; i++)
    if (checkPrime(i))
      array[counter++] = i;
  uint64_t res = array[n - 1];
  delete[] array;
  return res;
}

uint64_t nextPrime(uint64_t value) {
  for (uint64_t i = value + 1; ; i++)
    if (checkPrime(i))
      return i;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t res = 0;
  for (uint64_t i = 2; i < hbound; i++)
    if (checkPrime(i))
      res += i;
  return res;
}
