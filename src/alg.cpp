// Copyright 2022 NNTU-CS
#include "alg.h"
bool checkPrime(uint64_t value) {
    bool isPrime = true;
    if (value == 1 || value == 4 || value == 0) {
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
    uint64_t p = 0;
    for (uint64_t i = 2; i < 100000000; i++) {
        if (checkPrime(i) == true) {
            p++;
        }
        if (p == n) {
            return i;
        }
    }
    return 0;
}
uint64_t nextPrime(uint64_t value) {
    for (uint64_t i = value + 1; i < 10000000; i++) {
        if (checkPrime(i) == true) {
            return i;
        }
    }
    return 1;
}
uint64_t sumPrime(uint64_t hbound) {
    uint64_t summ = 0;
    for (uint64_t i = 1; i <= hbound; i++) {
        if (checkPrime(i) == true) {
            summ += i;
        }
    }
    return summ;
}
