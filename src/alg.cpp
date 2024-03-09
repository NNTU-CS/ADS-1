// Copyright 2022 NNTU-CS
#include <cstdint>
#include <vector>
#include <cmath>
bool checkPrime(uint64_t value) {
    if (value <= 1) return false;
    if (value <= 3) return true;
    if (value % 2 == 0 || value % 3 == 0) return false;
    for (uint64_t i = 5; i * i <= value; i += 6) {
        if (value % i == 0 || value % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
uint64_t nPrime(uint64_t n) {
    if (n == 1) return 2;
    if (n == 2) return 3;
    uint64_t count = 2;
    uint64_t candidate = 5;
    while (true) {
        if (checkPrime(candidate)) {
            count++;
            if (count == n) return candidate;
        }
        candidate += 2;
    }
}
uint64_t nextPrime(uint64_t value) {
    if (value <= 1) return 2;
    uint64_t candidate = value + 1;
    while (true) {
        if (checkPrime(candidate)) {
            return candidate;
        }
        candidate++;
    }
}
uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
