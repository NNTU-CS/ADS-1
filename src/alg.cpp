// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cmath>

bool checkPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    for (uint64_t i = 2; i <= pow(value, 0.5); i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 1) {
        return 2;
    }
    uint64_t count_value = 1;
    uint64_t number_value = 3;
    while (count_value < n) {
        if (checkPrime(number_value)) {
            count_value++;
        }
        if (count_value < n) {
            number_value = number_value + 2;
        }
    }
    return number_value;
}

uint64_t nextPrime(uint64_t value) {
    if (value <= 1) {
        return 2;
    }
    uint64_t following = value + 1;
    while (!(checkPrime(following))) {
        following++;
    }
    return following;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t summa = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            summa += i;
        }
    }
    return summa;
}
