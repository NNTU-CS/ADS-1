
// Copyright 2022 NNTU-CS
#include <cstdint>
#include <vector>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value <= 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;
  for (uint64_t i = 5; i * i <= value; i += 6) {
    if (value % i == 0 || value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 2;
  std::vector<uint64_t> primes;
  uint64_t num = 3;
  primes.push_back(2);
  while (primes.size() < n) {
    bool isPrime = true;
    for (uint64_t prime : primes) {
      if (prime * prime > num) break;
      if (num % prime == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      primes.push_back(num);
    }
    num += 2;
  }
  return primes[n - 1];
}

uint64_t nextPrime(uint64_t value) {
  for (uint64_t num = value + 1; ; ++num) {
    if (checkPrime(num)) return num;
  }
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound < 2) return 0;
  bool* checkPrime = new bool[hbound];
  if (!checkPrime) return 0;
  for (uint64_t i = 0; i < hbound; ++i) {
    checkPrime[i] = true;
  }
  checkPrime[0] = checkPrime[1] = false;
  for (uint64_t i = 2; i * i < hbound; ++i) {
    if (checkPrime[i]) {
      for (uint64_t j = i * i; j < hbound; j += i) {
        checkPrime[j] = false;
      }
    }
  }
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound - 2; ++i) {
    if (checkPrime[i] && checkPrime[i + 2]) {
      count++;
    }
  }
  delete[] checkPrime;  
  return count;
}
