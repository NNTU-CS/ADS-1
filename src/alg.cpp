// Copyright 2022 NNTU-CS
#include <cstdint>



bool checkPrime(uint64_t value) {
    for (int i = 2; i <= (value/2); i++) {
        if (value == 2)
            return true;
        if ((value % i) == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int count = 0;
    for (int i = 2; i <= 10000; i++) {
        if (checkPrime(i) == true)
            ++count;
        if (count == n)
            return i;
    }
    return 0;
}

uint64_t nextPrime(uint64_t value) {
    for (++value; value <= 10000000; value++) {
        if (checkPrime(value) == true)
            return value;
    }
    return 0;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i) == true)
            sum += i;
    }
    return sum;
}

