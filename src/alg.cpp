// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value == 0) {
        return false;
    }
    if (value < 4) {
        return true;
    }
    if (value % 2 == 0) {
        return false;
    }
    for (uint64_t i = 3; i < value / 2; i += 2) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}
uint64_t nPrime(uint64_t n) {
    if (n < 1) {
        return 0;
    }
    uint64_t number = 0, i = 2;
    while (true) {
        if (checkPrime(i)) {
            number++;
            if (number == n) {
                return i;
            }
        }
        i++;
    }
    return 0;
}

uint64_t nextPrime(uint64_t value) {
    while (true) {
        value++;
        if (checkPrime(value)) {
            return value;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound == 0) {
        return 0;
    }
    uint64_t sum = 0;
    for (uint64_t i = hbound - 1; i > 1; i--) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
