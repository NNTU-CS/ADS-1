// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value == 1) return false;

    bool isPrime = true;

    for (uint64_t i = 2; i < value; i++) {
        if (value % i == 0) isPrime = false;
        if (!isPrime) break;
    }

    return isPrime;
}

uint64_t nPrime(uint64_t n) {
    uint64_t j = 0;

    for (uint64_t i = 2; ; i++) {
        if (checkPrime(i)) j++;
        if (j == n) return i;
    }
}

uint64_t nextPrime(uint64_t value) {
    for (uint64_t i = value + 1; ; i++) {
        if (checkPrime(i)) return i;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;

    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) sum += i;
    }

    return sum;
}
