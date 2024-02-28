// Copyright 2022 NNTU - CS
#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value == 2) {
        return true;
    }
    for (uint64_t i = 2; i <= sqrt(value) + 1; i++)
        if (value % i == 0)
            return false;
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t k = 0;
    uint64_t m = 0;
    for (uint64_t i = 2; i <= 100000; i++) {
        if (checkPrime(i) == true)
            k += 1;
        if (k == n) {
            m = i;
            break;
        }
    }
    return m;
}

uint64_t nextPrime(uint64_t value) {
    bool f = false;
    uint64_t i = value + 1;
    while (f != true) {
        if (checkPrime(i) == true) {
            f = true;
        } else {
            i++;
        }
    }
    return i;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t summa = 0;
    for (uint64_t i = 2; i < hbound; i++)
        if (checkPrime(i) == true)
            summa += i;
    return summa;
}
