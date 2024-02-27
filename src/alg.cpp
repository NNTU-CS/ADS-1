// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include "cmath"


bool checkPrime(uint64_t value) {
    for (uint64_t i = 2; i <= (sqrt(value)); i++) {
        if (value == 2) {
            return true;
        }
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t iCount = 0;
    for (uint64_t i = 2; i < 1000000; i++) {
        if (checkPrime(i)) {
            ++iCount;
        }
        if (iCount == n) {
            return i;
        }
    }
    return 0;
}


uint64_t nextPrime(uint64_t value) {
    while (true) {
        value++;
        if (checkPrime(value) == true) {
            return value;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t iBound = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i) == true) {
            iBound += i;
        }
    }
    return iBound;
}
