// Copyright 2022 NNTU-CS
#include <math.h>
#include "alg.h"



bool checkPrime(uint64_t value) {
    for (int i = 2; i <= sqrt(value); i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int f = 1;
    for (uint64_t i = 0; i < n; i++) {
        for (uint64_t j = f+1; j < (pow(2, 64)); j++) {
            if (checkPrime(j)) {
                f = j;
                break;
            }
        }
    }
    return f;
}

uint64_t nextPrime(uint64_t value) {
    for (uint64_t j = value + 1; j < (pow(2, 64)); j++) {
        if (checkPrime(j)) {
            value = j;
            break;
        }
    }
    return value;
}


uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
