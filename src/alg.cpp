// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if(value <= 1){
        return false;
    }
    for(int i = 2;i*i<=value;i++){
        if(value%i==0){
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
uint64_t chesl = 2,cont = 1;
    while(cont<n){
        chesl+=1;
    if(checkPrime(chesl)){
        cont+=1;
        }
    }
    return chesl;

}

uint64_t nextPrime(uint64_t value) {
    value += 1;
    while (!checkPrime(value)) {
        value += 1;
    }
    return value;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i ++) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
