// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value == 1) {
    return false;
  }
  if ((value % 2 == 0) && (value != 2)) {
    return false;
  }
  if (value == 2) {
    return true;
  }
  for (int i = 3; i <= ((value / 2) + 1); i+=2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 1) {
    return 2;
  }
  int count = 1;
  for (uint64_t i = 3; ; i += 2) {
    if (checkPrime(i)) {
      count++;
    }
    if (count == n) {
      return i;
    }
  }
  return 4;
}

uint64_t nextPrime(uint64_t value) {
  if ((value % 2) == 0) {
    for (uint64_t i = value + 1; ; i += 2) {
      if (checkPrime(i)) {
        return i;
      }
    }
  } else {
    for (uint64_t i = value+2; ; i += 2) {
      if (checkPrime(i)) {
          return i;
        }
      }
    }
    return 4;
  }

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 2;
  if (hbound <= 2) {
      return 0;
    }
  if (hbound == 3) {
      return 2;
    }
  for (uint64_t i = 3; i < hbound; i += 2) {
    if (checkPrime(i)) {
        sum += i;
      }
    }
    return sum;
  }

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;
    uint64_t first_prime = 0;
  if ((lbound) % 2 == 0) {
    for (uint64_t i = lbound; i < hbound; i++) {
      if (checkPrime(i)) {
          first_prime = i;
          break;
        }
      }
    if (first_prime == 2) {
      for (uint64_t i = first_prime + 1; i < hbound; i += 2) {
        if (checkPrime(i)) {
          if (i - first_prime == 2) {
              count++;
            }
            first_prime = i;
          }
        }
    } else {
      for (uint64_t i = first_prime; i < hbound; i += 2) {
        if (checkPrime(i)) {
          if (i - first_prime == 2) {
                count++;
              }
              first_prime = i;
            }
          }
        }
  } else {
    for (uint64_t i = lbound; i < hbound; i++) {
      if (checkPrime(i)) {
              first_prime = i;
              break;
            }
          }
    if (first_prime == 2) {
      for (uint64_t i = first_prime + 1; i < hbound; i += 2) {
        if (checkPrime(i)) {
          if (i - first_prime == 2) {
                  count++;
                }
                first_prime = i;
              }
            }
    }  else {
      for (uint64_t i = first_prime; i < hbound; i += 2) {
        if (checkPrime(i)) {
          if (i - first_prime == 2) {
                    count++;
                  }
                  first_prime = i;
                }
              }
            }
          }
          return count;
        }
