// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  int flag = 0;
  for (int i = 2; i < value; i++) {
    if (value % i == 0) {
        flag = 1;
        break;
    }
  }
  if (flag == 1)
    return false;
  else
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 1) return 2;
    uint64_t count = 1;
    uint64_t num = 3;
    while (count < n) {
        bool isPrime = true;
        for (uint64_t i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            count++;
            if (count == n) return num;
        }
        num += 2;
    }
    return 0;
}

uint64_t nextPrime(uint64_t value) {
  int a = value + 1;
  while (1) {
    if (checkPrime(a)) {
      return a;
    }
    a++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t num = 2; num < hbound; ++num) {
        bool isPrime = true;
        for (uint64_t i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            sum += num;
        }
    }
    return sum;
}
