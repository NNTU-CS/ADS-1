// Copyright 2022 NNTU-CS
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    if (value == 2) {
        return true;
    }
    for (uint64_t i = 2; i < value; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t  nPer = 0;
    for (uint64_t i = 2; i < UINTMAX_MAX; i++) {
        if (checkPrime(i)) {
            nPer++;
        }
        if (n == nPer) {
            return i;
        }
    }
    return 0;
}

uint64_t nextPrime(uint64_t value) {
    for (uint64_t i = value+1; i < UINTMAX_MAX; i++) {
        if (checkPrime(i)) {
            return i;
        }
    }
    return 0;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t summa = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            summa = summa + i;
        }
    }
    return summa;
}
