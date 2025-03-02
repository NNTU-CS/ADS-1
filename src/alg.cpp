//Copyright [2025] <Copyright Alexey Efimov>
#include <iostream>
#include <vector>
#include "alg.h"


bool checkPrime(uint64_t value) {
    for (int i = 2; i < value; i++) {
        if (value % i == 0) {
      return false;
    }
  }
  return true;
}
uint64_t nPrime(uint64_t n) {
  int createArrOfPrimes(int c) {
    std::vector<int> x;
        for (int i = 2; i <= c; i++) {
            if (checkPrime(i)) {
        x.push_back(i);
      }
    }
    return x;
  }

  int b = createArrOfPrimes(10000);
    for (size_t i = 0; i < b.size(); i++) {
        if (i == n) {
      return b[i];
    }
  }
  return -1;
}

uint64_t nextPrime(uint64_t value) {
  value++;
    while (!checkPrime(value)) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  int counter = 0;
    for (int i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
      counter += i;
    }
  }
  return counter;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  std::vector<int> x;
  int counter = 0;

    for (int i = lbound; i <= hbound; i++) {
        if (checkPrime(i)) {
      x.push_back(i);
    }
  }

    for (int i = 0; i < x.size() - 1; i++) {
        if (x[i+1] - x[i] == 2) {
      counter++;
    }
  }

  return counter;
}
