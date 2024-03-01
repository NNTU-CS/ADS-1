// Copyright 2022 NNTU-CS
#include "alg.h"
#include <valarray>

bool checkPrime(uint64_t value) {
    if ((value < 2) || ((value % 2 == 0) && (value > 2))) {
        return false;
    }
    for (uint64_t i = 3; i <= sqrt(value); i += 2) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int count = 1;
    int number_now = 2;
    for (int i = 3; count < n; i += 2) {
        if (checkPrime(i)) {
            count++;
            number_now = i;
        }
    }
    return number_now;
}


uint64_t nextPrime(uint64_t value) {
    value++;
    while (!checkPrime(value)) {
        value++;
    }
    return value;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t number = 2;
    uint64_t summ = 0;
    while (number < hbound) {
        if (checkPrime(number)) {
            summ += number;
        }
        number++;
    }
    return summ;
}

