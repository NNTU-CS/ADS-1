// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>
#include <cmath>


bool checkPrime(uint64_t value) {
    for (uint64_t a = 2; a <= sqrt(value); a++) {
        if (value % a == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t count = 0;
    uint64_t number = 2;
    
    while (count < n) {
        if (checkPrime(number)) {
            count++;
        }
        number++;
    }
    
    return number - 1;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t next_prime = value + 1;
    while (true) {
        if (checkPrime(next_prime)) {
            return next_prime;
        }
        next_prime++;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t summ = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            summ += i;
        }
    }
    return summ;
}
