// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    for (int i = 2; i * i <= value; i++) {
        if (value % i == 0) return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 1)  return 2;
    uint64_t cnt = 1;
    uint64_t number = 3;
    while (cnt < n) {
        if (checkPrime(number)) {
                cnt++;
        }
        if (cnt < n) {
                    number += 2;
        }
    }
    return number;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t next = value + 1;
    while (!checkPrime(next)) {
        next++;
    }
    return next;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (int i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
