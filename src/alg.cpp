// Copyright 2022 NNTU-CS
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }

    for (uint64_t i = 2; i * i <= value; i++) {
        if (value % i == 0) {
            return false;
        }
    }

    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t count = 0;
    uint64_t chislo = 2;
    while (count < n) {
        if (checkPrime(chislo)) {
            count++;
        }
        chislo++;
    }
    return chislo - 1;
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
    uint64_t summa = 0;
    while (number < hbound) {
        if (checkPrime(number)) {
            summa = summa + number;
        }
        number++;
    }
    return summa;
}
