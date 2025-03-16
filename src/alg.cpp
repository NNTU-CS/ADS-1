// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    if (value == 2 || value == 3) {
        return true;
    }
    if (value % 2 == 0) {
        return false;
    }
    uint64_t limit = static_cast<uint64_t>(std::sqrt(value));
    for (uint64_t i = 3; i <= limit; i += 2) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0;
    uint64_t count = 0;
    uint64_t candidate = 1;
    while (count < n) {
        candidate++;
        if (checkPrime(candidate)) {
            count++;
        }
    }
    return candidate;
}

uint64_t nextPrime(uint64_t value) {
    value++;
    while (!checkPrime(value)) {
        value++;
    }
    return value;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    if (lbound > hbound || hbound < 3) {
        return 0;
    }
    uint64_t count = 0;
    uint64_t start = (lbound < 2) ? 2 : lbound;
    for (uint64_t p = start; p + 2 <= hbound; p++) {
        if (checkPrime(p) && checkPrime(p + 2)) {
            count++;
        }
    }
    return count;
}
