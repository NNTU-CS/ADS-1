// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    for (uint64_t i = 2; i < value; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t size = 0;
    uint64_t prost_arr[1000] = { 0 };
    for (int number = 2; size < 1000; number++) {
        if (checkPrime(number)) {
            prost_arr[size] = number;
            size++;
        }
    }
    return prost_arr[n-1];
}

uint64_t nextPrime(uint64_t value) {
    value++;
    while (checkPrime(value) == false) {
        value++;
    }
    return value;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (int number = 2; number < hbound; number++) {
        if (checkPrime(number)) {
            sum += number;
        }
    }
    return sum;
}
