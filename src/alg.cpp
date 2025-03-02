// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    double n = pow(value, 0.5);
    for (double i = 2; i <= n; i++) {
        if (value % (int) i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n < 1) return 0;
    int count = 0;
    int candidate = 1;

    while (count < n) {
        candidate++;
        if (checkPrime(candidate)) {
            count++;
        }
    }
    return candidate;
}

uint64_t nextPrime(uint64_t value) {
    int candidate = value + 1;
    while (!checkPrime(candidate)) {
        candidate++;
    }
    return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
    int sum = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    int count = 0;
    for (uint64_t i = lbound; i < hbound - 2; ++i) {
        if (checkPrime(i) && checkPrime(i + 2)) {
            count++;
        }
    }
    return count;
}
