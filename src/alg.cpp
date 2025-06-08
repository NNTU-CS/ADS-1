// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include "PrimeLibrary.h"
bool PrimeLibrary::checkPrime(uint64_t value) {
    if (value < 2) return false;
    for (uint64_t i = 2; i <= sqrt(value); ++i) {
        if (value % i == 0) return false;
    }
    return true;
}
uint64_t PrimeLibrary::nPrime(uint64_t n) {
    if (n < 1) return 0;
    uint64_t count = 0;
    uint64_t number = 1;
    while (count < n) {
        ++number;
        if (checkPrime(number)) {
            ++count;
        }
    }
    return number;
}
uint64_t PrimeLibrary::nextPrime(uint64_t value) {
    do {
        ++value;
    } while (!checkPrime(value));
    return value;
}
uint64_t PrimeLibrary::sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
uint64_t PrimeLibrary::twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;
    uint64_t lastPrime = 0;
    for (uint64_t i = lbound; i < hbound; ++i) {
        if (checkPrime(i)) {
            if (lastPrime != 0 && i - lastPrime == 2) {
                ++count;
            }
            lastPrime = i;
        }
    }
    return count;
}
