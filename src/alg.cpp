// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2) return true;
  if (value % 2 == 0) return false;
  for (uint64_t i = 3; i * i <= value; i += 2) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  uint64_t count = 0;
  uint64_t num = 1;
  while (count < n) {
    num++;
    if (checkPrime(num)) {
      count++;
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) return 2;
  uint64_t candidate = value + 1;
  if (candidate % 2 == 0) {
    candidate++;
  }
  while (true) {
    if (checkPrime(candidate)) {
      return candidate;
    }
    candidate += 2;
  }
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
  uint64_t last_prime = 0;
  if (lbound <= 2) {
    if (hbound > 3 && checkPrime(3)) {
      last_prime = 3;
    }
    lbound = 3;
  } else if (lbound % 2 == 0) {
    lbound++;
    }
    for (uint64_t i = lbound; i < hbound; i += 2) {
      if (checkPrime(i)) {
        if (i - last_prime == 2) {
          count++;
        }
        last_prime = i;
     }
   }
   return count;
}
