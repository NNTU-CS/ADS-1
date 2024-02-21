// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    for (uint64_t i = 2; i <= value / 2; i ++) {
        if (!(value % i)) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t counter = 1, number = 2;
    while (counter < n) {
        number += 1;
        if (checkPrime(number)) {
            counter += 1;
        }
    }
    return number;
}

uint64_t nextPrime(uint64_t value) {
    value += 1;
    while (!checkPrime(value)) {
        value += 1;
    }
    return value;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t summ = 0;
    for (uint64_t i = 2; i < hbound; i ++) {
        if (checkPrime(i)) {
            summ += i;
        }
    }
    return summ;
}
