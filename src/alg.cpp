// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
}

for (uint64_t i = 2; i+i <= value; i++) {
    if (value % i == 0) {
        return false;
    }
}

return true;
}

uint64_t nPrime(uint64_t n) {
if (n <= 0) {
    return 0;
  }

uint64_t cnt = 0;
uint64_t num = 2;

while (cnt < n) {
    if (checkPrime(num)) {
        ++cnt;
    }
    ++num;
}

return num - 1;
}

uint64_t nextPrime(uint64_t value) {
    for (uint64_t i = value+1;; ++i) {
        if (checkPrime(i)) {
            return i;
            break;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t rez = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            rez += i;
        }
    }
    return rez;
}
