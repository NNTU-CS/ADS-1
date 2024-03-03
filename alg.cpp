
#include <iostream>
#include <vector>

bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    for (uint64_t i = 2; i * i <= value; ++i) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 1) {
        return 2;
    }

    uint64_t count = 1;
    uint64_t num = 3;

    while (count < n) {
        if (checkPrime(num)) {
            ++count;
        }
        if (count < n) {
            num += 2;
        }
    }

    return num;
}

uint64_t nextPrime(uint64_t value) {
    if (value < 2) {
        return 2;
    }

    uint64_t num = value + 1;
    while (!checkPrime(num)) {
        ++num;
    }

    return num;
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

std::vector<uint64_t> restorePrimes(uint64_t hbound) {
    std::vector<uint64_t> primes;

    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            primes.push_back(i);
        }
    }

    return primes;
}
