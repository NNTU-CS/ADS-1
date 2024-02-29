// Copyright 2022 NNTU-CS
#include <cstdint>
#include <climits>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
    int count = 0;
    for (int i = 1; i < value + 1; i++) {
        if (value % i == 0) count++;
    }
    if (count == 2) {
        return true;
    } else {
        return false;
    }
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
    uint64_t i, j;
    int count2 = 0;
    for (i = 2; i < LLONG_MAX; i++) {
        int count1 = 0;
        for (j = 1; j < i + 1; j++) {
            if (i % j == 0) {
                count1++;
            }
        }
        if (count1 == 2) {
            count2++;
        }
        if (count2 == n) {
            return i;
        }
    }
    return 0;
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
    uint64_t i;
    for (i = value + 1; i < LLONG_MAX; i++) {
        if (checkPrime(i) == 1) {
            return i;
        }
    }
    return 0;
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
    uint64_t i, sum = 0;
    for (int i = 2; i < hbound; i++) {
        if (checkPrime(i) == 1) {
            sum += i;
        }
    }
    return sum;
}
