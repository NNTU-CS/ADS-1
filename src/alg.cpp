// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cmath>


bool checkPrime(uint64_t value) {
    bool flag = true;
    double sqNum = sqrt(static_cast<double>(value));
    for (int i = 2; i <= sqNum; i++) {
        if (value % i == 0) {
            flag = false;
        }
    }
    return flag;
}

uint64_t nPrime(uint64_t n) {
    int num = 2;
    double maxNum = pow(2, 64);
    for (int i = 1; i < n; i++) {
        for (int j = num+1; j < maxNum; j++) {
            if (checkPrime(j)) {
                num = j;
                break;
            }
        }
    }
    return num;
}

uint64_t nextPrime(uint64_t value) {
    int result = 0;
    double maxNum = pow(2, 64);
    for (uint16_t i = value + 1; i < maxNum; i++) {
        if (checkPrime(i)) {
            result = i;
            break;
        }
    }
    return result;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t summa = 0;
    for (int i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            summa += i;
        }
    }
    return summa;
}
