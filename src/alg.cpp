// Copyright 2022 NNTU-CS

#include "alg.h"
#include "cmath"

bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(value); i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int counter = 1;
    int result;

    while (counter <= n){
        for (int i = 2; i<=1000000000; i++) {
            if (checkPrime(i)) {
                counter++;
                result = i;
                if (counter>n) {
                    break;
                }
            }
        }
    }
    return n;
}

uint64_t nextPrime(uint64_t value) {
    int counter = 0;
    int result;

    while (counter <= value){
        for (int i = 2; i<=1000000000; i++) {
            if (checkPrime(i)) {
                counter++;
                result = i;
                if (counter>value) {
                    break;
                }
            }
        }
    }
    return value;
}

uint64_t sumPrime(uint64_t hbound) {
    int summa = 0;
    for (int i = 2; i <= hbound; i++) {
        if (checkPrime(i)) {
            summa += i;
        }
    }
    return summa;
}
