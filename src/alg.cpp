// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }

    for (uint64_t test = 2; test * test <= value; ++test) {
        if (value % test == 0) {
            return false;
        }
    }

    return true;
}

uint64_t nPrime(uint64_t targetIndex) {
    uint64_t found = 0;
    uint64_t current = 1;

    while (found < targetIndex) {
        ++current;
        if (checkPrime(current)) {
            ++found;
        }
    }

    return current;
}

uint64_t nextPrime(uint64_t from) {
    uint64_t next = from + 1;

    while (!checkPrime(next)) {
        ++next;
    }

    return next;
}

uint64_t sumPrime(uint64_t upperLimit) {
    uint64_t sum = 0;

    for (uint64_t val = 2; val < upperLimit; ++val) {
        if (checkPrime(val)) {
            sum += val;
        }
    }

    return sum;
}

uint64_t twinPrimes(uint64_t low, uint64_t high) {
    uint64_t twinPairs = 0;
    uint64_t lastPrime = 0;

    for (uint64_t i = low; i < high; ++i) {
        if (checkPrime(i)) {
            if (lastPrime && i - lastPrime == 2) {
                ++twinPairs;
            }
            lastPrime = i;
        }
    }

    return twinPairs;
}
