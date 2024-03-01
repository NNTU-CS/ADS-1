// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
    if (value < 2)
        return false;
    for (uint64_t k = 2; k*k <= value; k++) {
        if (value % k == 0)
            return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
    uint64_t num = 2;
    uint64_t counter = 0;
    while (counter < n) {
        if (checkPrime(num))
            counter++;
        num++;
    }
    return num-1;
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
    if (value < 2)
        return 2;
    value++;
    while (!checkPrime(value))
        value++;
    return value;
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
    uint64_t summ = 0;
    for (uint64_t k = 2; k < hbound; k++) {
        if (checkPrime(k))
            summ += k;
    }
    return summ;
}
