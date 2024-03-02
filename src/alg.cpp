// Copyright 2022 NNTU-CS
#include <cmath>
#include <cstdint>
using namespace std;
bool checkPrime(uint64_t value){
    for( uint64_t i = 2; i <= sqrt(value); i++){
        if (value % i == 0)
            return false;
    }
    return true;
}
uint64_t nPrime(uint64_t n) {
    int count = 0;
    int value = 2;

    while(count < n) {
        if(checkPrime(value)) {
            count++;
        }
        value++;
    }
    return value - 1;
    }
    uint64_t nextPrime(uint64_t value) {
    while (true) {
        if (checkPrime(value)) return value;
        value++;
    }
}

uint64_t sumPrime(uint64_t hbound) {
int s = 0;
    for (int i = 1; i <= hbound; i++) {
        s += i;
    }
    return s;
}

