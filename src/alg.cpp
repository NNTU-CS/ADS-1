// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cmath>


bool checkPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    for (uint64_t i = 2; i <= sqrt(value); i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t number = 2;
    uint64_t count = 0;
    while (true) {
        if (checkPrime(number)) {
            count++;
        }
        if (count == n) {
            return number;
        }
        number++;
    }
}

uint64_t nextPrime(uint64_t value) {
    uint64_t number = value + 1;
    while (!checkPrime(number)) {
        number++;
    }
    return number;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
