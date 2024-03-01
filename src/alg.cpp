// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
    if (value <= 1) {
        return false;
    }
    for (int i = 2; i <= value / 2; ++i) {
        if ((value % i == 0)) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
    uint64_t count = 0;
    uint64_t num = 2;
    while (count < n) {
        if (checkPrime(num)) {
            ++count;
        }
        ++num;
    }
    return num - 1;
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
    uint64_t next = value + 1;
    while (true) {
        if (checkPrime(next)) {
            return next;
        }
        next++;
    }
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
    uint64_t sum = 0;
    for (uint64_t num = 2; num < hbound; num++) {
        bool isPrime = true;
            for (uint64_t divs = 2; divs <= num / 2; divs++) {
                if (num % divs == 0) {
                    isPrime = false;
                    break;
                }
            }
        if (isPrime) {
            sum += num;
        }
    }
    return sum;
}
