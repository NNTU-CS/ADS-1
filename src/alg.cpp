// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value % 2 == 0) {
        return false;
  }

  for (int i = 3; i < sqrt(value); i += 2) {
      if (value % i == 0) {
          return false;
      }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 1){
    return 2;
  }
  uint64_t count = 1;
  uint64_t num = 3;
  
  while (count < n) {
      bool isPrime = true;
      for (uint64_t i = 2; i <= std::sqrt(num); i++) {
          if (num % i == 0) {
              isPrime = false;
              break;
          }
      }
      if (isPrime) {
        count++;
      }
      if (count < n) {
        num += 2;  
      }
  }
}

uint64_t nextPrime(uint64_t value) {
  uint64_t num = value + 1;
  while (!checkPrime(num)) {
        num++;
    }
  return num;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  uint64_t predPrime = 0;
  for (uint64_t i = lbound; i < hbound; i++) {
    if (checkPrime(i)) {
      if (predPrime != 0 && i - predPrime == 2) {
        ++count;
      }
      predPrime = i;
    }
  }
  return count;
}
