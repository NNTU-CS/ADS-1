// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    bool flag = true;
    if (value < 2) {
        flag = false;
    }
    for (uint64_t i = 2; i < value; i++) {
        if (value % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

uint64_t nPrime(uint64_t n) {
    uint64_t result = 1;
    for (uint64_t i = 1; i <= n; i++) {
        for (uint64_t k = result + 1; k <= INT64_MAX; k++) {
            if (checkPrime(k)) {
                result = k;
                break;
            }
        }
    }
    return result;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t result = 0;
    for (uint64_t i = value + 1; i <= INT64_MAX; i++) {
        if (checkPrime(i)) {
            result = i;
            break;
            }
    }
    return result;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t result = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            result += i;
        }
    }
    return result;
}
