// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
for (uint64_t a = 2; a <= sqrt(value); a++) {
        if (value % a == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
        uint64_t b = 0;
        for (uint64_t i = 2; i <= n; i++) {
            if (checkPrime(i)) {
                b = i;
            }
        }
        return b;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t next_prime = value + 1;
    while (true) {
        if (checkPrime(next_prime)) {
            return next_prime;
        }
        next_prime++;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t summ = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return summ;
}
