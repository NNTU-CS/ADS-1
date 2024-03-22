// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value == 1) return false;
    for (int i = 2; i < value; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int cur = 0;
    if (n == 1) return 2;
    for (int i = 2;; i++) {
        bool f = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                f = 0;
                break;
            }
        }
        if (f == 1) cur += 1;
        if (cur == n) return i;
    }
}

uint64_t nextPrime(uint64_t value) {
    int i = value + 1;
    for (i;; i++) {
        bool f = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                f = 0;
                break;
            }
        }
        if (f == 1) break;
    }
    return i;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        bool f = 1;
        for (uint64_t j = 2; j < i; j++) {
            if (i % j == 0) {
                f = 0;
                break;
            }
        }
        if (f == 1) sum += i;
    }
    return sum;
}
