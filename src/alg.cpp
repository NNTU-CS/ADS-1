// Copyright 2022 NNTU-CS
#include <cstdint>
#include <vector>

bool checkPrime(uint64_t num) {
  if (num < 2) return false;
  if (num < 4) return true;
  if (num % 2 == 0 || num % 3 == 0) return false;
  for (uint64_t i = 5; i * i <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t primeIndex) {
  if (primeIndex == 0) return 0;

  uint64_t primeCount = 0;
  uint64_t currentNumber = 1;

  while (primeCount < primeIndex) {
    currentNumber++;
    if (checkPrime(currentNumber)) {
      primeCount++;
    }
  }
  return currentNumber;
}

uint64_t nextPrime(uint64_t currentValue) {
  uint64_t nextCandidate = currentValue + 1;
  while (!checkPrime(nextCandidate)) {
    nextCandidate++;
  }
  return nextCandidate;
}

uint64_t sumPrime(uint64_t upperBound) {
  uint64_t primeSum = 0;
  for (uint64_t i = 2; i < upperBound; ++i) {
    if (checkPrime(i)) {
      primeSum += i;
    }
  }
  return primeSum;
}

uint64_t twinPrimes(uint64_t lowerBound, uint64_t upperBound) {
  if (upperBound < 3) return 0;

  uint64_t twinPrimeCount = 0;
  uint64_t previousPrime = 0;

  for (uint64_t i = lowerBound; i < upperBound; ++i) {
    if (checkPrime(i)) {
      if (previousPrime != 0 && i - previousPrime == 2) {
        twinPrimeCount++;
      }
      previousPrime = i;
    }
  }
  return twinPrimeCount;
}
