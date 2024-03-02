// Copyright 2022 NNTU-CS
#ifndef INCLUDE_ALG_H_
#define INCLUDE_ALG_H_
#include <cstdint>

bool checkPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    for (uint64_t i = 2; i * i <= value; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t cur_num = 1;
    uint64_t count = 0;
    while (count < n) {
        cur_num++;
        if (checkPrime(cur_num)) {
            count++;
        }
    }
    return cur_num;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t check_value = value + 1;
    while (checkPrime(check_value) != true) {
        check_value++;
    }
    return check_value;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (int i = 2; i < hbound; i++) {
        if (checkPrime(i) == true) {
            sum += i;
        }
    }
    return sum;
}


#endif // INCLUDE_ALG_H_
