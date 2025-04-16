#include <iostream>
#include <cmath>
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value <= 1) return false;
    if (value == 2) return true;
    if (value % 2 == 0) return false;

    uint64_t sqrtVal = static_cast<uint64_t>(std::sqrt(value)) + 1;
    for (uint64_t i = 3; i < sqrtVal; i += 2) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}


uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0;

    uint64_t count = 0;
    uint64_t num = 2;

    while (count < n) {
        if (checkPrime(num)) {
            count++;
            if (count == n) {
                return num;
            }
        }
        num++;
    }
    return 0; 
}


uint64_t nextPrime(uint64_t value) {
    uint64_t num = value + 1;
    while (true) {
        if (checkPrime(num)) {
            return num;
        }
        num++;
    }
}


uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}


uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;
    uint64_t prevPrime = 0;

    for (uint64_t i = lbound; i < hbound; ++i) {
        if (checkPrime(i)) {
            if (i - prevPrime == 2) {
                count++;
            }
            prevPrime = i;
        }
    }
    return count;
}
