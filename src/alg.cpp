// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>


bool checkPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    for (int i = 2; i * i <= value; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t chislo = 2;
    uint64_t count = 0;
    while (count < n) {
        if (checkPrime(chislo) == true) {
            count++;
        }
    chislo++;
    }
    return (chislo - 1);
}

uint64_t nextPrime(uint64_t value) {
    uint64_t next = value + 1;
    while (true) {
        if (checkPrime(next)) {
            return next;
    }
    next++;
    }
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
