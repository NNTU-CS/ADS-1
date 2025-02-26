// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include "math.h"


bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    for (uint64_t i = 2; i * i <= value; ++i) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t num = 2;
    uint64_t count = 0;
    while (count < n) {
        if (checkPrime(num)) {
            count += 1;
        }
        num++;
    }
    return num - 1;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t next = value + 1;
    while (!checkPrime(next)) {
        next++;
    }
    return next;
}

uint64_t sumPrime(uint64_t rbound) {
    if (rbound < 2) {
        return 0;
    }

    uint64_t sum = 0;
    for (uint64_t num = 2; num < rbound; num = nextPrime(num)) {
        sum += num;
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t rbound) {
    uint64_t count = 0;
    for (uint64_t i = lbound; i < rbound; i = nextPrime(i)) {
        if (nextPrime(i) - i == 2) count++;
    }
    return count;
}

