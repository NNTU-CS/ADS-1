// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    for (int i = 2; i < (value/2)+1; i++) {
    if (value % i == 0)
    return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int c = 0;
    for (int i = 2; ; i++) {
        if (c != n) {
            bool flag = true;
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                c++;
            }
        } else {
            return i-1;
        }
    }

    return 2;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t n = value + 1;
    for (uint64_t i = n; ; i++) {
        bool flag = true;
        for (int j = 2; j <= (i / 2)+1; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            return i;
        }
    }
    return 2;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        bool flag = true;
        for (uint64_t j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            sum+=i;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    int c = 0;
    for (uint64_t i = lbound; i+2 < hbound; i++) {
        bool flag = true;
        for (int j = 2; j <= (i / 2)+1; j++) {
            if (i % j == 0 || (i + 2) % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            c++;
        }
    }
    return c;
}
