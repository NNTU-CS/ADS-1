// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
    for (int i = 2; i < (uint64_t)(sqrt(value) + 1); i++) {
        if (value % i == 0)
            return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t c = 0;
    uint64_t i = 2;
    while (1) {
        if (checkPrime(i)) {
            c++;
            if (n == c) {
                return i;
                break;
            }
        }
        i++;
    }
}

uint64_t nextPrime(uint64_t value) {
    value++;
    while (1) {
        if (checkPrime(value)) {
            return value;
            break;
        } else {
            value++;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t s = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            s += i;
        }
    }
    return s;
}
