// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
for (int i = 2; i <= pow(value, 0.5); i++) {
        if (value % i == 0)
            return 0;
    }
    return 1;
}

uint64_t nPrime(uint64_t n) {
    int cnt = 0;
    uint64_t prime = 0;
    for (int i = 2; i < 1000000; i++) {
        if (checkPrime(i) == 1) {
            prime = i;
            cnt++;
            if (cnt == n)
                return prime;
        }
    }
    return 0;
}

uint64_t nextPrime(uint64_t value) {
    for (int i = value + 1; i < 1000000; i++) {
        if (checkPrime(i) == 1) {
            return i;
        }
    }
    return 0;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t summ = 0;
    for (int i = 2; i < hbound; i++) {
        if (checkPrime(i) == 1) {
            summ += i;
        }
    }
    return summ;
}

