// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    bool flag = true;
    for (uint64_t i = 2; i <= value / 2; i++) {
        if (value % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

uint64_t nPrime(uint64_t n) {
    bool flag = true;
    uint64_t count = 0;
    uint64_t b = 0;
    for (uint64_t j = 2; count < n; j++) {
        if (checkPrime(j) == true) {
            count++;
            b = j;
        }
        flag = true;
    }
    return b;
}

uint64_t nextPrime(uint64_t value) {
    bool flag = true;
    uint64_t b = 0;
    for (uint64_t j = (value + 1); flag == true; j++) {
        if (checkPrime(j)) {
            b = j;
            break;
        } else {
            flag = true;
        }
    }
    return b;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t count = 0;
    for (uint64_t j = hbound - 2; j >= 2; j--) {
        if (checkPrime(j) && j > 1) {
            count += j;
        }
    }
    return count;
}
