// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cmath>


bool checkPrime(uint64_t value) {
    if (value == 0 || value == 1) {
        return false;
    }
    for (uint64_t i = 2; i <= sqrt(value); i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t primeCount = 0;
    for (uint64_t currentNumber = 2; true; ++currentNumber) {
        if (checkPrime(currentNumber)) {
            primeCount++;
        }
        if (primeCount == n) {
            return currentNumber;
        }
    }
}

uint64_t nextPrime(uint64_t value) {
    uint64_t currentNumber = value + 1;
    while (!checkPrime(currentNumber)) {
        currentNumber++;
    }
    return currentNumber;
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
