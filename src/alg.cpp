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
  int position = 1;
  int num = 2;
    while (position < n) {
    num++;
      if (checkPrime(num)) {
      position++;
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  value++;
    while (!checkPrime(value)) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t one = 2;
  uint64_t counter = 0;
    while (one < hbound) {
    counter += one;
    one = nextPrime(one);
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
