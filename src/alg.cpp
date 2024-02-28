// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include "cmath"


bool checkPrime(uint64_t value) {
    if (value > 1) {
        for (int i = 2; i < value; i++)
            if (value % i == 0)
                return false;
        return true;
    }
    return false;
}


uint64_t nPrime(uint64_t n) {
    if (n == 1)
        return 2;
    uint64_t count = 1;
    uint64_t num = 3;
    while (count < n) {
        bool is_prime = true;
        for (uint64_t i = 2; i <= (sqrt(num)); ++i) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            ++count;
        if (count == n)
            break;
        num += 1;
    }
    return num;
}

uint64_t nextPrime(uint64_t value) {
    if (value <= 1)
        return 2;
    uint64_t num = value + 1;
    if (num % 2 == 0)
        num++;
    while (true) {
        bool is_prime = true;
        for (uint64_t i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            return num;
        num += 1;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    if (hbound > 2)
        sum = 5;
    if (hbound == 2)
        sum = 2;

    for (uint64_t num = 2; num < hbound; ++num) {
        bool is_prime = true;
        if (num <= 1)
            is_prime = false;
        if (num % 2 == 0 || num % 3 == 0)
            is_prime = false;
        for (uint64_t i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            sum += num;
    }
    return sum;
}
