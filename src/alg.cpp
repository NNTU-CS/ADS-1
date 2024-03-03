// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
   if (number < 2) {
        return false;
    }
    for (uint64_t i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
  return true;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
   uint64_t count = 0;
    uint64_t num = 2;
  while (count < n) {
        if (isPrime(num)) {
            count++;
        }
        num++;
    }
  return num - 1;
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
   uint64_t result = 0;
  for (uint64_t n = value + 1; n <= INT64_MAX; n++) {
    if (checkPrime(i)) {
      result = n;
      break;
    }
  }
return result;
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
   uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
  return sum;
}
