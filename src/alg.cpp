// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value <= 1) return false;
    if (value <= 3) return true;
    if (value % 2 == 0 || value % 3 == 0) return false;
    for (uint64_t i = 5; i * i <= value; i += 6) {
        if (value % i == 0 || value % (i + 2) == 0) return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 1) return 2;
    uint64_t count = 1;
    uint64_t number = 1;
    while (count < n) {
        number += 2;
        if (checkPrime(number)) {
            ++count;
        }
    }
    return number;
}

uint64_t nextPrime(uint64_t value) {
    if (value <= 1) return 2;
    uint64_t prime = value;
    bool found = false;
    while (!found) {
        prime++;
        if (checkPrime(prime)) found = true;
    }
    return prime;
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
