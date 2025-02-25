// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
 if (value < 2) return false;
    if (value == 2) return true;
    if (value % 2 == 0) return false;
    for (uint64_t i = 3; i * i <= value; i += 2) {
        if (value % i == 0) return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;
    uint64_t num = 2;

    while (count < n) {
        bool isPrime = true;

        if (num < 2) isPrime = false;
        else if (num == 2) isPrime = true;
        else if (num % 2 == 0) isPrime = false;
        else {
            for (uint64_t i = 3; i * i <= num; i += 2) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime) {
            count++;
        }
        num++;
    }
    return num - 1;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t num = value + 1;

    while (true) {
        bool isPrime = true;

        if (num < 2) isPrime = false;
        else if (num == 2) isPrime = true;
        else if (num % 2 == 0) isPrime = false;
        else {
            for (uint64_t i = 3; i * i <= num; i += 2) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime) {
            return num;
        }
        num++;
    }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;

    for (uint64_t i = 2; i < hbound; i++) {
        bool isPrime = true;

        if (i < 2) isPrime = false;
        else if (i == 2) isPrime = true;
        else if (i % 2 == 0) isPrime = false;
        else {
            for (uint64_t j = 3; j * j <= i; j += 2) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime) {
            sum += i;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t pairs = 0;
    uint64_t prevPrime = 0;

    for (uint64_t i = lbound; i < hbound; i++) {
        bool isPrime = true;

        if (i < 2) isPrime = false;
        else if (i == 2) isPrime = true;
        else if (i % 2 == 0) isPrime = false;
        else {
            for (uint64_t j = 3; j * j <= i; j += 2) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime) {
            if (i - prevPrime == 2) {
                pairs++;
            }
            prevPrime = i;
        }
    }
    return pairs;
}
