// Copyright 2022 NNTU-CS
#include "alg.h"
#include "math.h"

bool checkPrime(uint64_t value) {
    for (uint64_t i = 2 ; i < sqrt(value+1) ; i++) {
        if (value % i != 0) {
            return true;
        } else {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t k = 0;
    for (uint64_t i = 2; k != n; i++) {
        uint64_t c = 0;
        for (uint64_t j = 2; j < sqrt(i+1) ; j++) {
            if (i % j == 0) {
                c++;
            }
        }
        if (c == 0) {
            k++;
            if (k == n) {
                return i;
            }
        }
    }
    return 0;
}

uint64_t nextPrime(uint64_t value) {
    for (uint64_t i = value+1 ;  value < i ; i++) {
        uint64_t k = 0;
        for (uint64_t j = 2; j < sqrt(i+1) ; j++) {
            if (i%j == 0) {
                k++;
            }
        }
        if (k == 0) {
            return i;
        }
    }
    return 0;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t su = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        uint64_t k = 0;
        for (uint64_t j = 2; j < sqrt(i+1); j++) {
            if (i % j == 0) {
                k++;
            }
        }
        if (k == 0) {
            su += i;
        }
    }
    return su;
}

