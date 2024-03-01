// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cmath>


bool checkPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    for (uint64_t i = 2; i <= pow(value, 0.5); i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t c = 0;
    uint64_t num = 1;
    while (c < n) {
        bool k = true;
        num++;
        for (uint64_t i = 2; i <= pow(num, 0.5); i++) {
            if (num % i == 0) {
                k = false;
                break;
            }
        }
        if (k == true) {
            c++;
        }
    }
    return num;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t num = value;
    while (true) {
        bool k = true;
        num++;
        for (uint64_t i = 2; i <= pow(num, 0.5); i++) {
            if (num % i == 0) {
                k = false;
                break;
            }
        }
        if (k == true) {
            return num;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t num = 2;
    uint64_t count = 0;
    while (num < hbound) {
        bool k = true;
        for (uint64_t i = 2; i <= pow(num, 0.5); i++) {
            if (num % i == 0) {
                k = false;
                break;
            }
        }
        if (k == true) {
            count += num;
        }
        num++;
    }
    return count;
}
