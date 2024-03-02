// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) 
{
    for (int i = 2; i < sqrt(value) + 1; i ++){
        if (value % i == 0){
            return false;
        }
    }
    return true;    
}

uint64_t nPrime(uint64_t n) {
    int count = 0;
    int i = 0;
    while (count != n){
        if (checkPrime(i)){
            count ++;
        }
        i++;
    }
    return i;
}

uint64_t nextPrime(uint64_t value) {
    int i = value + 1;
    while (!checkPrime(i))
    {
        i++;
    }
    return i;
}

uint64_t sumPrime(uint64_t hbound)
{
    int i = 0;
    int res = 0;
    while (i<hbound){
        if (checkPrime(i)){
            res+=i;
        }
        i++;
    }
    return res;
}
