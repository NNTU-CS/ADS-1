// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value){
    if (value <= 1)
        return false;

    for (int i = 2; i * i < value + 1; i++)
    {
        if (value % i == 0)
            return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n){
    int num = 0;
    for (int i = 0; i < n; i++)
        num = nextPrime(num);

    return num;
}

uint64_t nextPrime(uint64_t value){
    int i = value + 1;
    for (int i = value + 1;; i++)
        if (checkPrime(i))
            return i;
}

uint64_t sumPrime(uint64_t hbound){
    uint64_t res = 0;
    for (uint64_t i = nextPrime(0); i < hbound; i = nextPrime(i))
        res += i;

    return res;
}
