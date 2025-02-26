// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  for (int i = 2; i * i <= value; i++) {
    if (value % i == 0) {
        return false;
    }
  }
}

uint64_t nPrime(uint64_t n) {
  const int SIZE = 100 * 1000;
  const int N = 9500;
  int a[SIZE];
  for (int i = 2; i < SIZE; ++i)
      a[i] = 1;
  int k = 1;
  int p = 2;
  while (k < n) {
      for (int i = 2 * p; i < SIZE; i += p)
          a[i] = 0;
      for (int i = p + 1; i < SIZE; ++i)
          if (a[i] == 1) {
              p = i;
              break;
          }
      ++k;
  }
  return p;
}

#define SIZE 100
uint64_t nextPrime(uint64_t value) {
  std::vector<int> np;
  std::vector<int> isprime;
  int i = 0;
  
  for (int k = value + 1; k < value + 200; k++) {
      np.push_back(k);
  }
  for (int j : np) {
      bool val_is_prime = true;
      if (j <= 1) {
          val_is_prime = false;
      }
      else {
          val_is_prime = checkPrime(j);
      }
      if (val_is_prime) {
          isprime.push_back(j);
      }
  }
  return *std::min_element(isprime.begin(), isprime.end());
}

uint64_t sumPrime(uint64_t hbound) {
  int sum = 0;
  for (int i = 0; i < hbound; i++) {
      if (checkPrime(i)) {
          sum += i;
      }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  std::vector<bool> prime(hbound + 1, true);
  prime[0] = prime[1] = false;
  int temp = 0;
  int m = 0;
  int count = 0;
  for (int i = 3; i < hbound + 1; i += 2) {
      if (!prime[i]) {
          continue;
      }
      if (i >= lbound) {
          if (temp && (i - temp == 2)) {
              count++;
          }
          temp = i;
      }
      for (int j = i * i; j < hbound + 1; j += i) {
          prime[j] = false;
      }
  }
  return count;
}
