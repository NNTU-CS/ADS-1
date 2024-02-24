// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value > 1) {
        for (int i = 2; i < value / 2 + 1; i++) {
            if (value % i == 0) {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

uint64_t nPrime(uint64_t n) {
  int count = 0;
  uint64_t uPer = 2;
    while (true) {
        if (checkPrime(uPer)) {
            count++;
        }
        if (count == n) {
            return uPer;
        }
        uPer++;
    }
}

uint64_t nextPrime(uint64_t value) {
    uint64_t uPer = value + 1;
    while (!checkPrime(uPer)) {
        uPer++;
    }
    return uPer;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t result = 0;
    for (int i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            result += i;
        }
    }
    return result;
}
