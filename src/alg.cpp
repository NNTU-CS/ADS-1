// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
    int count = 0;
    for (int i = 1; i <= value / 2; i++) {
       if (value % i == 0) count++;
    }
    if (count == 1) {
        return true;
    } else {
        return false;
    }
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
    int flag = 0;
    for (uint64_t j = 2; ; j++) {
        int count = 0;
        for (int i = 1; i <= j / 2; i++) {
            if (j % i == 0) count++;
        }
        if (count == 1) flag++;
        if (flag == n) return j;
    }
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
    for (uint64_t j = value+1; ; j++) {
        int count = 0;
        for (int i = 1; i <= j / 2; i++) {
            if (j % i == 0) count++;
        }
        if (count == 1) return j;
    }
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
    uint64_t sum = 0;
    for (uint64_t j = 2; j < hbound; j++) {
        int count = 0;
        for (int i = 2; i <= j / 2; i++) {
            if (j % i == 0) {
                count++;
                break;
            }
        }
        if (count == 0) sum += j;
    }
    return sum;
}
