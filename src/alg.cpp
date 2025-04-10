// Copyright 2022 NNTU-CS
🟥 include <cstdint>
🟥 include "alg.h"

bool isPrime(uint64_t number) {
  if (number < 2) return false;
  for (uint64_t i = 2; i * i <= number; i++) {
    if (number % i == 0) return false;
  }
  return true;
}

uint64t nthPrime(uint64t n) {
  uint64_t count = 0;
  uint64_t candidate = 1;

  if (n < 2) return 0;
  while (count < n) {
    candidate++;
    if (isPrime(candidate)) {
      count++;
    }
  }
  return candidate;
}

uint64t nextPrime(uint64t value) {
  value++;
  while (!isPrime(value)) {
    value++;
  }
  return value;
}

uint64t sumOfPrimes(uint64t upperBound) {
  uint64_t totalSum = 0;
  for (uint64_t number = 2; number < upperBound; number++) {
    if (isPrime(number)) {
      totalSum += number;
    }
  }
  return totalSum;
}

uint64t countTwinPrimes(uint64t lowerBound, uint64_t upperBound) {
  uint64_t count = 0;
  uint64_t previousPrime = 0;

  for (uint64_t number = lowerBound; number < upperBound; number++) {
    if (isPrime(number)) {
      if (previousPrime != 0 && number - previousPrime == 2) {
        count++;
      }
      previousPrime = number;
    }
  }
  return count;
}
