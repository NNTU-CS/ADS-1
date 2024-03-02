// Copyright 2022 NNTU-CS
#include <cmath>
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  for (uint64_t i = 2; i <= sqrt(value); i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  bool flag = 0;
  uint64_t count = 0;
  uint64_t num = 3;
  uint64_t i = 1;
  if (n == 1) {
    return 2;
    flag == 1;
  }
  if (n == 2) {
    return 3;
    flag == 1;
  }
  while (flag !=1) {
    count = 0;
    for (uint64_t j = 2; j <= sqrt(num); j++) {
      if (num % j == 0) {
        count++;
      }
    }
    if (count == 0) {
      i++;
    }
    if ((i == n)) {
      flag = true;
      return(num);
    }
    num+=2;
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  bool flag = 0;
  uint64_t count = 0;
  uint64_t num = value+1;
  while (flag !=1) {
    count = 0;
    for (uint64_t j = 2; j <= sqrt(num); j++) {
      if (num % j == 0) {
        count++;
      }
    }
    if (count == 0) {
      return(num);
      flag = 1;
    }
    num++;
  }
  return 0;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t count = 0;
  uint64_t num = 3;
  uint64_t sum = 2;
  while (num < hbound) {
    count = 0;
    for (uint64_t j = 2; j <= sqrt(num); j++) {
      if (num % j == 0) {
        count++;
      }
    }
    if (count == 0) {
      sum+=num;
    }
    num+=2;
  }
  return sum;
}
