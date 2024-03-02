// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value <= 1)
        return false;
    for (int i = 2; i <= (value / 2); ++i) {
        if (value % i == 0)
            return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0)
        return 0;
    uint64_t dl1 = 2;
    uint64_t dl2 = 1;
    while (dl2 != n) {
        dl1++;
        if (checkPrime(dl1)) {
            dl2++;
        }
    }
    return dl1;
}

uint64_t nextPrime(uint64_t value) {
    value++;
    while (!(checkPrime(value))) {
        value++;
    }
    return value;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t summdl = 0;
    for (int i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            summdl = summdl + i;
        }
    }
    return summdl;
}
