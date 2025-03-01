// Copyright 2022 NNTU-CS
#include <cstdint>
#include <vector>

#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2 || value == 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;

  for (uint64_t i = 5; i * i <= value; i += 6) {
    if (value % i == 0 || value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;

  std::vector<uint64_t> primes;
  uint64_t num = 2;

  while (primes.size() < n) {
    bool isPrime = true;
    for (uint64_t p : primes) {
      if (p * p > num) break;
      if (num % p == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      primes.push_back(num);
    }
    ++num;
  }

  return primes[n - 1];
}

uint64_t nextPrime(uint64_t value) {
  uint64_t num = value + 1;
  while (true) {
    if (checkPrime(num)) return num;
    ++num;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound < 2) return 0;

  std::vector<bool> is_prime(hbound, true);
  is_prime[0] = is_prime[1] = false;

  for (uint64_t i = 2; i * i <= hbound; ++i) {
    if (is_prime[i]) {
      for (uint64_t j = i * i; j < hbound; j += i) {
        is_prime[j] = false;
      }
    }
  }

  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (is_prime[i]) {
      sum += i;
    }
  }

  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  uint64_t prev = 0;

  for (uint64_t i = lbound; i <= hbound; i++) {
    if (checkPrime(i)) {
      if (prev != 0 && i - prev == 2) {
        count++;
      }
      prev = i;
    }
  }

  return count;
}
