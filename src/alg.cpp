// Copyright 2022 NNTU-CS
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value <= 1)
        return false;
    if (value == 2)
        return true;
    if (value % 2 == 0)
        return false;

    for (uint64_t i = 3; i <= sqrt(value); i += 2) {
        if (value % i == 0)
            return false;
    }

    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 1)
        return 2;

    uint64_t count = 1;
    uint64_t num = 3;

    while (count < n) {
        if (checkPrime(num))
            count++;
        if (count == n)
            break;
        num += 2;
    }

    return num;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t num = value + 1;
    while (!checkPrime(num))
        num++;
    return num;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t num = 2; num < hbound; num++) {
        if (checkPrime(num))
            sum += num;
    }
    return sum;
}
