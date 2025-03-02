#include <cstdint>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
  for (uint64_t i = 2; i <= sqrt(value); ++i) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
  uint64_t num = 2, count = 0;
  while (count <= n) {
    if (checkPrime(num)) {
      count++;
    }
    if (count == n) {
      break;
    } else {
      num++;
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
  uint64_t num = value + 1;
  while (!checkPrime(num)) {
    num++;
  }
  return num;
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
  uint64_t num = 2, sum = 0;
  while (num < hbound) {
    if (checkPrime(num)) {
      sum += num;
    }
    num++;
  }
  return sum;
}
