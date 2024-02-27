// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value > 1) {
        for (int i = 2; i <= value / 2; i++) {
            if (value % i == 0) {
                return 0;
            }
        }
    return 1;
    } else {
    return 0;
    }
}

uint64_t nPrime(uint64_t n) {
    uint64_t k = 2;
    uint64_t chislo = 0;
    while (n != 0) {
        if (checkPrime(k) == true) {
            n--;
            chislo = k;
        }
        k++;
    }
    return chislo;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t k = value;
    uint64_t chislo = 0;
    uint64_t timer = 1;
    while (timer != 0) {
        k++;
        if (checkPrime(k) == true) {
            timer--;
            chislo = k;
        }
    }
    return chislo;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t res = 0;
    for (int i = 2; i < hbound; i++) {
        if (checkPrime(i) == true) {
            res += i;
        }
    }
    return res;
}
