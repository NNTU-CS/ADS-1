// Copyright 2022 NNTU-CS
#include <cstdint>
#include <vector>

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value < 4) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;
  for (uint64_t i = 5; i * i <= value; i += 6) {
    if (value % i == 0 || value % (i + 2) == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  uint64_t count = 0, number = 1;
  while (count < n) {
    number++;
    if (checkPrime(number)) count++;
  }
  return number;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t candidate = value + 1;
  while (!checkPrime(candidate)) {
    candidate++;
  }
  return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) sum += i;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound < 3) return 0;
  uint64_t count = 0, prevPrime = 0;
  for (uint64_t i = lbound; i < hbound; ++i) {
    if (checkPrime(i)) {
      if (prevPrime != 0 && i - prevPrime == 2) {
        count++;
      }
      prevPrime = i;
    }
  }
  return count;
}
