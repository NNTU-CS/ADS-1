// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false; 
  if (value == 2) return true; 
  if (value % 2 == 0) return false;
  for (uint64_t i = 3; i * i <= value; i += 2) {
    if (value % i == 0) {
      return false; 
    }
  }
  return true;
} 
uint64_t nPrime(uint64_t n) {
  if (n < 1) return 0; 
  uint64_t count = 0; 
  uint64_t num = 1; 
  while (count < n) {
    num++;
    bool isPrime = (num > 1); 
    for (uint64_t i = 2; isPrime && (i * i <= num); i++) {
      if (num % i == 0) isPrime = false; 
    }
    if (isPrime) count++;
  }
  return num; 
}
uint64_t nextPrime(uint64_t value) {
  if (value < 2) return 2; // Первое простое число
  while (true) {
    value++;
    bool isPrime = true;
    for (uint64_t i = 2; i * i <= value; i++) {
      if (value % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) return value;
  }
} 
uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t num = 2; num < hbound; num++) {
    bool isPrime = true;
    for (uint64_t i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) sum += num;
  }
  return sum;
} 
uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;

  for (uint64_t i = (lbound < 2 ? 2 : lbound); i < hbound - 1; ++i) {
    bool isPrimeI = true, isPrimeN = true;

    for (uint64_t j = 2; j * j <= i || j * j <= (i + 2); ++j) {
      if (i % j == 0) isPrimeI = false;
      if ((i + 2) % j == 0) isPrimeN = false;
    }

    if (isPrimeI && isPrimeN) count++;
  }
  return count;
}

