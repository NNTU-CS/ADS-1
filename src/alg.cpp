// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    int flag = 0;
    for (int i = 2; i < value; i++) {
        if (value % i == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        return false;
    else
        return true;
}

uint64_t nPrime(uint64_t n) {
    int cnt = 0;
    int flag = 0;
    for (int i = 2; i < 100000; ++i) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cnt += 1;
            if (cnt == n)
                return i;
        }
        else
          flag = 0;
    }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
    int a = value + 1;
    while (1) {
        if (checkPrime(a)) {
            return a;
        }
        a++;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    int sum = 0;
    for (int i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
