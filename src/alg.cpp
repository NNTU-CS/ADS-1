// Copyright 2022 NNTU-CS
#include "alg.h"  
#include <cstdint>  
#include <cmath>    

bool checkPrime(uint64_t numberToTest) {
  if (numberToTest <= 1) return false;
  if (numberToTest == 2 || numberToTest == 3) return true;
  if (numberToTest % 2 == 0) return false;

  uint64_t upperBound = static_cast<uint64_t>(
      sqrt(static_cast<double>(numberToTest)));
  for (uint64_t checker = 3; checker <= upperBound; checker += 2) {
    if (numberToTest % checker == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t position) {
  if (position < 1) return 2;

  uint64_t primesFound = 0;
  uint64_t currentValue = 1;

  while (primesFound < position) {
    currentValue++;
    if (checkPrime(currentValue)) {
      primesFound++;
    }
  }
  return currentValue;
}

uint64_t nextPrime(uint64_t startingPoint) {
  uint64_t seekerValue = startingPoint + 1;
  while (!checkPrime(seekerValue)) {
    seekerValue++;
  }
  return seekerValue;
}

uint64_t sumPrime(uint64_t upperLimit) {
  uint64_t primeSum = 0;
  for (uint64_t candidate = 2; candidate < upperLimit; candidate++) {
    if (checkPrime(candidate)) {
      primeSum += candidate;
    }
  }
  return primeSum;
}

uint64_t twinPrimes(uint64_t lowerEdge, uint64_t upperEdge) {
  uint64_t twinCounter = 0;
  for (uint64_t baseNum = lowerEdge; baseNum < upperEdge - 2; baseNum++) {
    if (checkPrime(baseNum) && checkPrime(baseNum + 2)) {
      twinCounter++;
    }
  }
  return twinCounter;
}