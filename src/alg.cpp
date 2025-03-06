// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
  uint64_t koren = static_cast<uint64_t>(std::pow(value, 0.5)) + 1;
  for (uint64_t i = 2; i != koren; ++i) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t fl_n = 0;
  uint64_t prime;
  if (n < 2) {
    return false;
  }
  for (uint64_t j = 2; fl_n != n; ++j) {
    bool flag = true;
    uint64_t koren = static_cast<uint64_t>(std::pow(j, 0.5)) + 1;
    for (uint64_t i = 2; i != koren; ++i) {
      if (j % i == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      prime = j;
      ++fl_n;
    }
  }
  return prime;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t prime;
  if (value < 2) {
    return false;
  }
  for (uint64_t j = value + 1; ; ++j) {
    bool flag = true;
    uint64_t koren = static_cast<uint64_t>(std::pow(j, 0.5)) + 1;
    for (uint64_t i = 2; i != koren; ++i) {
      if (j % i == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      prime = j;
      return prime;
    }
  }
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t prime = 0;
  for (uint64_t j = 2; j != hbound; ++j) {
    bool flag = true;
    uint64_t koren = static_cast<uint64_t>(std::pow(j, 0.5)) + 1;
    for (uint64_t i = 2; i != koren; ++i) {
      if (j % i == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      prime += j;
    }
  }
  return prime;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t first_prime = static_cast<uint64_t>(-10);
  int koll = 0;
  for (uint64_t j = lbound; j != hbound; ++j) {
    bool flag = true;
    uint64_t koren = static_cast<uint64_t>(std::pow(j, 0.5)) + 1;
    for (uint64_t i = 2; i != koren; ++i) {
      if (j % i == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      if (first_prime == j - 2) {
        ++koll;
      }
      first_prime = j;
    }
  }
  return koll;
}
