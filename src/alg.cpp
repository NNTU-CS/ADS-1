// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    for (int i = 2; i * i <= value; i++) {
        if (value % i == 0)
            return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int count = 0, value = 1;
    while (count < n) {
        value++;
        if (checkPrime(value)) {
            count++;
        }
    }
    return value;
}

uint64_t nextPrime(uint64_t value) {
    int next = value + 1;
    while (!checkPrime(next)) {
        next++;
    }
    return next;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (int i = 2; i < hbound; i++) {
        if (checkPrime(i))
            sum += i;
    }
    return sum;
}
