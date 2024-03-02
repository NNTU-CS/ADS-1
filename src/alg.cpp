// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    for (int i = 2; i < value; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int count = 0;
    int num = 2;
    while (true) {
        int del = 2;
        int max_del = num / 2;
        bool is_prime = true;
        while (del <= max_del) {
            if (num % del == 0) {
                is_prime = false;
                break;
            }
            del++;
        }
        if (is_prime) {
            count++;
            if (count == n)
                return num;
        }
        num++;
    }
}

uint64_t nextPrime(uint64_t value) {
    if (value <= 1) {
        return 2;
    }

    uint64_t num = (value % 2 == 0) ? value + 1 : value + 2;

    while (true) {
        bool isPrime = true;
        for (uint64_t i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            return num;
        }
        num += 2;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
    bool isPrime = true;
        for (uint64_t j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            sum += i;
        }
    }
    return sum;
}
