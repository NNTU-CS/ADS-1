// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    uint64_t counter = 0;
    for (uint64_t i = 1; i < value / 2 + 1; i++) {
        if (value % i == 0) {
            counter++;
        }
        if (counter > 1) {
            return false;
        }
    }
    return counter == 1;
}

uint64_t nPrime(uint64_t n) {
    uint64_t counter = 0;
    for (uint64_t i = 0; i < UINT64_MAX; i++) {
        if (checkPrime(i)) {
            counter++;
        }
        if (counter == n) {
            return i;
        }
    }
    // Если такого числа нет
    return -1;
}

uint64_t nextPrime(uint64_t value) {
    for (uint64_t i = value + 1; i < UINT64_MAX; i++) {
        if (checkPrime(i)) {
            return i;
        }
    }
    // Если такого числа нет
    return -1;
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
