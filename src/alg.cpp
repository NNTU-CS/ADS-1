// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool CheckPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    if (value == 2) {
        return true;
    }
    for (uint64_t i = 2; i * i <= value; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t count = 0;
    uint64_t number = 2;
    while (true) {
        if (CheckPrime(number)) {
            ++count;
            if (count == n) {
                return number;
            }
        }
        ++number;
    }
}

uint64_t NextPrime(uint64_t value) {
    uint64_t next = value + 1;
    while (!CheckPrime(next)) {
        ++next;
    }
    return next;
}

uint64_t SumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (CheckPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
