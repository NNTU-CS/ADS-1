// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value == 2 || value == 3) {
        return true;
    }
    uint64_t counter = 0;
    for (uint64_t i = 2; i <= (value / 2); i++) {
        if (value % i == 0) {
            counter++;
        }
    }
    if (counter == 0 && value != 1) {
        return true;
    } else {
        return false;
    }
}

uint64_t nPrime(uint64_t n) {
    uint64_t count = 0;
    uint64_t i = 1;
    uint64_t number;
    while (count != n) {
        bool res =  checkPrime(i);
        if (res) {
            count++;
            number = i;
            i++;
        } else {
            i++;
            continue;
        }
    }
    return number;
}

uint64_t nextPrime(uint64_t value) {
    value++;
    while (true) {
        bool test = checkPrime(value);
        if (test) {
            return value;
        } else {
            value++;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 0; i < hbound; i++) {
        if (checkPrime(i)) {
            sum += i;
        } else {
            continue;
        }
    }
    return sum;
}
