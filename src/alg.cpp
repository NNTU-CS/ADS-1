// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
for (int i = 2; i < value; i++) {
        if (value % i == 0)
                return false;
        }
        return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t count = 0, x = 2;
    while (true) {
        uint64_t d = 2, md = x / 2;
        bool prostoe = true;
        while (d <= md) {
            if (x % d == 0) {
                prostoe = false;
                break;
            }
            d++;
        }
        if (prostoe) {
            count++;
            if (count == n)
                return x;
        }
        x++;
    }
}

uint64_t nextPrime(uint64_t value) {
    if (value <= 1)
        return 2;
    uint64_t next = value + 1;
    bool prostoe;
    while (true) {
        prostoe = true;
        for (uint64_t i = 2; i * i <= next; ++i) {
            if (next % i == 0) {
                prostoe = false;
                break;
            }
        }
        if (prostoe)
            return next;
        next++;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t num = 2; num < hbound; ++num) {
        bool is_prime = true;
        for (uint64_t i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            sum += num;
    }
    return sum;
}
