// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  uint64_t count_divisors = 2;

  for (uint64_t i = 2; i < value; ++i) {
    if (value % i == 0) {
      count_divisors++;
    }
  }

  return count_divisors == 2 && value != 1;
}

uint64_t nPrime(uint64_t n) {
  uint64_t indx = 1;
  uint64_t res = 2;

  while (indx != n) {
    res++;
    while (true) {
      if (checkPrime(res)) {
        indx++;
        break;
      }

      res++;
    }
  }

  return res;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t res = 0;

  while (true) {
    value++;
    if (checkPrime(value)) {
      res = value;
      break;
    }
  }

  return res;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t total = 0;

  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) {
      total += i;
    }
  }

  return total;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t first_number_pair = 0;
  uint64_t second_number_pair = 0;
  uint64_t res = 0;

  for (uint64_t i = lbound; i < hbound; ++i) {
    if (checkPrime(i)) {
      if (!first_number_pair) {
        first_number_pair = i;
        continue;
      }

      second_number_pair = i;
      if (second_number_pair - first_number_pair == 2) {
        res++;
      }

      first_number_pair = second_number_pair;
    }
  }

  return res;
}
