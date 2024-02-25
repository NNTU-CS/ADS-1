// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
    if (value <= 1)
        return true;
    for (uint32_t i = 2; i < value; i++)
        if (value % i == 0)
            return false;
return true;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
    uint32_t order = 0;
    uint64_t number = 2;
    while (order < n) {
        if (checkPrime(number)) {
            order++;
        if (order == n)
            return number;
        }
    number++;
}
return number;
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
    uint64_t number = value;
    while (true) {
        number++;
        if (checkPrime(number))
            return number;
}
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
    uint64_t sum = 0;
    for (auto i = 2; i < hbound; i++) {
        if (checkPrime(i))
            sum += i;
}
return sum;
}
