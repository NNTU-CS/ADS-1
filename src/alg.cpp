// Copyright 2022 NNTU-CS
#include "alg.h"


bool checkPrime(uint64_t value) {
    bool isPrime = true;
    if (value == 0 || value == 1 || value == 4) {
        isPrime = false;
    } else {
        for (int i = 2; i < value / 2; i++) {
            if (value % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}

uint64_t nPrime(uint64_t n) {
    uint64_t s = 0;
    for (uint64_t i = 2; i < 10000000; i++) {
        if (checkPrime(i) == true) {
            s++;
        }
        if (s == n) {
            return i;
        }
    }
    return 12;
}

uint64_t nextPrime(uint64_t value) {
    for (uint64_t i = value + 1; i < 10000000; i++) {
        if (checkPrime(i) == true) {
            return i;
        }
    }
    return 21;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 1; i <= hbound; i++) {
        if (checkPrime(i) == true) {
            sum += i;
        }
    }
    return sum;
}
